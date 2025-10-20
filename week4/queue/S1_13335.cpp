#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 가속화
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // n : 다리를 건너는 트럭의 수, w : 다리의 길이, L : 다리의 최대 하중
    int n, w, L;
    cin >> n >> w >> L;

    // 지나갈 트럭의 무게 선입 선출이므로 큐로 선언 하여 입력
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        q.push(temp);
    }

    // 다리를 표현 길이 w이므로 w크기의 벡터 선언
    vector<int> bridge(w);

    int time = 0;
    
    while (!q.empty() || accumulate(bridge.begin(), bridge.end(), 0) > 0) {
        
        // 단위 시간 증가
        time++;
        bridge[w - 1] = 0; // 마지막 트럭 다리 벗어남
        bridge.insert(bridge.begin(), 0); // 모든 트럭 앞으로 한 칸 이동

        // 다리 위 트럭과 다음 차례 트럭의 무게를 하중이 버틸 수 있다면, 다리에 트럭 올리기
        if (!q.empty() && accumulate(bridge.begin(), bridge.end(), 0) + q.front() <= L) {
            bridge[0] = q.front(); // 트럭 올리고
            q.pop(); // 대기열에서 제외
        }
    }

    // 답안 출력
    cout << time << '\n';
    return 0;
}