#include <bits/stdc++.h>

using namespace std;

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<int> v(N);

    int start = INT_MIN, end = 0;

    for (int i = 0; i < N; i++) {
        cin >> v[i];
        if (start < v[i]) start = v[i];
        end += v[i];
    }
    
    while (start <= end) {
        int mid = (end + start) / 2;
        int sum = 0;
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (sum + v[i] > mid) {
                count++;
                sum = 0;
            }
            sum += v[i];
        }
        if (sum != 0) count++;
        if (count > M) start = mid + 1;
        else end = mid - 1;
    }

    cout << start << '\n';

    return 0;
}