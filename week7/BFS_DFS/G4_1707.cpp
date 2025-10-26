#include <bits/stdc++.h>

using namespace std;

// 깊이 우선 탐색 알고리즘 사용
void DFS(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &check, bool &is_even, int node);

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 테스트 횟수 입력 받기
    int K;
    cin >> K;

    // 테스트 횟수만큼
    while (K--) {
        // 정점과 간선 개수 입력 받기
        int N, M;
        cin >> N >> M;

        // 필요한 것 초기화
        vector<vector<int>> graph(N + 1);
        vector<bool> visited(N + 1, false);
        vector<int> check(N + 1, 0);

        bool is_even = true;

        // 그래프 채우기
        for (int i = 0; i < M; i++) {
            int v, e;
            cin >> v >> e;

            graph[v].push_back(e);
            graph[e].push_back(v);
        }

        // 모든 정점에 대해서 
        for (int i = 1; i <= N; i++) {
            if (is_even) DFS(graph, visited, check, is_even, i);
            else break;
        }

        // 답안 출력
        if (is_even) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}

// 깊이 우선 탐색 알고리즘
void DFS(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &check, bool &is_even, int node) {
    // 방문여부 갱신
    visited[node] = true;
    // 간선에 연결되어 있는
    for (int i : graph[node]) {
        if (!visited[i]) {
            check[i] = (check[node] + 1) % 2;   // 0과 1로 직전에 탐색한 곳 여부를 판단 
            DFS(graph, visited, check, is_even, i); // 깊이 우선탐색 재귀호출
        }
        // 직전에 방문한 곳과 같은 곳을 방문한 경우
        // 사이클이 생긴 것이므로, 답에서 제외
        else if (check[node] == check[i]) is_even = false;
    }

}