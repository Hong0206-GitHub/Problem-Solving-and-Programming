#include <bits/stdc++.h>

using namespace std;

// 함수 선언 및 변수 선언
void unionfunc(int a, int b);
bool checksame(int a, int b);
int find(int a);
int N, M;
vector<int> parent;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 입력 받기
    cin >> N >> M;
    parent.resize(N + 1);

    // 초기값 넣기
    for (int i = 1; i <= N; i++) parent[i] = i;

    // M 만큼 반복
    for (int i = 0; i < M; i++) {

        // 질의 입력 받기
        int q, a, b;
        cin >> q >> a >> b;

        // 질의 형태에 따른 동작
        if (q == 0 ) {
            unionfunc(a, b);
        } else {
            if (checksame(a, b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}

// union 연산 대표 노드끼리 연결
void unionfunc(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[b] = a;
}

// 두 원소가 같은 집합인지 확인
bool checksame(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return 1;
    else return 0;
}

// 대표 노드 찾아서 리턴
int find(int a) {
    if (a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}