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
    ll N, K;
    cin >> t;
    while (t--)
    {
        cin >> N >> K;
        vector<ll> c(N);
        ll cntFirst{}, cntLast{}, alternate = K;
        for (int i{}; i < N; i++)
            cin >> c[i];

        for (int i{}; i < N; i++)
        {
            if (c[i] == c[0] && alternate > 0)
                cntFirst++, alternate--;
            if (c[i] == c[N - 1] && alternate == 0)
                cntLast++;
        }
        // K|P , means P is a multiple of K
        // Path is divided to blocks (having the same colour), of K elements each
        // P = xK and P <= N
        if ((cntFirst == K && cntLast >= K) || (c[0] == c[N - 1] && cntFirst == K))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}