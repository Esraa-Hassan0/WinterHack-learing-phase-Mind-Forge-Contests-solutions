#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
    int t = 1;
    ll N, Q;
    // cin >> t;
    while (t--)
    {

        cin >> N;
        if (N <= 2)
            return cout << (N == 1 ? "1\n1" : "1\n1 1"), 0;
        bitset<100001> isPrime; // Bitwise sieve
        isPrime.set();
        isPrime[0] = 0;
        isPrime[1] = 0;
        ll color{1};
        // ll maxColor{1};
        for (ll i{2}; i <= N + 1; i++)
        {
            color = 1;
            if (isPrime[i])
            {
                for (ll j = 2 * i; j <= N + 1; j += i)
                    isPrime[j] = 0;
            }
        }
        cout << 2 << endl;
        for (ll i{2}; i <= N + 1; i++)
            cout << (3 ^ (1 + isPrime[i])) << " ";
    }
    return 0;
}