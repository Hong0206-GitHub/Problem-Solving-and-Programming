#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 동전 종류 개수와 금액 입력 받기
    int N, K;
    cin >> N >> K;

    // 벡터에 저장하고, 역순 정렬
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    sort(v.begin(), v.end(), greater<>());

    // temp는 동전 선택시 선택한 금액,
    // count는 동전 선택 횟수
    int temp = 0, count = 0;
    int i = 0;

    // 원하는 금액에 도달할 때 까지
    while (temp != K) {
        // 초과되는 경우에는 값을 줄여야 하므로,
        // 인덱스 증가
        if (temp + v[i] > K) i++;
        else {
            // 아니면 temp 갱신하고, 동전 개수 1 증가
            temp += v[i];
            count++;
        }
    }

    // 답안 출력
    cout << count << '\n';
    return 0;
}