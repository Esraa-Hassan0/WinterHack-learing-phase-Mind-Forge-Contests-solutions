#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> arr;
ll n, k;
ll ok(ll x)
{
    ll m{};
    for (ll i{n / 2}; i < n; i++)
    {
        if (x - arr[i] > 0)
            m += x - arr[i];
    }
    return k >= m;
}
void solve()
{
    cin >> n >> k;
    for (ll i{}; i < n; i++)
    {
        ll x;
        cin >> x;
        arr.push_back(x);
    }
    // 1 1 1 1 2
    // 1 1 2 2
    sort(arr.begin(), arr.end());
    ll l = 1, r = 1ll << 34;
    ll mid, ans = 0;
    // 1 1 0 0 0 0
    for (ll i{}; i < 100; i++)
    {
        mid = ((l + r + 1) / 2);
        if (!ok(mid))
        {
            r = mid - 1;
        }
        else
        {
            ans = mid;
            l = mid;
        }
    }
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}