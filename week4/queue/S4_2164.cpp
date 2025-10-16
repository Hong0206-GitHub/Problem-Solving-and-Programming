#include <iostream>
#include <queue>

using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 자연수 N 입력받기
    int N;
    cin >> N;

    // 큐 선언
    queue<int> q;

    // 1~N 큐에 삽입
    for (int i = 1; i <= N; i++) q.push(i);

    // 큐에 원소가 하나가 남을 때 까지
    while (q.size() > 1) {
        q.pop(); // 앞 카드 버리기
        int temp = q.front(); // 그 다음카드 참조
        q.pop(); // 빼서
        q.push(temp); // 맨 뒤에 삽입
    }

    // 답안 출력
    cout << q.front() << '\n';

    return 0;
}
