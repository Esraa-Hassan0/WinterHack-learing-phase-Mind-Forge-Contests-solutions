#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define MOD 1000000007

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	string Input, Text;
	getline(cin, Input);
	getline(cin, Text);

	int *arr{new int[123]{0}}; // Frequency array for lowercase and uppercase characters
	for (const char &C : Input)
		arr[C]++;

	for (const char &C : Text)
	{
		if (arr[C] == 0) // If the character is NOT existing, he CANNOT compose the needed text
			return cout << "NO", 0;

		if (C != ' ') // He does NOT cut spaces out of the heading.
			arr[C]--;
	}
	cout << "YES";
	return 0;
}