#include <bits/stdc++.h>

using namespace std;

void DFS(vector<vector<int>> &graph, vector<bool> &visited, bool &arrive, int node, int depth);

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 정점 개수 및 간선 개수 입력 받기
    int N, M;
    cin >> N >> M;

    // 그래프 및 방문기록 선언
    vector<vector<int>> graph(N);
    vector<bool> visited(N, false);

    // 답안 분기 변수 선언
    bool arrive = false;

    // 그래프 채우기
    for (int i = 0; i < M; i++) {
        int v, e;
        cin >> v >> e;

        graph[v].push_back(e);
        graph[e].push_back(v);
    }

    // DFS 모든 정점에 대해서 계속 실행
    // 어떤 간선을 선택했는지에 따라 답이 다르게 나옴
    for (int i = 0; i < N; i++) {
        DFS(graph, visited, arrive, i, 1);
        if (arrive) break;
    }

    // 분기에 따라 적절한 답안 출력
    if (arrive) cout << 1 << '\n';
    else cout << 0 << '\n';

    return 0;
}

// 깊이 우선 탐색 알고리즘 사용
void DFS(vector<vector<int>> &graph, vector<bool> &visited, bool &arrive, int node, int depth) {
    // 깊이가 5이거나 arrive가 true로 갱신되었다면, 리턴
    if (depth == 5 || arrive) {
        arrive = true;
        return;
    }

    // 깊이 우선 탐색 알고리즘 부분
    visited[node] = true;
    for (int i : graph[node]) {
        if (!visited[i]) {
            // 깊이만 증가 시킴
            DFS(graph, visited, arrive, i, depth + 1);
        }
    }
    // 다시 탐색하기 위해서 방문기록 초기화
    visited[node] = false;

}