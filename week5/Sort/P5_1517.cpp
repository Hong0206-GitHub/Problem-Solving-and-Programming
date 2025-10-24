#include <bits/stdc++.h>

using namespace std;

// 답안 저장용 전역 변수 선언
long long answer = 0;

// 병합과정
// 버블소트는 붙어있는 두 값을 비교해서 오른쪽 값이 작으면 둘의 순서를 변경하는 정렬임
// 따라서 병합과정에서 2번째 배열의 값이 먼저 정렬 배열에 삽입된다면, 왼쪽배열의 개수만큼의
// 버블 과정이 일어난 것으로, 계산할 수 있음
void merge(vector<int> &v, int start, int mid, int end) {
    int i = start, j = mid + 1, k = 0;
    vector<int> sorted(end - start + 1);

    while (i <= mid && j <= end) {
        if (v[i] <= v[j]) sorted[k++] = v[i++];
        else {
            answer += (mid - i + 1);
            sorted[k++] = v[j++];
        }
    }

    while (i <= mid) sorted[k++] = v[i++];
    while (j <= end) sorted[k++] = v[j++];

    for (int i = start, k = 0; i <= end; i++, k++) v[i] = sorted[k];
}

// 병합 정렬
void merge_sort(vector<int> &v, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(v, start, mid);
        merge_sort(v, mid + 1, end);
        merge(v, start, mid, end);
    }
}

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 원소 개수 입력 받기
    int N;
    cin >> N;
    vector<int> v(N);
    // 원소 입력 받아서 벡터에 집어넣기
    for (int i = 0; i < N; i++) cin >> v[i];
    merge_sort(v, 0, N - 1);    // 단순 함수 호출용

    // 답안 출력
    cout << answer << '\n';

    return 0;
}