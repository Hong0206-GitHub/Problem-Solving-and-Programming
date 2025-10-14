#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력 변수
    int S, P;
    cin >> S >> P;
    
    // 문자열
    string str;
    cin >> str;

    // 조건과 문자열에서 각 문자 나오는 수 저장할 벡터
    vector<int> input(4);
    vector<int> check(4);

    // 조건 입력받기
    for (int i = 0; i < 4; i++) cin >> input[i];

    // 투포인터
    int start = 0, end = P - 1;

    // 처음 윈도우에서의 문자 수 저장
    for (int i = start; i <= end; i++) {
        if (str[i] == 'A') check[0]++;
        else if (str[i] == 'C') check[1]++;
        else if (str[i] == 'G') check[2]++;
        else check[3]++;
    }

    // 답안 저장용 변수
    int count = 0;
    
    // 유효한 범위에 한해
    while (end < S) {
        // 입력된 조건과 문자열 윈도우의 상태 비교
        bool ck = true;
        for (int i = 0; i < 4; i++) {
            if (input[i] > check[i]) {
                ck = false;
                break;
            }
        }
        // 케이스 통과시 카운트 증가
        if (ck) count++;

        // 포인터 이동
        start++, end++;

        // 이동한 포인터들에 맞춰
        // 문자 개수 갱신
        if (str[start - 1] == 'A') check[0]--;
        else if (str[start - 1] == 'C') check[1]--;
        else if (str[start - 1] == 'G') check[2]--;
        else check[3]--;
        
        if (str[end] == 'A') check[0]++;
        else if (str[end] == 'C') check[1]++;
        else if (str[end] == 'G') check[2]++;
        else check[3]++;
    }

    // 답안 출력
    cout << count << '\n';

    return 0;
}
