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
        // Two-pointers technique
        // binary search
        // Sliding window: fixed, variable
        // O(N³)
        // 15 2 4 8 9 5 10
        // 15 + 2 + 4
        // 2 + 4 + 8
        // 23
        // Expand --> include from right
        // Shrink --> exclude from left
        // O(N)
        ll N, S;
        cin >> N >> S;
        vector<ll> arr(N);
        for (int i{}; i < N; i++)
            cin >> arr[i];
        // Variable size sliding window
        ll curSum{};
        ll maxLen = 0;
        int L = 0, R = 0;
        while (R < N)
        {
            curSum += arr[R]; // Expand
            while (curSum > S && L <= R)
                curSum -= arr[L++]; // Shrink
            // curSum <= S
            maxLen = max(maxLen, R - L + 1LL); // Valid sub-array
            R++;
        }
        cout << maxLen;
    }
    return 0;
}