#include <bits/stdc++.h>

using namespace std;
// 새로운 타입 지정
using edge = pair<int, int>;

// 그래프, 방문기록, 거리 벡터 선언
static vector<vector<edge>> graph;
static vector<bool> visited;
static vector<int> m_distance;
void BFS(int node); // 함수 선언


int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 입력받고, 벡터 사이즈 재설정
    int N;
    cin >> N;
    graph.resize(N + 1);

    // N번 반복
    for (int i = 0; i < N; i++) {
        // 정점 입력 받기
        int S;
        cin >> S;
        // -1이 나올때까지 무한반복
        while (true) {
            int e, v;   // 정점 번호와 그 거리 입력 받기
            cin >> e;
            if (e == -1) break; // 입력 종료 조건인 -1 나오면 break
            cin >> v; 
            graph[S].push_back(edge(e, v)); // 그래프에 입력하기
        }
    }

    // 거리 벡터 및 방문기록 벡터 초기화
    m_distance = vector<int>(N + 1, 0);
    visited = vector<bool>(N + 1, false);
    BFS(1); // 시작노드 부터 시작
    int max = 1;    // 가장 먼 점을 찾기 위한 임시변수
    for (int i = 2; i <= N; i++)    // 모든 정점을 순회하면서
        if (m_distance[max] < m_distance[i]) 
            max = i;    // 거리가 가장 먼 정점 찾기

    // 초기화
    fill(m_distance.begin(), m_distance.end(), 0);
    fill(visited.begin(), visited.end(), false);
    
    // 가장 먼점으로 부터 가장 먼 점을 찾기
    BFS(max);
    // 정렬해주고
    sort(m_distance.begin(), m_distance.end());
    // 가장 큰 값 출력
    cout << m_distance[N] << '\n';

    return 0;
}

// 너비우선탐색 알고리즘
void BFS(int node) {

    // 큐 선언
    queue<int> q;
    q.push(node);
    visited[node] = true;

    // 큐가 빌 때까지
    while (!q.empty()) {
        // 하나 꺼내서
        int now_node = q.front();
        q.pop();
        // 그 정점에 대해
        for (edge i : graph[now_node]) {
            // 방문한 적이 없다면
            if (!visited[i.first]) {
                visited[i.first] = true;    // 방문기록 남겨주고
                q.push(i.first);    // 다시 큐에 삽입
                // 거리 재설정
                m_distance[i.first] = m_distance[now_node] + i.second;
            }
        }
    }
}