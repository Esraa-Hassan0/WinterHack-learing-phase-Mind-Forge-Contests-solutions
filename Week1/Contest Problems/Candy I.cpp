#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define N 1000000007

void kill(ll n)
{
    ll sum{}, ans{};
    ll arr[n];
    for (ll i{}; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    if (sum % n)
    {
        cout << "-1\n";
        return;
    }
    ll avg = sum / n;
    for (ll i{}; i < n; i++)
    {
        if (arr[i] < avg)
            ans += avg - arr[i];
    }
    cout << ans << "\n";
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
    while (1)
    {
        ll n;
        cin >> n;
        if (n == -1)
        {
            return 0;
        }
        kill(n);
    }
}
