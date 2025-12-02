#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 문자열 입력 받기
    string str;
    cin >> str;

    // -로 구분된 숫자나 숫자+숫자 조합 넣을 벡터 선언
    vector<string> strv;

    // 임시 문자열 선언
    string temp = "";

    // 문자열의 각 문자를 순회하며
    for (char c : str) {

        // - 면 지금까지 모아온 문자열 벡터에 삽입
        if (c == '-') {
            strv.push_back(temp);
            temp = ""; // 임시 문자열 초기화
        }
        // 아니면 문자열 확장
        else {
            temp += c;
        }
    }

    // 마지막에 벡터에 삽입
    strv.push_back(temp);

    // 람다 함수
    auto sumString([](string str) {

        // 리턴할 총합 변수 선언
        int sum = 0;

        // 임시 문자열 선언
        string num = "";

        // 전체 문자열 순회하면서
        for (char c : str) {
            // + 만나면 sum에 누적합
            if (c == '+') {
                sum += stoi(num);
                num = "";    // 임시 문자열 초기화
            }
            // 아니면 문자열 확장
            else {
                num += c;
            }
        }

        // 마지막에 남은거 더해주고
        sum += stoi(num);
        // 리턴
        return sum;
    });

    // 답안 변수
    int answer = 0;
    
    // 첫 번째 덩어리부터 답안 변수에 누적
    answer += sumString(strv[0]);

    // 나머지 덩어리들은 빼주면 됨
    for (size_t i = 1; i < strv.size(); i++) {
        answer -= sumString(strv[i]);
    }

    // 답안 출력
    cout << answer << '\n';
    return 0;

}