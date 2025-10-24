#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll SIZE = 10000001;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 소수인지 아닌지 저장하는 벡터 선언
    vector<bool> v(SIZE, true);
    v[0] = false;   // 0은 소수가 아님
    v[1] = false;   // 1은 소수가 아님

    // 에라토스테네스의 체 알고리즘
    for (ll i = 2; i * i <= SIZE - 1; i++) 
        if (v[i])
            for (ll j = i * i; j <= SIZE - 1; j += i)
                v[j] = false;
    
    // 입력 받기
    int N;
    cin >> N;

    // 문제에서 제시된 범위의 모든 소수에 대해
    for (ll i = N; i <= SIZE - 1; i++) {
        // 소수면
        if (v[i]) {
            // string 타입으로 형 변환
            string str = to_string(i);
            // 임시 벡터 선언
            vector<char> temp(str.size());
            int j = 0; // 벡터에 저장할 인덱스 번호
            // 역순으로 저장
            for (int i = str.size() - 1; i >= 0; i--) {
                temp[j++] = str[i];
            }

            // 분기 확인용 변수
            bool check = true;

            // 전체가 동일한 문자를 가지고 있는지 판단
            for (size_t i = 0; i < str.size(); i++) {
                if (temp[i] != str.at(i)) {
                    check = false;
                    break;
                } 
            }
            // for문을 무사히 돌았으면 그 수가 최소값이므로 출력후 종료
            if (check) {
                cout << i << '\n';
                break;
            }
            // for문 안의 if문에 들어갔으면 팰린드롬이 아니므로, 다음으로 넘어감
            else continue;
        }
    }

    return 0;
}