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
    ll N;
    cin >> N;
    ll *arr = new ll[N];
    for (ll i{}; i < N; i++)
        cin >> arr[i];

    int ans;
    for (int k{1}; k < 60; k++)
    {
        set<ll> mod;
        for (int i{}; i < N; i++)
            mod.insert(arr[i] & ((1LL << k) - 1));

        if (mod.size() == 2)
        {
            ans = k;
            break;
        }
    }
    cout << (1LL << ans);
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