#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // N*N의 표와 N번째 큰 수를 출력할 때 사용되는 변수
    int N;
    cin >> N;

    // 메모리 사용량 고려 최소힙으로 구현
    priority_queue<int, vector<int>, greater<int>> pq;

    // N*N 번 반복하되
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int temp;
            cin >> temp;
            pq.push(temp);
            // N보다 클 경우 팝해줌
            // 최소힙이므로, 큰값 N개는 유지됨
            // 즉 최종 큐의 탑에는 N번째로 큰 수가 남아있게 됨
            if (pq.size() > N) pq.pop();
        }
    }

    cout << pq.top() << '\n';

    return 0;
}