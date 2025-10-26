#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    while (a % b != 0) {
        ll temp = a % b;
        a = b;
        b = temp;
    }

    return b;
}

vector<ll> euclid(ll a, ll b) {
    vector<ll> v(2);
    if (b == 0) { 
        v[0] = 1;
        v[1]= 0;
        return v;
    }

    ll q = a / b;
    vector<ll> vt = euclid(b, a % b);
    v[0] = vt[1];
    v[1] = vt[0] - vt[1] * q;
    return v;
}

int main(void) {

    ios::sync_with_stdio(false), cin.tie(NULL);

    ll A, B, C;
    cin >> A >> B >> C;

    ll g = gcd(A, B);

    if (C % g != 0) {
        cout << -1 << '\n';
        return 0;
    }
    else {
        ll mok = (ll)(C / g);
        vector<ll> v = euclid(A, B);
        cout << v[0] * mok << ' ' << v[1] * mok << '\n';
    }

    return 0;
}