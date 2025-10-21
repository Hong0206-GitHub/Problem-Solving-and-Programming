#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// 하.. 큰 값에 , 쓰면 안됨
const ll mod = 1e9 + 7;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 테스트 케이스 입력 받기
    int T;
    cin >> T;

    // 미리 변수 선언
    int N;
    ll temp;
    ll answer;

    // 테스트 케이스만큼 반복
    while (T--) {
        
        // 최소힙 사용
        priority_queue<ll, vector<ll>, greater<ll>> min_heap;
        
        // 원소 개수 입력받기
        cin >> N;

        // 원소 개수 만큼 원소를 최소힙에 저장
        for (int i = 0; i < N; i++) {
            cin >> temp;
            min_heap.push(temp);
        }

        // 곱셈 연산 해야하므로 1로 초기화
        answer = 1;

        // 힙에서 2개의 값을 꺼내야 하기위한 조건
        while (min_heap.size() > 1) {
            ll x, y; // 힙에서 꺼낸 값 저장 변수
            x = min_heap.top(); min_heap.pop();
            y = min_heap.top(); min_heap.pop();
            ll xy = (x * y) % mod; // 곱셈 결과
            answer = (answer * xy) % mod; // 답안 갱신
            min_heap.push(x * y); // 힙에 넣을 때 모듈러 연산을 하면 우선순위가 바뀔 위험이 있음
        }

        // 답안 출력(1의 경우 위 while문을 진입못하고 그대로 1출력)
        cout << answer << '\n';        
    }

    return 0;

}