#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 값 입력받기
    int N, M;
    cin >> N >> M;
    vector<int> v(N);

    // 이분탐색에 사용할 시작값과 끝값
    // 여기서 시작값은 입력값 중에 최댓값, 끝값은 입력값의 총합
    int start = INT_MIN, end = 0;

    // 입력 받고 벡터에 넣으면서 시작값과, 끝값 설정
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        if (start < v[i]) start = v[i];
        end += v[i];
    }
    
    // 이분탐색
    while (start <= end) {
        // 중간값 설정
        int mid = (end + start) / 2;
        // 지금까지 넣은 강의 길이
        int sum = 0;
        // 사용한 블루레이 갯수
        int count = 0;

        // 모든 원소에 대해
        for (int i = 0; i < N; i++) {
            // sum 이 중앙값 보다 클 경우, 다른 블루레이를 사용하므로,
            // count증가와 sum 초기화
            if (sum + v[i] > mid) {
                count++;
                sum = 0;
            }
            // sum 에 강의 넣기
            sum += v[i];
        }
        // 강의가 남아있는 경우, 블루레이를 하나 더 사용해야하므로 + 1
        if (sum != 0) count++;
        // 사용한 블루레이 개수가 M보다 크다면,
        // 더 길게 저장할 수 있는 블루레이를 사용해아함
        if (count > M) start = mid + 1;

        // 그렇지 않으면 더 짧게 저장 가능한 블루레이를 사용할 수 있음
        else end = mid - 1;
    }

    // 답안 출력
    cout << start << '\n';

    return 0;
}