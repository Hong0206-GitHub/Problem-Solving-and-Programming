#include <iostream>
#include <vector>
using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 원소 개수 및 테스트 케이스 횟수 입력
    int N, M;
    cin >> N >> M;

    // 원본 배열과 누적 합 배열 선언
    vector<int> v(N);
    vector<int> sum(N + 1);
    
    // 원본 배열 채움과 동시에 합 배열 계산
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        v[i] = temp;
        sum[i + 1] = sum[i] + v[i];
    }

    // 테스트 케이스만큼 구간 합 구하기
    while (M--) {
        int i, j;
        cin >> i >> j;
        cout << (sum[j] - sum[i - 1]) << '\n';
    }

    return 0;
}
