#include <bits/stdc++.h>
using namespace std;
struct Player {
    string st;
    int hp = 4;
    bool stat = true;
    vector<string> hand;
    bool hasZ = false;
    int rev = -1;
    int last_d = -1;
};
int n, m;
vector<Player> P;
vector<string> deck;
int d_pos = 0;
vector<char> typc = {'P', 'K', 'D', 'F', 'N', 'W', 'J', 'Z'};
string d_ocd() {
    if (deck.empty()) 
        return "";
    if (d_pos < (int)deck.size())
        return deck[d_pos++];
    return deck.back();
}
void d_cd(int pid, int cnt) {
    for (int i = 0; i < cnt; ++i) {
        string c = d_ocd();
        if (!c.empty())
            P[pid].hand.push_back(c);
    }
}
int next_idx(int idx) {
    return (idx + 1) % n;
}
bool ex_alv(int pid) {
    for (int i = 0; i < n; ++i)
        if (i != pid && P[i].stat)
            return true;
    return false;
}
int nxt_alv(int idx) {
    int cur = (idx + 1) % n;
    while (!P[cur].stat)
        cur = (cur + 1) % n;
    return cur;
}
int alv_cnt() {
    int c = 0;
    for (int i = 0; i < n; ++i) 
        if (P[i].stat)
            ++c;
    return c;
}
int idx_of_lve_tp(int pid, char t) {
    for (int i = 0; i < (int)P[pid].hand.size(); ++i)
        if (!P[pid].hand[i].empty() && P[pid].hand[i][0] == t)
            return i;
    return -1;
}
bool remv_LFt(int pid, char t) {
    int idx = idx_of_lve_tp(pid, t);
    if (idx == -1)
        return false;
    P[pid].hand.erase(P[pid].hand.begin() + idx);
    return true;
}
bool c_tp(int pid, char t) {
    return idx_of_lve_tp(pid, t) != -1;
}
vector<bool> cls_rebel;
void try_toAC(int aa, const string &acc, int tg) {
    if (aa == 0) return;
    if (P[aa].rev != -1) return;
    if (P[aa].st == "ZP") {
        if (acc == "favor") {
            if (tg == 0 || P[tg].rev == 0)
                P[aa].rev = 0;
        }
        else if (acc == "hostile") {
            if (P[tg].rev == 1)
                P[aa].rev = 0;
        }
    }
    else if (P[aa].st == "FP") {
        if (acc == "hostile") {
            if (tg == 0 || P[tg].rev == 0)
                P[aa].rev = 1;
        }
        else if (acc == "favor") {
            if (P[tg].rev == 1)
                P[aa].rev = 1;
        }
    }
    if (P[aa].rev == 0) cls_rebel[aa] = false;
}
int fst_CW(int st, function<bool(int)> pred) { // Java&C++混合体（C++刚支持的新特心）
    int cur = (st + 1) % n;
    while (cur != st) {
        if (P[cur].stat && pred(cur)) return cur;
        cur = (cur + 1) % n;
    }
    return -1;
}
int neib(int a) {
    int cur = (a + 1) % n;
    while (!P[cur].stat)
        cur = (cur + 1) % n;
    return cur;
}
int fnd_TF(int at_to) {
    int nb = neib(at_to);
    if (nb == at_to) return -1;
    string st = P[at_to].st;
    if (st == "MP") {
        if (cls_rebel[nb] || P[nb].rev == 1) return nb;
        return -1;
    }
    else if (st == "ZP") {
        if (P[nb].rev == 1) return nb;
        return -1;
    }
    else {
        if (nb == 0) return nb;
        if (P[nb].rev == 0) return nb;
        return -1;
    }
}
int fnd_G(int atck_r) {
    string st = P[atck_r].st;
    if (st == "MP") {
        int t = fst_CW(atck_r, [&](int x){ return cls_rebel[x] || P[x].rev == 1; }); // 懒得写好几个函数了，下同
        return t;
    }
    else if (st == "ZP") {
        int t = fst_CW(atck_r, [&](int x){ return P[x].rev == 1; });
        return t;
    }
    else {
        if (P[0].stat) return 0;
        int t = fst_CW(atck_r, [&](int x){ return P[x].rev == 0; });
        return t;
    }
}
bool wo_F(int act, int tar) {
    if (!P[act].stat) return false;
    if (act == 0 && tar == 0) return true;
    if (P[tar].rev == -1) return false;
    if (P[act].st == "MP") return (tar == 0) || (P[tar].rev == 0);
    if (P[act].st == "ZP") return (tar == 0) || (P[tar].rev == 0);
    if (P[act].st == "FP") return (P[tar].rev == 1);
    return false;
}
bool wo_Hs(int act, int tar) {
    if (!P[act].stat) return false;
    int fF = fnd_G(act);
    int fK = fnd_TF(act);
    return (fF == tar) || (fK == tar);
}
bool resolveJChain(int fr, int tar) {
    int j_cnt = 0;
    bool flag;
    do {
        flag = false;
        for (int j = 0; j < n; ++j) {
            int i = (fr + j) % n;
            if (!P[i].stat) continue;
            int idx = idx_of_lve_tp(i, 'J');
            if (idx == -1) continue;
            bool FF_e = (j_cnt % 2 == 0);
            bool will = false;
            if (FF_e) {
                will = wo_F(i, tar);
            }
            else {
                will = wo_Hs(i, tar);
            }
            if (will) {
                P[i].hand.erase(P[i].hand.begin() + idx);
                ++j_cnt;
                if (FF_e)
                    try_toAC(i, "favor", tar);
                else try_toAC(i, "hostile", tar);
                flag = true;
            }
        }
    } while (flag);
    return (j_cnt % 2 == 1);
}
bool gend = false;
string win_who = "";
void ck_vec() {
    if (!P[0].stat) {
        gend = true;
        win_who = "FP";
        return;
    }
    bool anyFP = false;
    for (int i = 0; i < n; ++i) 
        if (P[i].stat && P[i].st == "FP") {
            anyFP = true;
            break;
        }
    if (!anyFP) {
        gend = true;
        win_who = "MP";
    }
}
void hld_sec(int deder) {
    P[deder].hand.clear();
    P[deder].hasZ = false;
    ck_vec();
    if (gend) return;
    if (P[deder].st == "FP") {
        int src = P[deder].last_d;
        if (src != -1 && P[src].stat) d_cd(src, 3);
    } else if (P[deder].st == "ZP") {
        int src = P[deder].last_d;
        if (src == 0) {
            P[0].hand.clear();
            P[0].hasZ = false;
        }
    }
    ck_vec();
}
void dg_t(int tar, int dmg, int src) {
    if (!P[tar].stat) return;
    P[tar].hp -= dmg;
    P[tar].last_d = src;
    if (tar == 0 && (dmg > 0) && src != -1) {
        // [test????]
    }
    while (P[tar].hp <= 0 && P[tar].stat) {
        int idxp = idx_of_lve_tp(tar, 'P');
        if (idxp != -1) {
            P[tar].hand.erase(P[tar].hand.begin() + idxp);
            P[tar].hp = 1;
        } else {
            // die
            P[tar].stat = false;
            hld_sec(tar);
            break;
        }
    }
}
void k_pl(int act) {
    int tid = fnd_TF(act);
    if (tid == -1) return;
    try_toAC(act, "hostile", tid);
    int idxd = idx_of_lve_tp(tid, 'D');
    if (idxd != -1) {
        P[tid].hand.erase(P[tid].hand.begin() + idxd);
    }
    else {
        dg_t(tid, 1, act);
    }
}
void p_d(int act) {
    int tid = fnd_G(act);
    if (tid == -1) return;
    try_toAC(act, "hostile", tid);
    bool neg = resolveJChain(act, tid);
    if (neg) return;
    int cur = tid, opp = act;
    while (P[cur].stat && P[opp].stat) {
        int idxk = idx_of_lve_tp(cur, 'K');
        bool flg = false;
        if (idxk != -1) {
            if (P[cur].st == "MP") flg = true;
            else if (P[cur].st == "FP") flg = true;
            else {
                if (opp == 0) flg = false;
                else flg = true;
            }
        }
        if (flg) {
            P[cur].hand.erase(P[cur].hand.begin() + idxk);
        }
        else {
            dg_t(cur, 1, opp);
            break;
        }
        swap(cur, opp);
    }
}
void playNW(int act, char type) {
    int cur = next_idx(act);
    for (int count = 1; count < n; ++count) {
        if (!P[cur].stat) {
            cur = next_idx(cur);
            continue;
        }
        bool neg = resolveJChain(act, cur);
        if (!neg) {
            if (type == 'N') {
                int idxk = idx_of_lve_tp(cur, 'K');
                if (idxk != -1) {
                    P[cur].hand.erase(P[cur].hand.begin() + idxk);
                }
                else {
                    dg_t(cur, 1, act);
                    if (cur == 0 && P[act].rev == -1) cls_rebel[act] = true;
                }
            }
            else {
                int idxd = idx_of_lve_tp(cur, 'D');
                if (idxd != -1) {
                    P[cur].hand.erase(P[cur].hand.begin() + idxd);
                } else {
                    dg_t(cur, 1, act);
                    if (cur == 0 && P[act].rev == -1) cls_rebel[act] = true;
                }
            }
        }
        if (gend) return;
        cur = next_idx(cur);
    }
}
void pl_p(int pid) {
    int cnt_k = 0;
    while (true) {
        int su_idx = -1;
        string mpc;
        for (int i = 0; i < (int)P[pid].hand.size(); ++i) {
            string c = P[pid].hand[i];
            if (c.empty()) continue;
            char t = c[0];
            if (t == 'P') {
                if (P[pid].hp < 4) {
                    su_idx = i;
                    mpc = c;
                    break;
                }
                else continue;
            }
            else if (t == 'K') {
                int lmt = P[pid].hasZ ? 1000000 : 1;
                if (cnt_k < lmt) {
                    if (fnd_TF(pid) != -1) {
                        su_idx = i; 
                        mpc = c;
                        break;
                    }
                } else continue;
            } 
            else if (t == 'F') {
                if (fnd_G(pid) != -1) {
                    su_idx = i;
                    mpc = c;
                    break;
                }
            } 
            else if (t == 'N' || t == 'W') {
                if (ex_alv(pid)) {
                    su_idx = i;
                    mpc = c;
                    break;
                }
            } 
            else if (t == 'Z') {
                su_idx = i;
                mpc = c; break;
            } 
            else {
                continue;
            }
        }
        if (su_idx == -1) break;
        char t = mpc[0];
        P[pid].hand.erase(P[pid].hand.begin() + su_idx);
        if (t == 'Z') {
            P[pid].hasZ = true;
        } else if (t == 'P') {
            P[pid].hp = min(4, P[pid].hp + 1);
        } else if (t == 'K') {
            ++cnt_k;
            k_pl(pid);
            if (gend) return;
        } else if (t == 'F') {
            p_d(pid);
            if (gend) return;
        } else if (t == 'N' || t == 'W') {
            playNW(pid, t);
            if (gend) return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    P.assign(n, Player()); // 构造函数
    cls_rebel.assign(n, false);
    for (int i = 0; i < n; ++i) {
        string st;
        cin >> st;
        P[i].st = st;
        P[i].hp = 4;
        P[i].stat = true;
        P[i].hand.clear();
        P[i].hasZ = false;
        if (i == 0) P[i].rev = 0; else P[i].rev = -1;
        for (int k = 0; k < 4; ++k) {
            string c;
            cin >> c;
            P[i].hand.push_back(c);
        }
    }
    deck.clear();
    for (int i = 0; i < m; ++i) {
        string c; cin >> c; deck.push_back(c);
    }
    d_pos = 0;
    int cur = 0;
    while (!gend) {
        if (P[cur].stat) {
            d_cd(cur, 2);
            pl_p(cur);
            if (gend) break;
        }
        cur = (cur + 1) % n;
    }
    cout << win_who << "\n";
    for (int i = 0; i < n; ++i) {
        if (!P[i].stat) {
            cout << "DEAD\n";
        } else {
            if (P[i].hand.empty()) {
                cout << "\n";
            } else {
                for (int j = 0; j < (int)P[i].hand.size(); ++j) {
                    if (j) cout << " ";
                    cout << P[i].hand[j];
                }
                cout << "\n";
            }
        }
    }
    return 0;
}