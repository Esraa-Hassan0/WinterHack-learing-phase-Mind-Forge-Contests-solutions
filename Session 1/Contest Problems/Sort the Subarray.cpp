#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define N 1000000007

void kill()
{
    ll n, st{-1}, end{-1}, num{}, mx{}, mn{};
    cin >> n;
    ll arr[n];
    ll sorted[n];
    for (ll i{}; i < n; i++)
        cin >> arr[i];

    for (ll i{}; i < n; i++)
        cin >> sorted[i];

    for (ll i{}; i < n; i++)
    {
        if (arr[i] != sorted[i] && st == -1)
            st = i + 1;
    }
    for (ll i{n - 1}; i >= 0; i--)
    {
        if (arr[i] != sorted[i] && end == -1)
            end = i + 1;
    }

    for (ll i{st - 1}; i < end; i++)
        if (arr[i] != sorted[i])
        {
            mx = max(mx, arr[i]);
            mn = min(mn, arr[i]);
        }

    while (st - 2 >= 0 && sorted[st - 2] <= sorted[st - 1])
        st--;
    while (end < n && sorted[end] >= sorted[end - 1])
        end++;
    cout << st << " " << end;
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
    cin >> t;
    while (t--)
    {
        kill();
        cout << endl;
    }
}