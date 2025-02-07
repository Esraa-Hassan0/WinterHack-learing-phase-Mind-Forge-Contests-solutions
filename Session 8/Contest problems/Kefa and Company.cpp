#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, d;
vector<pair<ll, ll>> vc;
bool ok(ll mid, ll lb)
{
    return (vc[mid].first - vc[lb].first < d);
}
void solve()
{
    cin >> n >> d;
    for (ll i{}; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        vc.push_back({x, y});
    }
    ll prefix[n];
    sort(vc.begin(), vc.end());
    for (ll i{}; i < n; i++)
    {
        prefix[i] = vc[i].second;
    }

    for (ll i{1}; i < n; i++)
        prefix[i] += prefix[i - 1];

    ll mx{};

    ll l = 0, lr = n - 1;
    ll mid, ans = 0, ansidx{}, lb{};

    for (ll j{}; j < n; j++)
    {
        l = j, lr = n - 1;
        for (ll i{}; i < 100; i++)
        {
            mid = l + (lr - l) / 2;
            if (!ok(mid, j))
            {
                lr = mid - 1;
            }
            else
            {
                ansidx = mid;
                l = mid + 1;
            }
        }
        ansidx = min(n - 1, ansidx);
        // cout << mx << " " << ansidx << "\n";
        if (j)
            ans = prefix[ansidx] - prefix[j - 1];
        else
            ans = prefix[ansidx] - 0;
        mx = max(mx, ans);
    }

    cout << mx;
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
    while (t--)
    {
        solve();
    }
    return 0;
}