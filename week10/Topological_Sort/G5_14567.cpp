#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 입력값 저장
    int N, M;
    cin >> N >> M;

    // 저장 자료형 선언
    vector<vector<int>> graph(N + 1);
    vector<int> indegree(N + 1);

    // 그래프 채우기
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        indegree[b]++;
    }

    // 진입차수 0인 것들 모두 큐에 삽입
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    // 답안 저장 벡터
    vector<int> result(N + 1, 1);

    // 큐가 빌 때까지 반복
    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int next : graph[now]) {
            // 진입차수가 0이 된 것들 큐에 삽입
            if (--indegree[next] == 0) q.push(next);

            // 선수 과목들의 학기 중 최댓값 + 1
            result[next] = max(result[next], result[now] + 1);
        }
    }

    // 답안 출력
    for (int i = 1; i <= N; i++) cout << result[i] << ' ';
    cout << '\n';

    return 0;
}