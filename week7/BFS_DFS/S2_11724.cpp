#include <bits/stdc++.h>

using namespace std;

void DFS(vector<vector<int>> &graph, vector<bool> &visited, int node) {
    if (visited[node]) return;
    visited[node] = true;
    for (int i : graph[node])
        if (!visited[i]) DFS(graph, visited, i);
}

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 정점 개수 및 간선 개수 입력 받기
    int N, M;
    cin >> N >> M;

    // 그래프 선언 및 방문 기록 저장용 벡터 선언
    vector<vector<int>> graph(N + 1);
    vector<bool> visited(N + 1, false);

    // 그래프 채우기
    for (int i = 0; i < M; i++) {
        int v, e;
        cin >> v >> e;

        graph[v].push_back(e);
        graph[e].push_back(v);
    }

    // 번호가 작은 것 부터 방문하기 위해 정렬 수행
    for (int i = 1; i <= N; i++) sort(graph[i].begin(), graph[i].end());

    int count = 0;

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            count++;
            DFS(graph, visited, i);
        }
    }

    cout << count << '\n';

    return 0;
}