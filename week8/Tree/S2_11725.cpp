#include <bits/stdc++.h>

using namespace std;

// 깊이 우선 탐색 알고리즘 사용
void DFS(vector<vector<int>> &tree, vector<bool> &visited, vector<int> &answer, int root);

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 노드 개수 입력 받기
    int N;
    cin >> N;

    // 트리, 방문 기록, 답안 벡터 선언 및 초기화
    vector<vector<int>> tree(N + 1);
    vector<bool> visited(N + 1);
    vector<int> answer(N + 1);

    // 트리 채우기
    for (int i = 0; i < N - 1; i++) {
        int v, e;
        cin >> v >> e;

        tree[v].push_back(e);
        tree[e].push_back(v);
    }

    // 깊이 우선 탐색 함수 호출
    // 루트 노드는 1이므로 1부터 시작
    DFS(tree, visited, answer, 1);
    
    // 답안 벡터 원소 내용 출력
    for (int i = 2; i <= N; i++) cout << answer[i] << '\n';
    return 0;
}

// 깊이 우선 탐색 함수
void DFS(vector<vector<int>> &tree, vector<bool> &visited, vector<int> &answer, int root) {
    visited[root] = true;   // 방문기록
    for (int i : tree[root]) {  // 모든 자식 노드에 대해
        if (!visited[i]) {  // 아직 방문하지 않았다면
            answer[i] = root;   // 방문해서, 답안에 해당 노드의 부모 노드 저장
            DFS(tree, visited, answer, i);  // 재귀호출
        }
    }
}