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
	ll N;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		int len = str.length();
		int freq[26]{};
		for (const char &C : str)
			freq[C - 'a']++;
		int cntOdd = count_if(freq, freq + 26, [](int x)
							  { return x & 1; });
		if (cntOdd > 1)
		{
			cout << "impossible\n";
			continue;
		}
		string ans = str;
		int l{}, r = len - 1;
		char C = '$';
		for (int i{}; i < 26 && l <= r; i++)
		{
			while (freq[i] > 1)
			{
				ans[l++] = char(i + 'a'), freq[i]--;
				ans[r--] = char(i + 'a'), freq[i]--;
			}
			if (freq[i] & 1)
				C = i + 'a';
		}
		if (C != '$')
			ans[len / 2] = C;
		cout << ans << endl;
	}
	return 0;
}