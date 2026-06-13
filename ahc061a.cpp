#include <bits/stdc++.h>
using namespace std;
const int DX[] = {-1, 1, 0, 0};
const int DY[] = {0, 0, -1, 1};
const int b_sz = 10;
const int tt_turn = 100;
enum GamePhase {
    EARLY_GAME,
    MID_GAME,
    LATE_GAME
};
struct WeightConfig {
    double empty_w;
    double reinforce_w;
    double tar_ai_w;
    double other_ai_w;
    double cwg;
    double pre_w;
};
long long cc_gsc(int pid, const vector<vector<int>>& V, 
                            const vector<vector<int>>& owner, const vector<vector<int>>& ll) {
    long long tong = 0;
    for (int i = 0; i < b_sz; ++i) {
        for (int j = 0; j < b_sz; ++j) {
            if (owner[i][j] == pid) {
                tong += (long long)V[i][j] * ll[i][j];
            }
        }
    }
    return tong;
}
GamePhase gg_gturn(int turn) {
    if (turn <= 30) return EARLY_GAME;
    else if (turn <= 70) return MID_GAME;
    else return LATE_GAME;
}
void calc_rett(const vector<vector<int>>& owner, int sx, int sy, 
                               vector<vector<bool>>& rec) {
    fill(rec.begin(), rec.end(), vector<bool>(b_sz, false));
    queue<pair<int, int>> q;
    q.push({sx, sy});
    rec[sx][sy] = true;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int d = 0; d < 4; ++d) {
            int nx = x + DX[d];
            int ny = y + DY[d];
            if (nx >= 0 && nx < b_sz && ny >= 0 && ny < b_sz 
                && !rec[nx][ny] && owner[nx][ny] == 0) {
                rec[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}
int calc_cgg(int x, int y, const vector<vector<bool>>& rec, 
                           const vector<vector<int>>& owner, const vector<vector<int>>& ll) {
    int g = 0;
    for (int d = 0; d < 4; ++d) {
        int nx = x + DX[d];
        int ny = y + DY[d];
        if (nx < 0 || nx >= b_sz || ny < 0 || ny >= b_sz) continue;
        if (!rec[nx][ny]) {
            if (owner[nx][ny] == -1) g += 2;
            else if (owner[nx][ny] != 0 && ll[nx][ny] == 1) g += 1;
        }
    }
    return g;
}
set<pair<int, int>> get_ai_ttp(const vector<vector<int>>& V, 
                                              const vector<vector<int>>& owner, int top_k = 3) {
    vector<pair<int, pair<int, int>>> emp_C;
    for (int i = 0; i < b_sz; ++i) {
        for (int j = 0; j < b_sz; ++j) {
            if (owner[i][j] == -1) {
                emp_C.emplace_back(V[i][j], make_pair(i, j));
            }
        }
    }
    sort(emp_C.rbegin(), emp_C.rend());
    set<pair<int, int>> tars;
    for (int i = 0; i < min(top_k, (int)emp_C.size()); ++i) {
        tars.insert(emp_C[i].second);
    }
    return tars;
}
WeightConfig get_pw(GamePhase phase) {
    WeightConfig cfg;
    switch (phase) {
        case EARLY_GAME:
            cfg.empty_w = 1.5;
            cfg.reinforce_w = 0.6;
            cfg.tar_ai_w = 0.8;
            cfg.other_ai_w = 0.4;
            cfg.cwg = 0.4;
            cfg.pre_w = 1.2;
            break;
        case MID_GAME:
            cfg.empty_w = 1.0;
            cfg.reinforce_w = 0.9;
            cfg.tar_ai_w = 1.4;
            cfg.other_ai_w = 0.6;
            cfg.cwg = 0.3;
            cfg.pre_w = 0.8;
            break;
        case LATE_GAME:
            cfg.empty_w = 0.4;
            cfg.reinforce_w = 1.6;
            cfg.tar_ai_w = 1.8;
            cfg.other_ai_w = 0.3;
            cfg.cwg = 0.2;
            cfg.pre_w = 0.4;
            break;
    }
    return cfg;
}
double cc_gscdd(
    int x, int y, int V_val, int ow_id, int ll_val, int ll_upper,
    int tar_ai_id, long long max_ai_score, long long mine,
    int ccg, bool is_ai_top_tar, const WeightConfig& cfg
) {
    double sb_cc = 0.0;
    if (ow_id == 0) {
        if (ll_val < ll_upper) {
            sb_cc = V_val * cfg.reinforce_w;
            if (ll_val < ll_upper - 1) sb_cc *= 1.2;
        } else {
            return 0.0;
        }
    }
    else if (ow_id == -1) {
        sb_cc = V_val * cfg.empty_w;
        if (is_ai_top_tar) sb_cc *= cfg.pre_w;
    }
    else {
        double at_w = (ow_id == tar_ai_id) ? cfg.tar_ai_w : cfg.other_ai_w;
        if (ll_val == 1) {
            sb_cc = V_val * at_w * 1.5;
            if (ow_id == tar_ai_id) {
                double rat_b = 1.0 + (double)V_val * ll_val / max_ai_score;
                sb_cc *= rat_b;
            }
        } else if (ll_val == 2) {
            sb_cc = V_val * at_w * 0.5;
        } else {
            sb_cc = V_val * at_w * 0.1;
        }
    }
    sb_cc += ccg * cfg.cwg * 100;
    return sb_cc;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int N, M, T, U;
    cin >> N >> M >> T >> U;
    vector<vector<int> > V(b_sz, vector<int>(b_sz));
    for (int i = 0; i < b_sz; ++i) {
        for (int j = 0; j < b_sz; ++j) {
            cin >> V[i][j];
        }
    }
    vector<int> px(M), py(M);
    vector<vector<int>> owner(b_sz, vector<int>(b_sz, -1));
    vector<vector<int>> ll(b_sz, vector<int>(b_sz, 0));
    for (int p = 0; p < M; ++p) {
        cin >> px[p] >> py[p];
        owner[px[p]][py[p]] = p;
        ll[px[p]][py[p]] = 1;
    }
    int turn_ = 0;
    while (T--) {
        turn_++;
        GamePhase phase = gg_gturn(turn_);
        WeightConfig cfg = get_pw(phase);
        vector<vector<bool>> rec(b_sz, vector<bool>(b_sz, false));
        calc_rett(owner, px[0], py[0], rec);
        vector<pair<int, int>> acd;
        for (int i = 0; i < b_sz; ++i) {
            for (int j = 0; j < b_sz; ++j) {
                if (rec[i][j]) {
                    acd.emplace_back(i, j);
                }
            }
        }
        set<pair<int, int>> adj_c;
        for (int i = 0; i < b_sz; ++i) {
            for (int j = 0; j < b_sz; ++j) {
                if (rec[i][j]) {
                    for (int d = 0; d < 4; ++d) {
                        int nx = i + DX[d];
                        int ny = j + DY[d];
                        if (nx >= 0 && nx < b_sz && ny >= 0 && ny < b_sz) {
                            adj_c.insert({nx, ny});
                        }
                    }
                }
            }
        }
        for (auto& p : adj_c) {
            acd.push_back(p);
        }
        set<pair<int, int>> o_pospp;
        for (int p = 1; p < M; ++p) {
            o_pospp.insert({px[p], py[p]});
        }
        vector<pair<int, int>> v_cc;
        for (auto& p : acd) {
            if (o_pospp.find(p) == o_pospp.end()) {
                v_cc.push_back(p);
            }
        }
        vector<long long> ai_ss(M, 0);
        long long ai_maxx = 0;
        int tar_ai_id = 1;
        long long my_score = cc_gsc(0, V, owner, ll);
        for (int p = 1; p < M; ++p) {
            ai_ss[p] = cc_gsc(p, V, owner, ll);
            if (ai_ss[p] > ai_maxx) {
                ai_maxx = ai_ss[p];
                tar_ai_id = p;
            }
        }
        auto ai_top_tars = get_ai_ttp(V, owner);
        double maxx = -1e18;
        pair<int, int> bs_m = {px[0], py[0]};
        for (auto& p : v_cc) {
            int x = p.first;
            int y = p.second;
            int V_val = V[x][y];
            int o_id = owner[x][y];
            int l_val = ll[x][y];
            int conn_gain = calc_cgg(x, y, rec, owner, ll);
            bool is_ai_tar = (ai_top_tars.find(p) != ai_top_tars.end());

            double sc = cc_gscdd(
                x, y, V_val, o_id, l_val, U,
                tar_ai_id, ai_maxx, my_score,
                conn_gain, is_ai_tar, cfg
            );
            if (abs(sc - maxx) < 1e-6) {
                if (rand() % 2 == 0) {
                    bs_m = p;
                }
            } else if (sc > maxx) {
                maxx = sc;
                bs_m = p;
            }
        }
        cout << bs_m.first << " " << bs_m.second << "\n";
        cout.flush();
        int tx, ty;
        for (int p = 0; p < M; ++p) {
            cin >> tx >> ty;
        }
        for (int p = 0; p < M; ++p) {
            cin >> px[p] >> py[p];
        }
        for (int i = 0; i < b_sz; ++i) {
            for (int j = 0; j < b_sz; ++j) {
                cin >> owner[i][j];
            }
        }
        for (int i = 0; i < b_sz; ++i) {
            for (int j = 0; j < b_sz; ++j) {
                cin >> ll[i][j];
            }
        }
    }

    return 0;
}