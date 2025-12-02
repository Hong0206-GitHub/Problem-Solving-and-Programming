#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 개수 입력 받기
    int N;
    cin >> N;

    // 최소힙 선언
    priority_queue<int, vector<int>, greater<int>> pq;

    // 입력 값 최소힙에 삽입
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        pq.push(temp);
    }

    // 답안 저장 변수
    int answer = 0;

    // 큐에 원소가 하나 남을 때 까지 반복
    while (pq.size() != 1) {

        // 두 개 꺼내서 
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        // 더한 값을 답안에 추가시켜주고,
        answer += a + b;

        // 큐에 삽입
        pq.push(a + b);
    }

    // 답안 출력
    cout << answer << '\n';
    return 0;
}