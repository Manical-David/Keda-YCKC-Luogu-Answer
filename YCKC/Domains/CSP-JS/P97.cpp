#include <bits/stdc++.h>
using namespace std;
struct Person {
    int time;
    int idx;
};
bool cmp(const Person &a, const Person &b) {
    return a.time < b.time;
}
int main() {
    int n;
    cin >> n;
    vector<Person> people(n);
    for (int i = 0; i < n; ++i) {
        cin >> people[i].time;
        people[i].idx = i + 1;
    }
    sort(people.begin(), people.end(), cmp);
    long long waits = 0;
    long long csum = 0;
    for (int i = 0; i < n - 1; ++i) {
        csum += people[i].time;
        waits += csum;
    }
    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << " ";
        cout << people[i].idx;
    }
    cout << endl;
    double ans = static_cast<double>(waits) / n;
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}