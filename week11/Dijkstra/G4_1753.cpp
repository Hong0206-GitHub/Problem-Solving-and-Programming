#include <bits/stdc++.h>

using namespace std;
using edge = pair<int, int>;

int main(void) {


    ios::sync_with_stdio(false), cin.tie(NULL);

    int V, E, K;
    cin >> V >> E >> K;

    vector<int> mdistance(V + 1, INT_MAX);
    vector<bool> visited(V + 1, false);
    vector<vector<edge>> mlist(V + 1);
    priority_queue<edge, vector<edge>, greater<edge>> pq;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        mlist[u].push_back({v, w});
    }

    pq.push({0, K});
    mdistance[K] = 0;

    while (!pq.empty()) {
        edge current = pq.top();
        pq.pop();

        int c_v = current.second;
        if (visited[c_v]) continue;

        for (size_t i = 0; i < mlist[c_v].size(); i++) {
            edge temp = mlist[c_v][i];

            int next = temp.first;
            int weight = temp.second;
            
            if (mdistance[next] > mdistance[c_v] + weight) {
                mdistance[next] = mdistance[c_v] + weight;
                pq.push({mdistance[next], next});
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (visited[i]) cout << mdistance[i] << '\n';
        else cout << "INF\n";
    }

    return 0;
}