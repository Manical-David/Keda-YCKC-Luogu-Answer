#include <bits/stdc++.h>
using namespace std;
const int N = 1e9;
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1);
    vector<pair<int, int>> edges(M);

    for (int i = 0; i < M; ++i) {
        int U, V;
        cin >> U >> V;
        edges[i] = {U, V};
        if (U != 0) {
            graph[U].push_back(V);
            graph[V].push_back(U);
        }
    }
    vector<int> result(N + 1, -1);
    for (int i = 1; i <= N; ++i) {
        vector<int> dist(N + 1, N);
        queue<int> q;
        for (auto& edge : edges) {
            if (edge.first == 0) {
                graph[edge.second].push_back(i);
                graph[i].push_back(edge.second);
            }
        }

        // BFS to find the shortest path from 1 to N
        dist[1] = 0;
        q.push(1);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : graph[u]) {
                if (dist[v] == N) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        // Remove the edges with U = 0 from the graph
        for (auto& edge : edges) {
            if (edge.first == 0) {
                graph[edge.second].pop_back();
                graph[i].pop_back();
            }
        }

        result[i] = (dist[N] == N) ? -1 : dist[N];
    }

    for (int i = 1; i <= N; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
