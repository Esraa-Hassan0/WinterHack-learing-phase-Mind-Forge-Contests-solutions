#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define N 1000000007

void kill()
{
    ll n, m;
    cin >> n >> m;
    cout << n * m / 2;
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
    while (t--)
    {
        kill();
        cout << endl;
    }
}