#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 2차원 벡터 선언
    vector<vector<int>> D(15, vector<int>(15));

    // 0층의 i호실에 사는 사람은 i명
    // 이로 인해 i층의 1층에 사는 사람은 1명
    for (int i = 0; i < 15; i++) {
        D[0][i] = i;
        D[i][1] = 1;
    }

    // 점화식
    // 뒤 호실에 사는 사람과 같은 호실 전층에 사는 사람 수를 더한 값이 현재 호실에 사는 사람임
    for (int i = 1; i < 15; i++) {
        for (int j = 2; j < 15; j++) {
            D[i][j] = D[i - 1][j] + D[i][j - 1];
        }
    }

    // 테스트 케이스 횟수 입력
    int T;
    cin >> T;

    // 테스트 케이스만큼 반복
    while (T--) {
        int a, b;
        cin >> a >> b;

        // DP로 저장해둔 값 출력
        cout << D[a][b] << '\n';
    }

    return 0;
}