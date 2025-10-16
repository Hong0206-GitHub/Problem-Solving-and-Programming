#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 전체 원소 수 입력
    int n;
    cin >> n;

    // 스택과 결과 저잘할 벡터 선언
    stack<int> s;
    vector<char> v;

    // 앞으로 집어넣어야 할 값 선언
    int start = 1;

    // 조건은 참으로 가정
    bool check = true;

    // 모든 원소에 대해 반복
    while (n--) {
        // 원소 입력 받기
        int temp;
        cin >> temp;

        // 초기값이나, 스택의 탑이 입력값보다 작다면
        while (s.empty() || s.top() < temp) {
            s.push(start++); // 스택에 집어넣고
            v.push_back('+'); // 푸시했으므로, + 벡터에 저장
        }

        // 탑이 입력값과 같을 것이기 때문에
        if (s.top() == temp) {
            s.pop();    // 팝해주고
            v.push_back('-'); // 벡터에 출력값 저장
        }
        // 같지 않는 경우는 조건에 부합하지 않는 상황
        else {
            check = false; // 결과 출력 분기 변수 거짓으로 갱신
            break; // 반복문 탈출
        }
        
    }

    // 결과 출력
    if (check) for (char x : v) cout << x << '\n';
    else cout << "NO\n";

    return 0;
}
