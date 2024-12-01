#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define N 1000000007

void kill()
{
    ll n, k;
    cin >> n >> k;
    if (k >= n)
        cout << 1;
    else
    {

        for (ll i{2}; i * i <= n; i++)
        {
            if (n % (i) == 0 && n / i <= k)
            {
                cout << i;
                return;
            }
        }
        for (ll i{sqrtl(n)}; i >= 2; i--)
        {
            if (n % (i) == 0 && i <= k)
            {
                cout << n / i;
                return;
            }
        }
        cout << n;
    }
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
