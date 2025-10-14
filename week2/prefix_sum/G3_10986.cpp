#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 원소 개수와 나눌 수 입력 받기
    int N, M;
    cin >> N >> M;

    // 답안 저장용 변수
    ll cnt = 0;

    // 누적합 벡터와 나머지 빈도 저장할 벡터 선언
    vector<ll> v(N);
    vector<ll> c(M);

    // 첫 번째 값에 대해서 처리
    cin >> v[0];
    v[0] %= M;
    if (v[0] == 0) cnt++;
    c[v[0]]++;

    // 다음 값에 대해서 처리
    for (int i = 1; i < N; i++) {
        int temp;
        cin >> temp;
        v[i] = (v[i - 1] + temp) % M;
        // 0이면 답 증가
        if (v[i] == 0) cnt++;
        // 빈도수 증가
        c[v[i]]++;
    }

    // 조합 공식 사용
    // nCr r = 2인 경우 n(n-1) / 2
    // 조합 공식을 사용하는 이유
    // 구간 i ~ j 까지의 합은 누적합 v[j] - i[j - 1] 이므로
    // 나머지가 같은 2개의 원소를 고르면, 차에 의해 나머지가 소멸됨.
    // 따라서 나머지가 같은 구간의 조합을 구함
    for (int i = 0; i < M; i++) {
        if (c[i] > 1) cnt = cnt + ((c[i] * (c[i] - 1)) / 2);
    }
    
    cout << cnt << '\n';

    return 0;
}