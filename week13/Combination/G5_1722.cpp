#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 기본 자료형 선언
    vector<long long> F(21);
    vector<int> S(21);
    vector<bool> visited(21, false);

    // 순열 자리수 입력 받기
    int N;
    cin >> N;

    // 팩토리얼 구하기
    F[0] = 1;
    for (int i = 1; i <= N; i++) F[i] = F[i - 1] * i;

    // 질의 번호 입력 받기
    int Q;
    cin >> Q;


    long long K;

    // 1번 질의인 경우
    // K번 째 순열 찾는 문제
    if (Q == 1) {
        cin >> K;

        for (int i = 1; i <= N; i++) {
            for (int j = 1, count = 1; j <= N; j++) {
                // 이미 사용한 숫자는 건너 뛰기
                if (visited[j]) continue;

                // 해당 자리에 부합하면
                if (K <= count * F[N - i]) {
                    // 숫자 저장해주고
                    S[i] = j;
                    // 사용처리 해주고
                    visited[j] = true;
                    // K값 갱신
                    K -= ((count - 1) * F[N - i]);
                    break;
                }
                // 카운트 증가
                count ++;
            }
        }
        // 답안 출력
        for (int i = 1; i <= N; i++) cout << S[i] << ' ';
        cout << '\n';
    }

    // 2번 질의인 경우
    // 입력 순열이 몇 번째 등장하는지 출력
    else if (Q == 2) {
        // 초기값
        K = 1;

        // 순열 입력 받아주기
        for (int i = 1; i <= N; i++) {
            cin >> S[i];

            // 카운트 변수
            long long count = 0;

            // 입력 받은 숫자보다 작은 숫자들 중에서
            // 사용되지 않은 숫자 개수 카운트
            for (int j = 1; j < S[i]; j++) {
                if (visited[j] == false) count++;
            }

            // 해당 개수만큼 건너뛰기
            K += count * F[N - i];

            // 방문처리 해주기
            visited[S[i]] = true;
        }
        cout << K << '\n';
    }
    return 0;
}