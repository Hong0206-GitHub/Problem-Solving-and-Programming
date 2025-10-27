#include <bits/stdc++.h>

using namespace std;

// 기본 자료형 선언 및 초기화
static vector<vector<int>> graph;
static vector<bool> visited;
static int answer = 0;
static int deleteNode = 0;
static int N;

// 함수 선언
void DFS(int node);

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 개수 입력 받기
    cin >> N;

    // 사이즈 및 기본값 초기화
    graph.resize(N);
    visited = vector<bool>(N, false);
    int root = 0;

    // 입력 받기
    for (int i = 0; i < N; i++) {
        int temp;   
        cin >> temp;
        // 부모 노드가 루트가 아니라면
        if (temp != -1) {
            // 그래프에 삽입
            graph[i].push_back(temp);
            graph[temp].push_back(i);
    
        }
        // 루트노드라면 루트 갱신
        else root = i;
    }

    // 삭제할 노드 입력 받기
    cin >> deleteNode;
    // 루트 노드를 삭제 할경우, 리프노드는 남지 않음
    if (deleteNode == root) cout << 0 << '\n';
    else {
        // 루트노드가 아닌 다른 노드를 삭제 하는 경우,
        // 깊이 우선 탐색 으로 백트래킹
        DFS(root);
        // 답안 출력
        cout << answer << '\n';
    }
    return 0;
}

// 깊이 우선 탐색 백트래킹 알고리즘 사용
void DFS(int node) {
    visited[node] = true;
    int cNode = 0;  // 자식이 있는지를 확인
    for (int i : graph[node]) {
        // 방문하지 않은 노드에 대해
        if (!visited[i] && i != deleteNode) {
            cNode++;    // 자식 수 증가 시키고
            DFS(i); // 재귀호출
        }
    }
    // 자식이 없다면,
    // 해당 노드는 리프노드임
    if (cNode == 0) {
        answer++;   // 답안 증가
    }
}