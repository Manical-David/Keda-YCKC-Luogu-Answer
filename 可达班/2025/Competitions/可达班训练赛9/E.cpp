#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAX_MU = 1e6;
const int MAX_POW = 2e5 + 10;
vector<int> mu(MAX_MU + 1, 1);
vector<int> lpf(MAX_MU + 1, 0);
vector<int> primes;
vector<long long> pow2(MAX_POW);
void miu() {
    for (int i = 2; i <= MAX_MU; ++i) {
        if (lpf[i] == 0) {
            lpf[i] = i;
            primes.push_back(i);
            mu[i] = -1;
        }
        for (size_t j = 0; j < primes.size() && primes[j] <= lpf[i] && i * primes[j] <= MAX_MU; ++j) {
            int p = primes[j];
            int num = i * p;
            lpf[num] = p;
            if (p == lpf[i]) {
                mu[num] = 0;
            } else {
                mu[num] = mu[i] * mu[p];
            }
        }
    }
}
void pow_2() {
    pow2[0] = 1;
    for (int i = 1; i < MAX_POW; ++i) {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }
}
int compute_mu(int k) {
    if (k == 1) return 1;
    int mu_k = 1;
    int temp = k;
    for (int p = 2; p * p <= temp; ++p) {
        if (temp % p == 0) {
            int cnt_p = 0;
            while (temp % p == 0) {
                cnt_p++;
                temp /= p;
            }
            if (cnt_p > 1) {
                return 0;
            }
            mu_k *= -1;
        }
    }
    if (temp > 1) {
        mu_k *= -1;
    }
    return mu_k;
}
int main() {
    miu();
    pow_2();
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    unordered_set<int> d_set;
    for (int x : a) {
        if (x < 2) continue;
        unordered_set<int> fac;
        for (int i = 1; i * i <= x; ++i) {
            if (x % i == 0) {
                if (i >= 2) fac.insert(i);
                int j = x / i;
                if (j >= 2) fac.insert(j);
            }
        }
        for (int f : fac) {
            d_set.insert(f);
        }
    }
    long long ans = 0;
    for (int d : d_set) {
        int s = 0;
        vector<int> B;
        for (int num : a) {
            if (num % d == 0) {
                s++;
                B.push_back(num / d);
            }
        }
        if (s == 0) continue;
        int max_B = 0;
        unordered_map<int, int> freq;
        for (int x : B) {
            freq[x]++;
            if (x > max_B) max_B = x;
        }
        vector<int> cnt(max_B + 1, 0);
        for (auto& p : freq) {
            cnt[p.first] = p.second;
        }
        vector<int> sum_cnt(max_B + 1, 0);
        for (int k = 1; k <= max_B; ++k) {
            for (int m = k; m <= max_B; m += k) {
                sum_cnt[k] += cnt[m];
            }
        }
        long long sum_val = 0;
        for (int k = 1; k <= max_B; ++k) {
            int c_k = sum_cnt[k];
            if (c_k == 0) continue;
            int mu_k;
            if (k <= MAX_MU) {
                mu_k = mu[k];
            } else {
                mu_k = compute_mu(k);
            }
            if (mu_k == 0) continue;
            long long t;
            if (c_k - 1 >= MAX_POW) {
                long long pow = 1;
                long long base = 2;
                int exponent = c_k - 1;
                while (exponent > 0) {
                    if (exponent % 2 == 1) {
                        pow = (pow * base) % MOD;
                    }
                    base = (base * base) % MOD;
                    exponent /= 2;
                }
                t = (mu_k * ((long long)c_k * pow % MOD)) % MOD;
            } else {
                t = (mu_k * ((long long)c_k * pow2[c_k - 1] % MOD)) % MOD;
            }
            sum_val = (sum_val + t) % MOD;
        }
        sum_val = (sum_val % MOD + MOD) % MOD; // 确保非负
        long long con = ((long long)d * sum_val) % MOD;
        ans = (ans + con) % MOD;
    }
    cout << ans % MOD << endl;
    return 0;
}