#include <bits/stdc++.h>

using namespace std;

// Union-find 확장버전
// 크루스칼 알고리즘 사용
void munion(int a, int b);
int find(int a);

vector<int> parent;

// 엣지 우선순위 정할 구조체 선언
typedef struct Edge {
    int s, e, v;
    bool operator > (const Edge &temp) const {
        return v > temp.v;
    }
}Edge;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 입력 받기
    int N, M;
    cin >> N >> M;

    // 우선순위 큐 선언
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    parent.resize(N + 1);

    // 초기값 세팅
    for (int i = 0; i <= N; i++) parent[i] = i;

    // 값 입력 받아서 우선순위 큐에 삽입
    // 자동 정렬됨.
    for (int i = 0; i < M; i++) {
        int s, e, v;
        cin >> s >> e >> v;
        pq.push(Edge{s, e, v});
    }


    int useEdge = 0;
    int result = 0;
    while (useEdge < N - 1) {
        Edge now = pq.top();
        pq.pop();

        // 다르다면 서로 연결시켜 줌.
        // 엣지 수 증가.
        if (find(now.s) != find(now.e)) {
            munion(now.s, now.e);
            result += now.v;
            useEdge++;
        }
    }

    // 답안 출력
    cout << result << '\n';

    return 0;
}

// 합집합 만들기
void munion(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) parent[b] = a;
}

// 재귀적으로 부모 노드 탐색
int find(int a) {
    if (a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}