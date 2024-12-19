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
        // 23
        // Expand --> include from right
        // Shrink --> exclude from left
        // O(N)
        ll N, sum;
        cin >> N >> sum;
        vector<ll> arr(N);
        for (int i{}; i < N; i++)
            cin >> arr[i];
        // Variable size sliding window
        ll curSum{};
        int L{}, R{}; // At first index
        int ansL = -1, ansR = -1;
        while (R < N)
        {
            // Expand
            curSum += arr[R];
            while (curSum > sum && L <= R) // Shrink
                curSum -= arr[L++];

            if (curSum == sum)
            {
                ansL = L;
                ansR = R;
                break;
            }
            R++;
        }
        cout << ansL + 1 << " " << ansR + 1;
    }
    return 0;
}