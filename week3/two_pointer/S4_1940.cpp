#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력 저장 변수
    int N, M;
    cin >> N >> M;

    // 원소 저장할 벡터 선언
    vector<int> v(N);

    // 원소 저장
    for (int i = 0; i < N; i++) cin >> v[i];

    // 정렬
    sort(v.begin(), v.end());

    // 투포인터 선언
    int start = 0, end = N - 1;

    // 답안 변수
    int count = 0;

    // 유효한 범위 내에서
    // 크면 end 감소, 작으면 start증가
    // 같으면 답안 증가, end나 start 변경
    while (start < end) {
        int sum = v[start] + v[end];
        if (sum < M) start++;
        else if (sum > M) end--;
        else {
            count++;
            start++;
        }
    }
    
    // 답안 출력
    cout << count << '\n';

    return 0;
}