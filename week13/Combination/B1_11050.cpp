#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 조합 nCr의 n = N, r = K
    int N, K;
    cin >> N >> K;

    // 2차원 벡터 선언
    vector<vector<int>> D(N + 1, vector<int>(N + 1));

    // 아무것도 선택하지 않는 경우 1, 전체를 선택할 경우 1
    for (int i = 0; i <= N; i++) {
        D[i][0] = 1;
        D[i][i] = 1;
    }

    // 점화식
    // 마지막 원소에 한해서,
    // 마지막 원소를 선택할 경우, 그 앞의 모든 원소들 중에서 K-1 개가 선택되어야 함.
    // 마지막 원소를 선택하지 않는 경우, 그 앞의 모든 원소들 중에서 K개가 선택되어야 함.
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            D[i][j] = D[i - 1][j - 1] + D[i - 1][j];
        }
    }

    // 답안 출력
    cout << D[N][K] << '\n';

    return 0;
}