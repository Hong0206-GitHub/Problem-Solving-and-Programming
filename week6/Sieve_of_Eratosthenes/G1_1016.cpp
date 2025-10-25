#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    ll min, max;
    cin >> min >> max;
    ll size = max - min + 1;
    vector<bool> v(size);

    for (ll i = 2; i * i <= max; i++) {
        ll pow = i * i;
        ll start_index = min / pow;
    
        if (min % pow != 0) start_index++;
        for (ll j = start_index; pow * j <= max; j++) {
            v[(int)((j * pow) - min)] = true;
        }
    
    }

    int count = 0;
    for (int i = 0; i <= max - min; i++) {
        if (!v[i]) count++;
    }

    cout << count << '\n';

    return 0;
}