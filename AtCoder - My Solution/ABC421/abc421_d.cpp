#include <bits/stdc++.h>
using namespace std;
struct mv {
    char dir;
    long long st;
};
int main() {
    long long Rt, Ct, Ra, Ca, N;
    int M, L;
    cin >> Rt >> Ct >> Ra >> Ca >> N >> M >> L;
    vector<mv> S, t;
    for (int i = 0; i < M; ++i) {
        char dir;
        long long st;
        cin >> dir >> st;
        S.push_back({dir, st});
    }
    for (int i = 0; i < L; ++i) {
        char dir;
        long long st;
        cin >> dir >> st;
        t.push_back({dir, st});
    }
    int s_ptr = 0, t_ptr = 0;
    long long s_st = S[0].st, t_st = t[0].st;
    int cnt = 0;
    if (Rt == Ra && Ct == Ca) {
        cnt++;
    }
    while (s_ptr < M && t_ptr < L) {
        long long minn = min(s_st, t_st);
        s_st -= minn;
        t_st -= minn;
        char s_dir = S[s_ptr].dir;
        char t_dir = t[t_ptr].dir;
        for (long long i = 0; i < minn; ++i) {
            switch (s_dir) {
                case 'U': Rt--; break;
                case 'D': Rt++; break;
                case 'L': Ct--; break;
                case 'R': Ct++; break;
            }
            switch (t_dir) {
                case 'U': Ra--; break;
                case 'D': Ra++; break;
                case 'L': Ca--; break;
                case 'R': Ca++; break;
            }
            if (Rt == Ra && Ct == Ca) {
                cnt++;
            }
        }
        if (s_st == 0) {
            s_ptr++;
            if (s_ptr < M) {
                s_st = S[s_ptr].st;
            }
        }
        if (t_st == 0) {
            t_ptr++;
            if (t_ptr < L) {
                t_st = t[t_ptr].st;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
