#include <bits/stdc++.h>

using namespace std;

// 깊이 우선 탐색으로 하면 시간초과
// 너비 우선 탐색 알고리즘 사용
void BFS(vector<vector<int>> &graph, vector<int> &visited, int node);

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 입력값 저장
    int N, M, K, X;
    cin >> N >> M >> K >> X;

    // 기초 그래프, 방문, 답안 벡터 선언
    vector<vector<int>> graph(N + 1);
    vector<int> visited(N + 1, -1);
    vector<int> answer;

    // 그래프 채우기
    for (int i = 0; i < M; i++) {
        int v, e;
        cin >> v >> e;

        graph[v].push_back(e);
    }

    // 너비 우선탐색 함수 호출
    BFS(graph, visited, X);

    // 같은 거리에 있는 정점들 정답 벡터에 저장
    for (int i = 0; i <= N; i++) {
        if (visited[i] == K) {
            answer.push_back(i);
        }
    }

    // 정답 벡터가 비어있으면, -1 출력
    if (answer.empty()) cout << -1 << '\n';
    // 비어있지 않으면, 정렬 후 해당 정점 출력
    else {
        sort(answer.begin(), answer.end());
        for (int i : answer) cout << i << '\n';
    }

    return 0;
}

// 너비 우선 탐색 알고리즘
void BFS(vector<vector<int>> &graph, vector<int> &visited, int node) {
    queue<int> q;   // 큐 선언
    q.push(node);   // 현재 노드 삽입
    visited[node]++;    // 방문횟수 증가

    // 큐가 빌 때까지
    while (!q.empty()) {
        // 큐에서 하나 꺼내서 저장
        int now_node = q.front();
        q.pop();

        // 연결된 정점들에 대해
        for (int i : graph[now_node]) {
            if (visited[i] == -1) { // 방문하지 않았다면
                visited[i] = visited[now_node] + 1; // 방문해서 거리 1 증가 시킴
                q.push(i);  // 큐에 삽입
            }
        }
    }

}