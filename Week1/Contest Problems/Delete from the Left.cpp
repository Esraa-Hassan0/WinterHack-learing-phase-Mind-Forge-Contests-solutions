#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define ll long long
int main()
{

    int t = 1;
    ll n, check = 0;
    while (t--)
    {
        string s, s1;
        cin >> s >> s1;
        reverse(s.begin(), s.end());
        reverse(s1.begin(), s1.end());
        ll i{};
        for (; i < min(s.size(), s1.size()); i++)
            if (s[i] != s1[i])
                break;
        cout << s.size() + s1.size() - i * 2;
    }

    return 0;
}