#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 소수인지 아닌지를 저장하는 bool 벡터 선언
    vector<bool> v(1e7 + 1, true);
    v[0] = false;
    v[1] = false;
    
    // 문제의 전체 조건에 대한 소수 구하기
    for (ll i = 2; i * i <= 1e7; i++)
        if (v[i])
            for (int j = i * i; j <= 1e7; j += i)
                v[j] = false;

    // 입력값
    ll A, B;
    cin >> A >> B; 

    // 답안 저장용 변수
    int count = 0;

    // 전체 벡터 범위에 대해
    for (ll i = 2; i <= 1e7; i++) {
        if (v[i]) {
            // 소수의 제곱을 temp 에 저장
            ll temp = i * i;
            // temp 가 B보다 작거나 같을 때까지
            while (temp <= B) {
                // temp가 A보다 크거나 같으면
                // 카운트 증가
                if (temp >= A) count++;
                
                // 오버플로우 방지용
                if (temp > B / i) break;
                
                // 소수의 제곱수를 늘려감
                temp *= i;
            }
        }
    }

    // 답안 출력
    cout << count << '\n';

    return 0;
}