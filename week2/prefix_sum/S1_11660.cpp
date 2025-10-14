#include <iostream>
#include <vector>
using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 2차원 벡터 크기 및 테스트 케이스 입력
    int N, M;
    cin >> N >> M;

    // 2차원 누적합 벡터 선언
    vector<vector<int>> sum(N + 1, vector<int>(N + 1));
    
    // 누적합 채우기
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int temp;
            cin >> temp;
            // 2차원 누적합 공식
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + temp;
        }
    }

    // 테스트 케이스
    while (M--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // 2차원 구간합 공식
        cout << (sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1]) << '\n';
    }

    return 0;
}