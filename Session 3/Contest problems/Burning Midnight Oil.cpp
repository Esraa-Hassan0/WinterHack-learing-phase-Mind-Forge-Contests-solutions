#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define N 1000000007
ll n, k, ans;
bool check(ll v)
{
    ll m = 0;
    for (int i = 0;; i++)
    {
        ll x = v / pow(k, i);
        if (!x)
            break;
        m += x;
        if (m >= n)
            break;
    }
    return m >= n;
}

void kill()
{
    cin >> n >> k;
    ll l = 0, r = n;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        if (check(m))
        {
            r = m - 1;
            ans = m;
        }
        else
            l = m + 1;
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
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        kill();
        cout << endl;
    }
}
