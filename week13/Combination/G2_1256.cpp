#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 변수 입력 받기
    int N, M, K;
    cin >> N >> M >> K;

    // 2차원 벡터 선언
    vector<vector<long long>> D(201, vector<long long>(201));

    // 조합 기본 값 채워 넣기
    for (int i = 0; i < 201; i++) {
        D[i][i] = 1;
        D[i][0] = 1;
    }

    // 조합 값 DP로 채워넣기
    for (int i = 1; i < 201; i++) {
        for (int j = 1; j < i; j++) {
            D[i][j] = D[i - 1][j - 1] + D[i - 1][j];

            // 범위 벗어난 것들은 큰 신경 안써도 됨
            if (D[i][j] > 1000000000) D[i][j] = 1000000001;
        }
    }

    // K번째 문자열이 존재하지 않는 경우
    if (D[N + M][M] < K) {
        cout << -1 << '\n';
        return 0;
    }

    // 둘 중 하나가 0이 될 때까지
    while (N > 0 && M > 0) {
        //a 를 선택 가능한 경우
        if (D[N - 1 + M][M] >= K) {
            cout << 'a';
            N--;
        }

        // z를 선택해야하는 경우
        else {
            cout << 'z';
            K -= D[N - 1 + M][M];
            M--;
        }
    }

    // 나머지 문자들도 출력
    while (N-- > 0) cout << 'a';
    while (M-- > 0) cout << 'z';
    cout << '\n';
    return 0;
}