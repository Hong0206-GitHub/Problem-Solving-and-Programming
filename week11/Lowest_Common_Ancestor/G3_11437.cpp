#include <bits/stdc++.h>

using namespace std;

// LCA 기본 자료형 선언
static int N, M;
static vector<vector<int>> tree;
static vector<int> depth;
static vector<int> parent;
static vector<bool> visited;

// 함수 선언
int excuteLCA(int a, int b);
void BFS(int node);  

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 입력 받기
    cin >> N;

    // 사이즈 재정의
    tree.resize(N + 1);
    depth.resize(N + 1);
    parent.resize(N + 1);
    visited.resize(N + 1);

    // 그래프 채우기 (양방향)
    for (int i = 0; i < N - 1; i++) {
        int s, e;
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }

    // 루트부터 시작해서 너비우선탐색
    BFS(1);
    
    // 입력 받기
    cin >> M;

    // 입력 받은 두 노드의 최소공통조상 출력
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        int LCA = excuteLCA(a, b);
        cout << LCA << '\n';
    }

    return 0;
}

// 최소공통조상 찾는 함수
int excuteLCA(int a, int b) {

    // 무조건 a의 깊이가 더 크게 만들기
    if (depth[a] < depth[b]) {
        int temp = a;
        a = b;
        b = temp;
    }

    // 깊이가 같아질 때 까지 a만 위로 올림
    while (depth[a] != depth[b]) {
        a = parent[a];
    }

    // 두 노드가 같아질 때까지 올림
    // 노드는 부모로 갱신됨
    while (a != b) {
        a = parent[a];
        b = parent[b];
    }

    return a;
}

// 너비우선탐색 알고리즘
void BFS(int node) {

    // 큐 선언
    queue<int> q;
    q.push(node);
    visited[node] = true;
   
    // 현재 상태를 나타내는 변수 선언
    int level = 1;  // 현재 레벨
    int now_size = 1;  // 현재 사이즈
    int count = 0; // 처리한 노드의 개수
   
    // 큐가 빌 때까지
    while (!q.empty()) {
        int now_node = q.front();
        q.pop();

        // 큐에서 하나 꺼내서 반복
        for (int next : tree[now_node]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                parent[next] = now_node;
                depth[next] = level;    // 깊이 갱신
            }
        }

        // 처리 노드 하나 증가
        count++;

        // 모두 처리했다면
        if (count == now_size) {
            count = 0;  // 카운트 0으로 초기화 하고
            now_size = q.size(); // 사이즈 초기화 해주고
            level++; // 레벨 증가
        }
    }
}