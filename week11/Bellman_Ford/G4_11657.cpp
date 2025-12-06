#include <bits/stdc++.h>

using namespace std;

struct edge {int start, end, time;};

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 정점 개수, 간선 개수 입력 받기
    int N, M;
    cin >> N >> M;

    // 기본 자료형 선언 및 초기화
    vector<edge> mlist;
    vector<long long> mtime(N + 1, LONG_LONG_MAX);

    // 그래프 채우기
    for (int i = 0; i < M; i++) {
        int start, end, time;
        cin >> start >> end >> time;

        mlist.push_back({start, end, time});
    }

    // 시작 정점 1로 하여 벨만포드 알고리즘 수행
    mtime[1] = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            edge medge = mlist[j];

            int start = medge.start;
            int end = medge.end;
            int time = medge.time;

            // 값 갱신이 가능한 경우 갱신
            if (mtime[start] != LONG_LONG_MAX && mtime[end] > mtime[start] + time) {
                mtime[end] = mtime[start] + time;
            }
        }
    }

    // 음수 사이클 탐색을 위해 한 번 더 수행
    bool mCycle = false;
    for (int i = 0; i < M; i++) {
        edge medge = mlist[i];
        
        int start = medge.start;
        int end = medge.end;
        int time = medge.time;

        // 갱신이 가능한 경우, 음수 사이클이 존재하는 경우임
        if (mtime[start] != LONG_LONG_MAX && mtime[end] > mtime[start] + time) {
            mCycle = true;
            break;
        }
    }

    // 답안 출력
    if (mCycle) cout << -1 << '\n';
    else {
        for (int i = 2; i <= N; i++) {
            if (mtime[i] != LONG_LONG_MAX) cout << mtime[i] << '\n';
            else cout << -1 << '\n';
        }
    }

    return 0;
}