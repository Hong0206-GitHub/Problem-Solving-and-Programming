#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 2차원 벡터 선언
    // 입력 조건에 따라 사이즈 조정
    vector<vector<int>> D(30, vector<int>(30));

    // 초기값 세팅
    for (int i = 0; i < 30; i++) {
        D[i][0] = 1;
        D[i][i] = 1;
    }

    // 조합 점화식 사용
    for (int i = 1; i < 30; i++) {
        for (int j = 1; j < i; j++) {
            D[i][j] = D[i - 1][j - 1] + D[i - 1][j];
        }
    }

    // 테스트 케이스 횟수 입력 받기
    int T;
    cin >> T;

    // 테스트 케이스 만큼
    while (T--) {

        // 입력 받아서
        int N, M;
        cin >> N >> M;

        // 출력, M개의 다리 중에서 N개를 선택함
        cout << D[M][N] << '\n';
    }

    return 0;
}