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
        cin >> N >> Q;
        vector<ll> vc(N + 1), pref(N + 1);
        for (int i{1}; i <= N; i++)
            cin >> vc[i];
        pref[0] = 0;
        pref[1] = vc[1];
        for (int i{2}; i <= N; i++)
            pref[i] = pref[i - 1] + vc[i];
        while (Q--)
        {
            ll L, R;
            cin >> L >> R;
            cout << pref[R] - pref[L - 1] << endl;
        }
    }
    return 0;
}
