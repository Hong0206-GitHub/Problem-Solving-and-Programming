#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 개수 입력 받기
    int N;
    cin >> N;

    // 개수에 맞춰 벡터 초기화
    vector<int> T(N + 1);
    vector<int> P(N + 1);
    vector<int> DP(N + 2);

    // 입력 받기
    for (int i = 1; i <= N; i++) {
        cin >> T[i];
        cin >> P[i];
    }

    // DP 역순으로 채우기
    for (int i = N; i >= 1; i--) {
        // 일이 불가능 할 경우,
        // 오늘은 넘기므로, 다음날부터 마지막 날까지 얻을 수 있는 최대 수익을
        // 저장해야함
        if (N + 1 < i + T[i]) DP[i] = DP[i + 1];
        
        // 일이 가능할 경우,
        // 오늘을 넘길지, 오늘 일을 시작할지를 선택하여 최대 수익을 얻을 수 있는 걸
        // 선택해야함
        else {
            DP[i] = max(DP[i + 1], P[i] + DP[i + T[i]]);
        }
    }

    // 1일부터 시작하여 마지막 날까지 얻은 최대 수익 출력
    cout << DP[1] << '\n';

    return 0;
}