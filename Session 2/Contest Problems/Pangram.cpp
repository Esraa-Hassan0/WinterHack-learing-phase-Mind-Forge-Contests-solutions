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
	ll N, Q;
	// cin >> t;
	while (t--)
	{
		vector<bool> freq(26);
		// a -> z, A -> Z
		int n;
		string s;
		cin >> n >> s;
		for (char &c : s)
			freq[tolower(c) - 'a'] = true;
		for (int i = 0; i < 26; i++)
		{
			if (!freq[i])
			{
				cout << "NO\n";
				return;
			}
		}
		cout << "YES\n";
	}
	return 0;
}
