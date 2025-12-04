#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 숫자 입력 받기
    int N;
    cin >> N;

    // DP 테이블 선언
    vector<long long> DP(N + 1);

    // 0이면 이친수 없음
    DP[0] = 0;

    // 1은 그 자체로 이친수 하나임
    DP[1] = 1;

    // 마지막 숫자가 0인 경우 N - 1 자리에 모든 이친수가 올 수 있음
    // 마지막 숫자가 1인 경우 11은 불가, 01에 대해서 N - 2의 모든 이친수가 올 수 있음
    for (int i = 2; i <= N; i++) DP[i] = DP[i - 1] + DP[i - 2];

    // 답안 출력
    cout << DP[N] << '\n';

    return 0;
}