#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> K(N + 1);
    for (int i = 1; i <= N; ++i) cin >> K[i];

    vector<int> dist(N + 1, -1);
    queue<int> q;
    dist[A] = 0;
    q.push(A);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == B) break;
        int up = cur + K[cur];
        int down = cur - K[cur];
        if (up <= N && dist[up] == -1) {
            dist[up] = dist[cur] + 1;
            q.push(up);
        }
        if (down >= 1 && dist[down] == -1) {
            dist[down] = dist[cur] + 1;
            q.push(down);
        }
    }
    cout << dist[B] << endl;
    return 0;
}