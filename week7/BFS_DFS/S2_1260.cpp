#include <bits/stdc++.h>

using namespace std;

// 그래프
static vector<vector<int>> graph;

// 방문 여부 기록 벡터
static vector<bool> check;

static bool arrive;

// 깊이 우선 탐색 알고리즘
void DFS(int node) {
    cout << node << " ";
    check[node] = true;
    for (int i : graph[node]) {
        if (!check[i]) DFS(i);
    }
}

// 너비 우선 탐색 알고리즘
void BFS(int node) {
    queue<int> q;
    q.push(node);
    check[node] = true;

    while (!q.empty()) {
        int now_node = q.front();
        q.pop();
        cout << now_node << " ";
        for (int i : graph[now_node]) {
            if (!check[i]) {
                check[i] = true;
                q.push(i);
            }
        }
    }
}

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 정점, 간선, 시작 노드 입력 받기
    int N, M, V;
    cin >> N >> M >> V;

    // 초기값 설정
    arrive = false;
    graph.resize(N + 1);

    // 입력 받고 그래프 채우기
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        // 양방향 그래프이므로, 둘다 추가해주어야 함
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // 작은 번호의 노드부터 탐색하므로 정렬
    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    // 초기값 초기화
    check = vector<bool>(N + 1, false);
    DFS(V);
    cout << '\n';
    
    // 방문 여부 초기화
    fill(check.begin(), check.end(), false);
    BFS(V);
    cout << '\n';

    return 0;
}