#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,O3,unroll-loops")
#pragma GCC target("avx,avx2,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define i128 __int128_t
#define endl "\n"

void primeFactorize(int N, vector<int> &primeFactors)
{
    while (!(N & 1))
        primeFactors.push_back(2), N >>= 1;
    for (int i{3}; i * i <= N; i += 2)
    {
        while (N % i == 0)
            primeFactors.push_back(i), N /= i;
    }
    if (N > 1) // N is prime
        primeFactors.push_back(N);
    sort(primeFactors.begin(), primeFactors.end());
}

void AllFactors(int N, vector<int> &allDivisors)
{
    vector<int> primeFactors;
    primeFactorize(N, primeFactors);
    for (const int &p : primeFactors)
    {
        int len = allDivisors.size();
        for (int i{}; i < len; i++)
            allDivisors.push_back(p * allDivisors[i]);

        set<int> distinctDivisors(allDivisors.begin(), allDivisors.end());
        allDivisors.clear();
        for (const int &it : distinctDivisors)
            allDivisors.push_back(it);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
    int t = 1;
    int N;
    cin >> t;
    while (t--)
    {
        cin >> N;
        vector<int> vc(N);
        for (int i = 0; i < N; ++i)
            cin >> vc[i];

        vector<int> allDivisors = {1};
        AllFactors(N, allDivisors);
        ll ans = -1;
        for (const int &d : allDivisors)
        {
            ll mx = LLONG_MIN, mn = LLONG_MAX;
            for (int i = 0; i < N; i += d)
            {
                ll sum = 0;
                for (int j = i; j < i + d; ++j)
                    sum += vc[j];

                mx = max(mx, sum);
                mn = min(mn, sum);
            }
            ans = max(ans, mx - mn);
        }
        cout << ans << '\n';
    }
    return 0;
}