#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 입력값 저장
    int N, M;
    cin >> N >> M;

    // 기본 자료형 선언
    vector<vector<int>> graph(N + 1);
    vector<int> indegree(N + 1);

    // 횟수만큼 반복
    while (M--) {

        int temp;
        cin >> temp;

        // 임시 벡터에 먼저 값을 저장한 뒤에
        vector<int> order(temp);
        for (int i = 0; i < temp; i++) cin >> order[i];

        // 그래프 채우기
        for (int i = 0; i < temp - 1; i++) {
            int a = order[i];
            int b = order[i + 1];

            graph[a].push_back(b);
            indegree[b]++;
        }
    }

    // 큐 선언해서 진입차수 0인 것들 큐에 넣기
    queue<int> q;
    for (int i = 1; i <= N; i++)
        if (indegree[i] == 0) q.push(i);

    // 답안 저장 벡터 선언
    vector<int> answer;

    // 큐가 빌 때까지
    while (!q.empty()) {
        // 앞에거 하나 꺼내서
        int now = q.front();
        q.pop();

        // 저장 벡터에 집어넣고
        answer.push_back(now);

        // 진입차수 1 줄이고, 진입차수가 0이 된 것들 큐에 삽입
        for (int next : graph[now]) {
            if (--indegree[next] == 0) q.push(next);
        }
    }

    // 답안 벡터 사이즈와 정점 수가 다르면 사이클이 생겼다는 뜻
    if (answer.size() != N) {
        cout << "0\n";  // 0 출력
    } 
    
    // 아니면 정상
    else {
        // 답안 출력
        for (int i : answer) {
            cout << i << '\n';
        }
    }

    return 0;
}