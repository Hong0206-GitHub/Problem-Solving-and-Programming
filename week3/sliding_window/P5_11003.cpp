#include <iostream>
#include <deque>

using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 원소개수 및 윈도우 크기 입력
    int N, L;
    cin >> N >> L;

    // 덱 선언
    deque<pair<int, int>> d;

    // 모든 원소에 대해
    for (int i = 1; i <= N; i++) {
        int val;
        cin >> val;

        // 덱이 비어있는 초기는 무조건 푸시백
        if (i == 1) d.push_back({i, val});
        else {
            // 집어넣을 원소가 덱의 마지막 원소보다 작으면 푸시백
            if (d.back().second <= val) {
                d.push_back({i, val});
            }
            // 아니라면, 덱이 비지않을 때까지 팝백
            else {
                while (!d.empty() && d.back().second > val)
                    d.pop_back();
                // 후 푸시백
                d.push_back({i, val});
            }

            // 윈도우 크기 조건에 부합하여야하므로
            // 윈도우 크기보다 커지면 앞의 원소 팝
            if (d.size() > 1 && d.back().first - d.front().first >= L) {
                d.pop_front();
            }
        }
        // 결과 출력
        cout << d.front().second << ' ';
    }
    cout << '\n';

    return 0;
}