#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 학생 수 및 비교횟수 입력 받기
    int N, M;
    cin >> N >> M;

    // 위상정렬 알고리즘 자료형들 선언
    vector<int> indegree(N + 1);
    vector<vector<int>> graph(N + 1);

    // 입력 값에 따라 진입차수와 원본 저장
    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        indegree[e]++;
        graph[s].push_back(e);
    }

    // 위상정렬을 위한 큐 선언
    queue<int> q;

    // 진입차수가 0인 노드들 큐에 삽입
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    // 큐가 빌 때까지
    while (!q.empty()) {
        int now = q.front();
        q.pop(); // 하나 꺼내와서
        
        cout << now << ' '; // 출력하고

        // 그 노드가 가리키는 것들에 대해
        for (int next : graph[now]) {
            indegree[next]--;   // 진입 차수 하나 빼주고,
            if (indegree[next] == 0) q.push(next);  // 진입차수가 0이면 다시 큐에 삽입을 반복
        }
    }
    cout << '\n';   // 답안 보정용

    return 0;
}