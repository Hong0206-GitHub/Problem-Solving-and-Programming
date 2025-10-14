#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 원소 개수 입력 받기
    int N;
    cin >> N;

    // 벡터 선언
    vector<int> v(N);

    // 원소 벡터에 집어넣기
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        v[i] = temp;
    }

    // 오름차순 정렬
    sort(v.begin(), v.end());

    // 벡터에 저장된 순서대로 출력
    for (int x : v) cout << x << '\n';
    
    return 0;
}
