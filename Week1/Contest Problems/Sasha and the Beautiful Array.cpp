#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define N 1000000007

void kill()
{
    ll sum = 0, n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    if (n == 2)
    {
        cout << arr[1] - arr[0] << endl;
        return;
    }
    for (int i = 1; i < n; i++)
    {
        sum += arr[i] - arr[i - 1];
    }
    cout << sum;
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
