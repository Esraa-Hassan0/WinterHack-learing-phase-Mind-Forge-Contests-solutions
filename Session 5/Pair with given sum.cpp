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
    int t = 1, K, N;
    // cin >> t;
    while (t--)
    {
        ll N, x;
        cin >> N >> x;
        vector<ll> vc(N);
        map<ll, bool> mp;
        for (int i{}; i < N; i++)
        {
            cin >> vc[i];
            mp[vc[i]] = true;
        }

        // a[i] + a[j] = x
        // Now we are at a[i]
        // a[j] = x - a[i]
        // Can be negative, or too large --> map
        // [ ] is overloaded to operate like `insert`

        bool isExisting = false;
        for (int i{}; i < N; i++) // O(N)
        {
            // lookup --> O(1)
            // 1 -2 3 5 0
            // mp[4] --> inserted 4 into the map --> N log N
            // if (mp[x - vc[i]] == true) // TLE, MLE
            if (mp.find(x - vc[i]) != mp.end()) // Doesn't insert, log N
                isExisting = true;
        }
        if (isExisting)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}