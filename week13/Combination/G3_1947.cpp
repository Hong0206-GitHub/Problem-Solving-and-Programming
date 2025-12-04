#include <bits/stdc++.h>

using namespace std;

// 상수
const long long MOD = 1000000000;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 사람 수 입력받기
    int N;
    cin >> N;

    // 벡터 선언
    vector<long long> D(N + 1);

    // 1명은 서로 교환할 수 없으므로 0
    D[1] = 0;

    // 2명은 서로 교환할 수 밖에 없으므로 1
    D[2] = 1;

    // 완전순열 점화식
    for (int i = 3; i <= N; i++) D[i] = ((i - 1) * (D[i - 1] + D[i - 2])) % MOD;

    // 답안 출력
    cout << D[N] << '\n';

    return 0;
}