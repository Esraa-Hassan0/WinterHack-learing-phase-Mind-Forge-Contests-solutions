#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <map>
#include <regex>
#include <set>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <bitset>
#include <bit>
#include <stack>
// #include <bits/stdc++.h>
#define ll long long
// #define pi 3.141592653589793238462643383279
using namespace std;

// 3 3 3
// 1  001
// 2  010
// 3  011
// 4  100
ll __bit_ceil(ll n)
{
    ll s = 1;
    while (s < n)
        s <<= 1;
    return s;
};
ll __bit_floor(ll n)
{
    ll s = 1;
    while (s < n)
        s <<= 1;
    if (s == n)
        return s;
    return s / 2;
};

void KILL()
{
    ll n, sum{};
    cin >> n;
    ll *arr = new ll[n];
    vector<ll> l, r;
    for (ll i{}; i < n; i++)
        cin >> arr[i];
    for (ll i{1}; i < n; i++)
        arr[i] += arr[i - 1];
    string s;
    cin >> s;
    // reverse(s.begin(), s.end());
    for (ll i{0}; i < n; i++)
    {
        if (s[i] == 'L')
            l.push_back(i);
        else
            r.push_back(i);
    }
    for (ll i{0}; i < min(l.size(), r.size()); i++)
    {
        ll L = l[i], R = r[r.size() - i - 1];
        if (R > L)
            if (L - 1 >= 0)
                sum += arr[R] - arr[L - 1];
            else
                sum += arr[R];
        else
            break;
    }
    cout << sum;
    /* 1 2 3 4 5
         LRLRR*/
    // RRLRL
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll tt = 1;
    cin >> tt;

    for (ll i{}; i < tt; i++)
    {
        KILL();
        cout << endl;
    }

    return 0;
}