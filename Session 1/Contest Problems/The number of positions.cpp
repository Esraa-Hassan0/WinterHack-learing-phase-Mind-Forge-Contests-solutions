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
    ll N, K, a, b;
    // cin >> t;
    while (t--)
    {

        cin >> N >> a >> b;
        ll ans{}, cur = a;
        while (cur < N)
            ans += (N - cur - 1 <= b), cur++;
        cout << ans << endl;
    }
    return 0;
}