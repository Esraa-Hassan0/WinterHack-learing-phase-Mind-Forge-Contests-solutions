#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
Set: 1
Cleared: 0
indexing bits starts from right, 0-based
rightmost bit -> LSB
leftmost bit -> MSB
*/
void setIthBit(ll &N, int i)
{
    // 000101111010111
    // 000000000001000
    N = (N | (1LL << i));
}

void clearIthBit(ll &N, int i)
{
    // 000101111010111
    // 000000000001000
    // 111111111110111
    N = (N & ~(1LL << i));
}

void flipIthBit(ll &N, int i)
{
    N = (N ^ (1LL << i));
}

bool checkIthBit(const ll &N, int i)
{
    // 000101111010111
    return ((N >> i) & 1);
    // return !(N ^ (1LL << i));
    // return (N & (1LL << i));
}

void clearRightmostSetBit(ll &N)
{
    // 11100101(1)00
    // 11100101(0)11
    N = (N & (N - 1));
}

int countSetBits(ll N)
{
    int cnt{};
    while (N)
    {
        if (N & 1)
            cnt++;
        N >>= 1;
    }
    return cnt;
}

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
        }
    }
    return 0;
}