#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 총 조약돌 개수
    double N = 0.0;

    // 색상 개수, 선택할 조약돌 개수
    int M, K;

    cin >> M;

    // 색상에 따른 조약돌 개수 저장
    vector<int> color(M);

    // 입력 받으면서, 총 조약돌 개수 누적
    for (int i = 0; i < M; i++) {
        cin >> color[i];
        N += color[i];
    }

    cin >> K;

    // 답안 저장 변수
    double answer = 0.0;
    
    // 선택 가능한 수보다 적은 수의 조약돌은 무시
    for (int i = 0; i < M; i++) {
        if (color[i] < K) continue;

        // 임시변수
        double temp = 1.0;

        // 확률계산
        for (int j = 0; j < K; j++) {
            temp *= (color[i] - j) / (N - j);
        }
        // 답안 저장 변수에 누적 합
        answer += temp;
    }

    // 소수점 자리 조정하고 답안 출력
    cout << fixed << setprecision(9) << answer << '\n';
    return 0;
}