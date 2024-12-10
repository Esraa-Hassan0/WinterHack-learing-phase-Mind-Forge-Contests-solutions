#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

ll removeZeros(ll N)
{
	string number = to_string(N);
	string res("");
	for (int i{}; i < number.length(); i++)
		if (number[i] != '0')
			res += number[i];
	return stoll(res);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	ll a, b;
	cin >> a >> b;
	ll sumWithZeros = a + b;
	if (removeZeros(a) + removeZeros(b) == removeZeros(sumWithZeros))
		cout << "YES";
	else
		cout << "NO";
	return 0;
}