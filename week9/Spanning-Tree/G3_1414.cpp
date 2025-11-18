#include <bits/stdc++.h>

using namespace std;

// 서로 다른 집합을 하나로 합치는 함수
void munion(int a, int b);

// 집합의 대표 노드 찾는 함수
int find(int a);

vector<int> parent;

// 우선순위 큐의 우선순위를 결정하는 구조체
typedef struct Edge {
    int s, e, v;
    bool operator > (const Edge &temp) const {
        return v > temp.v;
    }
};

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 입력 받기 및 초기 함수 세팅
    int N, sum = 0;
    cin >> N;

    // 우선순위 큐 선언
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    // 문자로 입력 받으면서 아스키 코드값을 통해 정수로 변환 후,
    // 우선순위 큐에 삽입
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char tempc = cin.get();
            if (tempc == '\n') {
                tempc = cin.get();
            }

            int temp = 0;

            if (tempc >= 'a' && tempc <= 'z') {
                temp = tempc -  'a' + 1;
            }
            else if (tempc >= 'A' && tempc <= 'Z') {
                temp = tempc - 'A' + 27;
            }

            sum += temp;
            if (i != j && temp != 0) pq.push(Edge{i, j, temp});
        }
    }

    // 초기세팅
    parent.resize(N);
    for (int i = 0; i < N; i++) parent[i] = i;

    
    int useEdge = 0;
    int result = 0;

    // 두 집합 연결
    while (!pq.empty()) {
        Edge now = pq.top();
        pq.pop();

        if (find(now.s) != find(now.e)) {
            munion(now.s, now.e);
            result += now.v;
            useEdge++;
        }
    }

    // 조건에 맞는지 확인 후 적절한 답안 출력
    if (useEdge == N - 1) cout << sum - result << '\n';
    else cout << -1 << '\n';

    return 0;
}

void munion(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) parent[b] = a;
}

int find(int a) {
    if (a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}