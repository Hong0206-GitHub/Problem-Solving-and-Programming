#include <bits/stdc++.h>

using namespace std;

int main(void) {

    ios::sync_with_stdio(false), cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);
    vector<int> indegree(N + 1);

    while (M--) {
        int temp;
        cin >> temp;

        vector<int> order(temp);

        for (int i = 0; i < temp; i++) cin >> order[i];

        for (int i = 0; i < temp - 1; i++) {
            int a = order[i];
            int b = order[i + 1];

            graph[a].push_back(b);
            indegree[b]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= N; i++)
        if (indegree[i] == 0) q.push(i);

    vector<int> answer;
    while (!q.empty()) {
        int now = q.front();
        q.pop();

        answer.push_back(now);

        for (int next : graph[now]) {
            if (--indegree[next] == 0) q.push(next);
        }
    }

    if (answer.size() != N) {
        cout << "0\n";
    } else {
        for (int i : answer) {
            cout << i << '\n';
        }
    }


    return 0;
}