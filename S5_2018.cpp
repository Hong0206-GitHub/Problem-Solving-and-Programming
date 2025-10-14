#include <iostream>
using namespace std;

int main(void) {
    
    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 자연수 입력 받기
    int N;
    cin >> N;

    // 같은 위치의 투 포인터 선언
    int start = 1, end = 1;

    // 마지막 원소 하나만인 경우 미리 세기
    int count = 1;

    // 현재의 누적합
    int sum = 1;

    while (end != N) {
        // sum이 N보다 크면 start포인터 오른쪽으로 이동 및 sum 갱신
        if (sum > N) sum -= start++;
        // sum이 N보다 작으면 end포인터 오른쪽으로 이동 및 sum 갱신
        else if (sum < N) sum += ++end;
        // sum == N인 경우 카운터 증가 후 end 포인터 오른쪽으로 이동 및 sum 갱신
        else {
            count++;
            sum += ++end;
        }
    }

    // 답안 출력
    cout << count << '\n';

    return 0;
}