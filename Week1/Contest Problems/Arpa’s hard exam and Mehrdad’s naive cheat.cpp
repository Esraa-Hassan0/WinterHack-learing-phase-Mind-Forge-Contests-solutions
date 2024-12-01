#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define N 1000000007

void kill()
{
    ll a;
    cin >> a;
    if (a == 0)
        cout << 1;
    else
    {
        a %= 4;
        if (a == 0)
            cout << "6";
        if (a == 1)
            cout << "8";
        if (a == 2)
            cout << "4";
        if (a == 3)
            cout << "2";
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
    while (t--)
    {
        kill();
        cout << endl;
    }
}