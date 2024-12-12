#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,O3,unroll-loops")
#pragma GCC target("avx,avx2,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define i128 __int128_t
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
    ll N, Q, m;
    // cin >> t;
    while (t--)
    {
        cin >> N;
        vector<int> prices(N);
        for (int i{}; i < N; i++)
            cin >> prices[i];

        sort(prices.begin(), prices.end());

        cin >> Q;
        while (Q--)
        {
            cin >> m;
            auto pos = upper_bound(prices.begin(), prices.end(), m);
            int cnt = pos - prices.begin();
            cout << cnt << endl;
        }
    }
    return 0;
}