#include <bits/stdc++.h>

using namespace std;

vector<int> parent;

// 유니온 파인드 알고리즘 사용
// 파인드 함수는 해당 원소가 속해있는 루트 노드의 값을 가짐
// 경로 압축을 통해서 트리의 높이를 납작하게 만들어 접근 속도를 높임
int find(int a) {
    if (a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}

// 두 노드를 하나의 집합으로 합치는 함수
void unionFunc(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) parent[b] = a;
}

int main(void) {

    // 입출력 가속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 입력 받기
    int n, m;
    cin >> n >> m;

    // 초기값 세팅
    // 초기에는 자기 자신을 루트 노드로 가짐
    parent.resize(n);
    for (int i = 0; i < n; i++) parent[i] = i;

    // 값을 입력 받으면서
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        // 두 값의 루트 노드 값이 다른 경우 사이클이 없으므로, 같은 집합으로 묶음
        if (find(a) != find(b)) {
            unionFunc(a, b);
        }
        // 같은 경우 사이클이 생긴 것이므로 해당 횟수 출력 후 종료
        else {
            cout << i << '\n';
            return 0;
        }
    }

    // 위에서 걸러지지 않았다면,
    // 끝까지 사이클이 생기지 않았다는 것이므로 0 출력
    cout << 0 << '\n';

    return 0;
}