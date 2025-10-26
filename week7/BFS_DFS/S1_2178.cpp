#include <bits/stdc++.h>

using namespace std;

// 너비 우선 탐색 알고리즘 사용
void BFS(vector<vector<int>> &graph, vector<vector<bool>> &visited, int i, int j);
// 이동할 위치 델타
static int dx[] = {0, 1, 0, -1};    
static int dy[] = {1, 0, -1, 0};

static int N, M;


int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 이차원 행, 열 크기 입력 받기
    cin >> N >> M;

    // 2차원 벡터 채우기
    vector<vector<int>> graph(N);
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    // 2차원 벡터 채우기
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (size_t j = 0; j < str.size(); j++) {
            graph[i].push_back((int)(str[j]) - '0');
        }
    }

    // 너비 우선 탐색 알고리즘 호출
    BFS(graph, visited, 0, 0);
    // 도착지에 최단거리가 저장되어있으므로, 그 값을 출력
    cout << graph[N-1][M-1] << '\n';

    return 0;
}

void BFS(vector<vector<int>> &graph, vector<vector<bool>> &visited, int i, int j) {
    // 너비 우선탐색 용 큐 선언
    queue<pair<int, int>> q;
    q.push({i, j});
    
    // 큐가 빌 때까지 반복
    while (!q.empty()) {
        // 임시 배열
        int now[2];
        // x, y좌표 각각 저장
        now[0] = q.front().first;
        now[1] = q.front().second;
        q.pop();    // 큐에서 꺼내기
        // 방문처리 해주고
        visited[now[0]][now[1]] = true;
        
        // 상하좌우 모두 탐색
        for (int k = 0; k < 4; k++) {
            // 델타 값에 따라 이동한 결과 저장
            int x = now[0] + dx[k];
            int y = now[1] + dy[k];
            // 각 좌표가 0보다 크거나 같으면서, N, M보다 작으면
            // 이동 할 수 있음
            if (x >= 0 && y >= 0 && x < N && y < M) {
                // 0이 아니면서 방문하지 않은 곳이라면,
                // 즉, 갈 수 있는 곳이면서 방문 하지 않은 곳이라면,
                if (graph[x][y] != 0 && !visited[x][y]) {
                    visited[x][y] = true;   // 방문처리 해주고
                    graph[x][y] = graph[now[0]][now[1]] + 1; // 거리 갱신
                    q.push({x, y}); // 해당 좌표 큐에 삽입
                }
            }
        }
    }
}