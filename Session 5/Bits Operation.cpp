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
    int t = 1, K, N;
    // cin >> t;
    while (t--)
    {
        // 011010111100101 -> bitmask
        // Bitwise operators:
        /*
        bitwise &
        5 & 13
        0101
        &
        1101
        ----
        0101
        bitwise |
        0101
        |
        1101
        ----
        1101

        XOR ^
        0101
        ^
        1101
        ----
        1000

        NOT ~
        ~(01101110) = 10010001
        left shift << k --> * 2 power k
        right shift >> k --> / 2 power k
        */
        ll n, q;
        cin >> q >> n;
        while (q--)
        {
            int query;
            ll x;
            cin >> query;
            if (query == 1)
            {
                cin >> x;
                n = n | x;
                cout << n << endl;
            }
            else if (query == 2)
            {
                cin >> x;
                n = n & x;
                cout << n << endl;
            }
            else if (query == 3)
            {
                cin >> x;
                n = n ^ x;
                cout << n << endl;
            }
            else
                cout << (n = ~n) << endl;
        }
    }
    return 0;
}