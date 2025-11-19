#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 건물 개수 입력 받기
    int N;
    cin >> N;

    // 원본 저장 벡터, 진입차수 저장 벡터, 답안 저장 벡터, 자기 자신 짓는데 걸리는 시간 저장 벡터 선언
    vector<vector<int>> graph(N + 1);
    vector<int> indegree(N + 1);
    vector<int> answer(N + 1);
    vector<int> time(N + 1);

    // 입력 값 저장
    for (int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;

        time[i] = temp;
        
        while (true) {
            cin >> temp;
            if (temp == -1) break;
            graph[temp].push_back(i);
            indegree[i]++;
        }
    }

    // 위상정렬을 위한 큐 선언
    queue<int> q;

    // 진입 차수 0인 노드들 큐에 삽입
    for (int i = 1; i <= N; i++) 
        if (indegree[i] == 0) q.push(i);

    // 큐가 빌 때 까지 반복
    while (!q.empty()) {
        int now = q.front();
        q.pop();

        // 큐에서 꺼낸 것과 연결된 것들에 대해
        for (int next : graph[now]) {
            indegree[next]--;   // 진입차수 낮추고,
            // 건물 시간은 모든 선행 건물들의 건설 완료 시간 중 최댓값임
            answer[next] = max(answer[next], answer[now] + time[now]);
            if (indegree[next] == 0) q.push(next);  // 진입차수 0인것들 다시 큐에 삽입
        }
    }

    // 답안 출력, 자기 자신을 짓는 시간 포함해야 함.
    for (int i = 1; i <= N; i++)
        cout << answer[i] + time[i] << '\n';

    return 0;
}