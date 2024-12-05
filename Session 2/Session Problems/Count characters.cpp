#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
// https://codeforces.com/group/c3FDl9EUi9/contest/262795/submission/226288572
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	int Freq_arr[123] = {0};
	string Input;
	cin >> Input;
	for (char &C : Input)
		Freq_arr[C]++;

	for (int i{65}; i < 123; i++)
		if (Freq_arr[i])
			cout << char(i) << " " << Freq_arr[i] << endl;
	return 0;
}