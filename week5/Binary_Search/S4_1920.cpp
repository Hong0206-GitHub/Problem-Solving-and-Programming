#include <bits/stdc++.h>

using namespace std;

// 이진 탐색, 벡터는 참조값으로 전달해야 시간초과가 안남
int binary_search(vector<int> &v, int start, int end, int key) {
    // start가 end보다 작거나 같을 동안
    while (start <= end) {
        // 중앙 인덱스 갱신
        int mid = (start + end) / 2;
        // 중앙값이 key값과 같은 경우 해당 인덱스 리턴
        if (v[mid] == key) return mid;
        // key가 더 큰 경우 start 인덱스 갱신
        else if (v[mid] < key) start = mid + 1;
        // key가 더 작으 경우 end 인덱스 갱신
        else end = mid - 1;
    }

    // 결국 못 찾았을 경우 -1 리턴
    return -1;
}

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 원소 개수 입력 받고 해당 크기만큼의 벡터 선언
    int N;
    cin >> N;
    vector<int> v(N);
    
    // 원소 입력받아 벡터에 저장
    for (int i = 0; i < N; i++)  cin >> v[i];

    // 이진 탐색을 위한 정렬
    sort(v.begin(), v.end());

    // 테스트 케이스 입력
    int M;
    cin >> M;

    // 테스트 케이스 동안
    while (M--) {
        // 찾을 값 입력 받고
        int key;
        cin >> key;

        // 이진탐색 수행해서 -1이면 못찾은 것으로 0 출력, 아니면 1 출력
        if (binary_search(v, 0, N - 1, key) == -1) cout << 0 << '\n';
        else cout << 1 << '\n';
    }

    return 0;
}