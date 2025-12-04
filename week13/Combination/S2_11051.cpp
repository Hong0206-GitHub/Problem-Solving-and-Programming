#include <bits/stdc++.h>

using namespace std;

// 문제에서 제시한 상수
const int MOD = 10007;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 두 값 입력 받기
    int N, K;
    cin >> N >> K;

    // 2차원 벡터 선언
    vector<vector<int>> D(N + 1, vector<int>(N + 1));

    // 초기값 세팅
    for (int i = 0; i <= N; i++) {
        D[i][0] = 1;
        D[i][i] = 1;
    }

    // 벡터 채우기, 나머지 규칙에 의해 계산함
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            D[i][j] = ((D[i - 1][j - 1] % MOD) + (D[i - 1][j] % MOD)) % MOD;
        }
    }

    // 답안 출력
    cout << D[N][K] << '\n';

    return 0;
}