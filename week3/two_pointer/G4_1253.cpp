#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 원소 개수 입력
    int N;
    cin >> N;

    // 원소 채우기
    vector<ll> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    // 정렬
    sort(v.begin(), v.end());

    // 답안 저장용 변수
    int count = 0;

    // 모든 원소에 대해서
    for (int i = 0; i < N; i++) {

        // 원소를 순차적으로 좋은수인지 판단
        ll good = v[i];
    
        // 투 포인터 선언
        int start = 0, end = N - 1;

        // 유효한 범위에 대해
        while (start < end) {
            // 좋은 수인 경우
            if (v[start] + v[end] == good) {
                // 좋은 수는 서로 다른 두 수의 합이므로
                // 위치가 같아서는 안됨 (위치가 다르면 같은수여도 다른수라고 명시되어있음)
                // 위치가 다른 수라면 좋은 수 이므로 카운터 증가 후 다음 루프
                if (start != i && end != i) {
                    count++;
                    break;
                } 
                // 좋은 수와 같은 위치를 가리키는 포인터 이동
                else if (start == i) start++;
                else end--;   
            }
            // 조건에 따라 포인터 이동
            else if (v[start] + v[end] < good) start++;
            else end--;
        }

    }
    // 답안 출력
    cout << count << '\n';

    return 0;
}
