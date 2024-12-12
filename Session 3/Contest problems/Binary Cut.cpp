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
    ll N, a, b, c, d;
    string str;
    cin >> t;
    while (t--)
    {
        cin >> str;
        if (is_sorted(str.begin(), str.end()))
        {
            cout << 1 << endl;
            continue;
        }
        str.erase(unique(str.begin(), str.end()), str.end());
        if (str.size() == 2)
            cout << 2 << endl;
        else
            cout << str.size() - 1 << endl;
    }
    return 0;
}