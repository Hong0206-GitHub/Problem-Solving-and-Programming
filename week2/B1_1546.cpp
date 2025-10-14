#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 원소 개수 입력받기
    int N;
    cin >> N;

    // 벡터 선언
    vector<int> v(N);

    // 총합
    double sum = 0;

    // 벡터에 저장하면서 총합 구하기
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        v[i] = temp;
        sum += temp;
    }

    // 최대값 구하기
    int max = *max_element(v.begin(), v.end());

    // 문제에서 요구하는 답안 도출
    cout << (sum * 100 / max / N) << '\n';

    return 0;
}