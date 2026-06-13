#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > a(n);
    int maxn = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        maxn += a[i].second * a[i].second;
    }
    bitset<1000001> dp; // 听你说的做的哈，出问题了找你（TLE）
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        int l = a[i - 1].first, r = a[i - 1].second;
        bitset<1000001> in_d;
        for (int x = l; x <= r; x++) {
            int s = x * x;
            in_d |= (dp << s);
        }
        dp = in_d;
    }
    cout << dp.count() << '\n';
    return 0;
}
/*
    提示🔔：
    本人在中国科技研究院温州英才学院闭关修炼1年，水平有所提高。
    若AK，勿喷！
    如果对本人代码有疑义，本人可以开Youtube Livestream直播讲题。

    还有，不知道keda是否支持ACLibrary，如果有的话可以稍微说一下吗？
*/