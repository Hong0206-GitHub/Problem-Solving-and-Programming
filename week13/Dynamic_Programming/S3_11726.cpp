#include <bits/stdc++.h>

using namespace std;

const int MOD = 10007;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 입력 받기
    int n;
    cin >> n;

    // 테이블 선언
    vector<int> dp(n + 1);

    // 초기값 
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    // 마지막 타일을 기준으로 1x2를 넣는 경우와
    // 2x1을 넣는 경우에 대해서 더해줌
    for (int i = 3; i <= n; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;

    // 답안 출력
    cout << dp[n] << '\n';

    return 0;
}