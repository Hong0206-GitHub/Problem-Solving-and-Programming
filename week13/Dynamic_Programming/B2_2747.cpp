#include <bits/stdc++.h>

using namespace std;

// look-up 테이블
vector<int> v(46, -1);

// 재귀 함수로 구현
int fibo(int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else {
        if (v[n] == -1)
            // DP 로 구현
            v[n] = fibo(n - 1) + fibo(n - 2);
        return v[n];
    }
}

int main(void) {
    
    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 값 입력 받기
    int N;
    cin >> N;

    // 답안 출력
    cout << fibo(N) << '\n';

    return 0;
}