#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void) {
    
    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 원소 개수 입력
    int N;
    cin >> N;

    // 원본 벡터 저장
    vector<int> v(N);
    
    // 스택 선언
    stack<int> s;
    
    // 답안 저장용 벡터 선언
    vector<int> answer(N, -1);

    // 원소 입력 받기
    for (int i = 0; i < N; i++) cin >> v[i];

    // 초기값 넣기
    s.push(0);

    // 이후 2번째 원소부터
    for (int i = 1; i < N; i++) {
        // 2번째 원소의 값
        int k = v[i];

        // 오큰수가 아니면, 스택에 인덱스 푸시
        if (k < v[s.top()]) {
            s.push(i);
        }
        // 오큰수의 경우
        else {
            // 스택에 저장되어있는 값들과 비교해서 조건에 부합하면
            // 같은 오큰수를 가짐
            while (!s.empty() && k > v[s.top()]) {
                int idx = s.top();
                answer[idx] = v[i];
                s.pop();
            }
            // 오큰수 해당 값도 스택에 푸시
            s.push(i);
        }
    }

    // 답안 출력
    for (int x : answer) cout << x << ' ';
    cout << '\n';

    return 0;
}