#include <iostream>
#include <string>
using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 문자열 길이 입력
    int N;
    cin >> N;

    // 문자열 입력
    string str;
    cin >> str;

    // 답안 저장할 변수
    int answer = 0;

    // char형 정수로 변환하여 누적 합
    for (size_t i = 0; i < N; i++)
        answer += str[i] - '0';

    // 결과 출력
    cout << answer << '\n';

    return 0;
}