#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력 개수 입력받기
    int N;
    cin >> N;

    // 최대힙과 최소힙 선언
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;

    // 입력 값 저장할 변수
    int temp;
    while (N--) {
        // 입력 받기
        cin >> temp;

        // 항상 최대힙의 크기가 크거나 같아야함
        if (l.size() <= r.size()) l.push(temp);
        else r.push(temp);

        // 최대힙의 top() 값은 중간값이됨
        // 만약 최대 힙의 top이 최소힙의 top보다 크다면, 두 힙의 top값을 swap하여
        // 작은 중간값을 출력해야함
        if (r.size() && l.top() > r.top()) {
            l.push(r.top());
            r.pop();
            r.push(l.top());
            l.pop();
        }
        // 답안 출력
        cout << l.top() << '\n';
    }

    return 0;
}