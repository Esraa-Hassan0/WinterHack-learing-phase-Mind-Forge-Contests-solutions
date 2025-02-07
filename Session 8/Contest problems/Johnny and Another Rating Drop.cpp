#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, ans{};
    cin >> n;
    while (n)
    {
        ans += n; // Number of swaps in LSB bit is n, for second last bit n/2 and so on...
        n /= 2;
    }
    // 0000
    // 0001
    // 0010
    // 0011
    // 0100
    // 0101
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
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}