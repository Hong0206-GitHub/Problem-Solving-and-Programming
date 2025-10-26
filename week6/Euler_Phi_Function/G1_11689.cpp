#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 입력 값 저장 변수 선언 및 입력 받기
    ll N;
    cin >> N;

    // 답안 출력용 변수
    ll result = N;

    // 오일러피 함수
    // 오일러피(N) 의 정의는 1~N까지의 범위에서 N과 서로소인 자연수의 개수
    // 즉, GCD(N, K) == 1을 만족하는 자연수 K의 개수(GCD(N, K) 는 N과 K의 최대 공약수)
    for (ll i = 2; i * i <= N; i++) {
        if (N % i == 0) {   // 소인수라면
            result = result - (result / i);  // 결과 값 업데이트
            
            while (N % i == 0) N /= i;  // 해당 소인수 삭제
        }
    }
    // 아직 소인수 구성이 남아있는 경우, 1개의 소인수가 누락된 경우
    if (N > 1) result = result - (result / N);

    // 결과 출력
    cout << result << '\n';

    return 0;
}