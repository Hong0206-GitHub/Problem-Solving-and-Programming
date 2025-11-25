#include <bits/stdc++.h>

using namespace std;

// 기본 변수 및 자료형 선언
static int N, M;
static vector<vector<int>> tree;
static vector<bool> visited;
static vector<int> depth;

static int kmax;
static int parent[21][100001];

// 함수 선언
int excuteLCA(int a, int b);
void BFS(int node);


int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 입력 받고
    cin >> N;

    // 사이즈 재정의
    tree.resize(N + 1);
    visited.resize(N + 1);
    depth.resize(N + 1);

    // 그래프 채우고
    for (int i = 0; i < N - 1; i++) {
        int s, e;
        cin >> s >> e;

        tree[s].push_back(e);
        tree[e].push_back(s);
    }

    // 기본 변수 초기화
    int temp = 1;
    kmax = 0;

    // 최대 가능 depth 구하기
    while (temp <= N) {
        temp <<= 1;
        kmax++;
    }

    // 깊이우선탐색
    BFS(1);

    // 점화식을 사용하여 parent 채우기
    for (int k = 1; k <= kmax; k++) {
        for (int n = 1; n <= N; n++) {
            parent[k][n] = parent[k - 1][parent[k - 1][n]];
        }
    }

    // 횟수 입력 받기
    cin >> M;

    // 두 노드의 최소 공통 조상 출력
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

    // b가 무조건 더 깊게 만들기
    if (depth[a] > depth[b]) {
        int temp = b;
        b = a;
        a = temp;
    }

    // depth 빠르게 맞추기
    for (int k = kmax; k >= 0; k--) {
        if (pow(2, k) <= depth[b] - depth[a]) {
            if (depth[a] <= depth[parent[k][b]]) {
                b = parent[k][b];
            }
        }
    }

    // 조상 빠르게 찾기
    for (int k = kmax; k >= 0 && a != b; k--) {
        if (parent[k][a] != parent[k][b]) {
            a = parent[k][a];
            b = parent[k][b];
        }
    }

    // 값 보정
    int LCA = a;
    if (a != b) {
        LCA = parent[0][LCA];
    }
    return LCA;
}

// 너비우선탐색
void BFS(int node) {

    queue<int> q;
    q.push(node);
    visited[node] = true;

    // 현재 상태를 나타내는 변수 선언
    int now_size = 1;
    int level = 1;
    int count = 0;

    while (!q.empty()) {
        int now_node = q.front();
        q.pop();

        for (int next : tree[now_node]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
                parent[0][next] = now_node;
                depth[next] = level;
            }
        }

        count++;

        // 초기화
        if (count == now_size) {
            count = 0;
            now_size = q.size();
            level++;
        }
    }
}