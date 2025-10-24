#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 입력 받기
    ll N, K;
    cin >> N >> K;

    // 시작값 종료값 선언
    // 2차원 배열은 N행이 N의 배수로 구성되어 있으므로,
    // 2차원 배열에서의 K번째 수는 K를 넘지 않음
    // 따라서 1~K 사이에 답이 있음
    ll start = 1, end = K;
    ll answer = 0;
    while (start <= end) {
        ll mid = (start + end) / 2;
        ll cnt = 0;

        // mid 보다 작은 값이 몇 개인지 계산
        // 작은 수를 카운트
        for (int i = 1; i <= N; i++) cnt += min(mid / i, N);
        
        if (cnt < K) start = mid + 1;
        else {
            answer = mid;   // 현재 단계의 중앙 값을 변수에 저장
            end = mid - 1;
        }
    }

    // 답안 출력
    cout << answer << '\n';

    return 0;
}