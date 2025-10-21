#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 최소힙 선언
    priority_queue<int, vector<int>, greater<int>> pq;

    // 입력값 개수 입력받기
    int N;
    cin >> N;

    // N만큼 반복
    while (N--) {

        // 입력 값 저장
        int x;
        cin >> x;

        // 0이면 힙이 비어있으면 0 출력, 아니면 힙의 최상단 출력 후 팝
        if (x == 0) {
            if (pq.empty()) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        // 0이 아니면 힙에 푸시
        else pq.push(x);
    }

    return 0;
}