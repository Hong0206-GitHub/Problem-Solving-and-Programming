#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 회의 개수 입력 받기
    int N;
    cin >> N;

    // 회의 정보 저장할 벡터 선언
    vector<pair<int, int>> v(N);

    // 시작시간, 종료시간 으로 벡터에 저장
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }

    // 정렬 수행
    // 종료시간이 같은 경우 시작시간이 짧은게 앞에 오도록
    // 종료시간이 다를 경우 종료시간이 짧은게 앞에 오도록
    sort(v.begin(), v.end(), [](auto &a, auto &b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });

    // 현재 진행중인 회의의 종료시간 저장 변수
    int endTime = 0;

    // 회의 개수 저장 변수
    int count = 0;

    // 모든 회의에 대해서
    for (auto &c : v) {
        // 회의 시작시간이 종료시간보다 크거나 같은 경우
        // 회의를 시작할 수 있음
        if (c.first >= endTime) {
            count++;    // 카운트 1 증가시켜주고
            endTime = c.second; // 종료시간 업데이트
        }
    }

    // 답안 출력
    cout << count << '\n';

    return 0;
}