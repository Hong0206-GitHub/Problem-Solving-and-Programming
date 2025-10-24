#include <bits/stdc++.h>

using namespace std;

// 에라토스테네스의 체 알고리즘을 사용하여
// index 에 대한 값이 소수인지 아닌지를 판별하여,
// bool 값으로 저장
void sieve_of_eratosthenes(vector<bool> &v) {
    // 0은 소수 판별에 사용하지 않음
    v[0] = false;

    // 1은 소수 판별에 사용하지 않음
    v[1] = false;

    // 2부터 시작함 ~ 원하는 범위의 제곱근까지
    for (int i = 2; i * i < v.size(); i++) {
        // 현재의 벡터 값이 true(소수) 인 경우
        if (v[i]) {
            // 해당 값은 넘어가고,
            // 그 값의 배수들은 소수가 아니므로, false로 값 갱신
            for (int j = i * i; j < v.size(); j += i) v[j] = false;
        }
    }
}

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 1~1,000,000 까지
    vector<bool> v(1000001, true);

    // 함수 호출해서 소수 판별
    sieve_of_eratosthenes(v);

    // M~N 까지의 범위를 나타내는 입력값 받기
    int M, N;
    cin >> M >> N;

    // 답안 출력
    for (int i = M; i <= N; i++)
        if (v[i] == true) cout << i << '\n';

    return 0;
}