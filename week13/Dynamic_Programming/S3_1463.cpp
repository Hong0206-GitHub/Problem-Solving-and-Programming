#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 숫자 입력 받기
    int N;
    cin >> N;

    // 벡터 선언
    vector<int> DP(N + 1);

    // 1은 그 자체로 1이므로 연산 필요 없음
    DP[1] = 0;

    // DP 테이블 채우기
    for (int i = 2; i <= N; i++) {
        DP[i] = DP[i - 1] + 1;

        if (i % 2 == 0) DP[i] = min(DP[i], DP[i / 2] + 1);
        if (i % 3 == 0) DP[i] = min(DP[i], DP[i / 3] + 1);
    }

    // 답안 출력
    cout << DP[N] << '\n';

    return 0;
}