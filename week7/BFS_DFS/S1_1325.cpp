#include <bits/stdc++.h>

using namespace std;

// 깊이 우선 탐색으로 구현
void DFS(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &answer, int node);

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 정점 개수 및 간선 개수 입력 받기
    int N, M;
    cin >> N >> M;

    // 답안 저장 벡터 및 그래프, 방문기록 저장용 벡터 선언
    vector<vector<int>> graph(N + 1);
    vector<int> answer(N + 1);
    vector<bool> visited(N + 1, false);

    // 입력 받기
    // 양방향 그래프가 아니므로, 한번만
    for (int i = 0; i < M; i++) {
        int v, e;
        cin >> v >> e;

        graph[v].push_back(e);
    }

    // 모든 정점에 대해서
    // 깊이 우선 탐색 진행
    for (int i = 0; i <= N; i++) {
        fill(visited.begin(), visited.end(), false);
        DFS(graph, visited, answer, i);
    }

    // 답안 벡터의 최댓값 구하기
    int max_val = INT_MIN;
    for (int i = 1; i <= N; i++) {
        if (max_val < answer[i]) max_val = answer[i];
    }

    // 최댓값과 같은 정점이 정답임
    for (int i = 1; i <= N; i++) {
        if (max_val == answer[i]) cout << i << ' ';
    }

    cout << '\n';

    return 0;
}

// 깊이 우선 탐색
void DFS(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &answer, int node) {
    // 현재 노드 방문 처리
    visited[node] = true;
    // 연결되어있는 간선을 따라
    for (int i : graph[node]) {
        // 아직 방문이 안되어있다면
        if (!visited[i]) {
            answer[i]++;    // 답안 배열 값 증가시키고,
            DFS(graph, visited, answer, i); // 재귀호출
        }
    }
}