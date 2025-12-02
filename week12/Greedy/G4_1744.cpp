#include <bits/stdc++.h>

using namespace std;

int main(void) {
    
    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 숫자 개수 입력 받기
    int N;
    cin >> N;

    // 최대힙, 최소힙, 1을 저장할 자료형 선언
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    vector<int> one;

    for (int i = 0; i < N; i++) {
        // 값 입력 받아서
        int temp;
        cin >> temp;

        // 1이면 1용 벡터에
        if (temp == 1)
            one.push_back(temp);
        // 1을 제외한 양수면 최대힙에
        else if (temp > 1)
            max_heap.push(temp);
        // 0이나 음수인 경우 최소힙에 푸시
        else
            min_heap.push(temp);
    }

    // 답안 저장용 변수
    int answer = 0;

    // 최대힙에서 2개 꺼낼 수 있을 때까지
    while (max_heap.size() > 1) {

        // 2개 꺼내서
        int a = max_heap.top();
        max_heap.pop();
        int b = max_heap.top();
        max_heap.pop();

        // 곱해서 더함
        answer += a * b;
    }

    // 최소힙에서 2개 꺼낼 수 있을 때 까지
    while (min_heap.size() > 1) {
        // 2개 꺼내서
        int a = min_heap.top();
        min_heap.pop();
        int b = min_heap.top();
        min_heap.pop();

        // 곱해서 더함
        answer += a * b;
    }

    // 1은 그냥 더해줌
    answer += one.size();

    // 비어있지 않은 경우, 사이즈는 1임이 자명하므로,
    // 그냥 최상단 값 더해줌
    if (!max_heap.empty()) answer += max_heap.top();
    if (!min_heap.empty()) answer += min_heap.top();
    
    // 답안 출력
    cout << answer << '\n';
    return 0;

}