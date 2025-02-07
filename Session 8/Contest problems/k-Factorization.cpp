#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,O3,unroll-loops")
#pragma GCC target("avx,avx2,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define i128 __int128_t
#define endl "\n"

template <typename T>
T mult64(T a, T b, T mod)
{
    return (__int128_t)a * b % mod;
}

template <typename T>
T mult128(T a, T b, T mod)
{
    T result = 0; // Initialize result

    for (a %= mod; b > 0; a <<= 1, b >>= 1)
    {
        if (a >= mod)
            a -= mod;
        if (b & 1)
        {
            result += a;
            if (result >= mod)
                result -= mod;
        }
    }
    return result;
}

template <typename T>
inline T F(T x, T c, T mod) // Pollard-rho function
{
    return (mult64(x, x, mod) + c) % mod;
}

template <typename T>
inline T __abs(T N)
{
    if (N < 0)
        return -N;

    return N;
}

template <typename T>
T Pollard_Brent(T N)
{
    if (!(N & 1))
        return 2;

    // Random Number Linear Congruential Generator MMIX from D.E. Knuth
    static i128 rng = 0xdeafbeefff;
    uint64_t a = rng * 6364136223846793005ull + 1442695040888963407ull;
    uint64_t b = a * 6364136223846793005ull + 1442695040888963407ull;
    rng = (a + b) ^ (a * b);

    T X0 = 1 + a % (N - 1);
    T C = 1 + b % (N - 1);
    T X = X0; // X1
    T gcd_val = 1;
    T q = 1;
    T Xs, Xt;
    T m = 128;
    T L = 1;
    while (gcd_val == 1)
    {
        Xt = X;
        for (size_t i = 1; i < L; i++)
            X = F(X, C, N);

        int k = 0;
        while (k < L && gcd_val == 1)
        {
            Xs = X;
            for (size_t i = 0; i < m && i < L - k; i++)
            {
                X = F(X, C, N);
                q = mult64(q, __abs(Xt - X), N);
            }
            gcd_val = __gcd(q, N);
            k += m;
        }
        L += L;
    }
    if (gcd_val == N) // Failure
    {
        do
        {
            Xs = F(Xs, C, N);
            gcd_val = __gcd(__abs(Xs - Xt), N);
        } while (gcd_val == 1);
    }
    return gcd_val;
}

template <typename T>
T Mod_Bin_Exp(T N, T power, T mod) //(N^power) % mod
{
    if (N % mod == 0 || N == 0)
        return 0;
    if (N == 1 || power == 0)
        return 1;

    if (N >= mod)
        N -= mod;

    T res{1};
    while (power)
    {
        if (power & 1) // ODD
            res = mult64(res, N, mod);

        N = mult64(N, N, mod);
        power >>= 1;
    }
    return res;
}

template <typename T>
bool Check_Composite(T N, T a, T d, int s)
{
    T X = Mod_Bin_Exp(a, d, N);
    if (X == 1 || X == N - 1)
        return false; // Not composite

    for (int r = 1; r < s; r++)
    {
        X = mult128(X, X, N);
        if (X == 1 || X == N - 1)
            return false; // Not composite
    }
    return true; // Composite
}

template <typename T>
bool Miller_Rabin(T N, int K = 5) // k is the number of trials (bases). If k increases the accuracy increases
{
    T d = N - 1;
    int s{};
    while (!(d & 1))
        d >>= 1, ++s;

    for (const T &a : {
             11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (N == a)
            return true;
        if (Check_Composite(N, a, d, s))
            return false;
    }
    return true;
}

template <typename T>
bool Is_Prime(T N)
{
    if (N < 2)
        return false;

    if (N <= 3)
        return true;
    if (N == 5 || N == 7)
        return true;

    if (!(N & 1) || N % 3 == 0 || N % 5 == 0 || N % 7 == 0)
        return false;

    // return (Mod_Bin_Exp(T(2), N - 1, N) % N == 1); // Using Fermat's little theorem, because there are NO Carmichael numbers
    return Miller_Rabin(N);
}

template <typename T>
void Factor(T N, vector<T> &Prime_factors)
{
    if (N == 1)
        return;

    if (!Is_Prime(N))
    {
        T Y = Pollard_Brent(N);
        Factor(Y, Prime_factors);
        Factor(N / Y, Prime_factors);
    }
    else
    {
        Prime_factors.push_back(N); // Use push_back() if using a vector
        return;
    }
}

template <typename T>
vector<T> Prime_factorize(T N)
{
    vector<T> Prime_factors; // Use a vector if generating ALL factors
    Factor(N, Prime_factors);
    return Prime_factors;
}

template <typename T>
vector<T> ALL_factors(T N)
{
    // Change the return type of Prime_factorize
    vector<T> primeFactors = Prime_factorize(N);
    vector<T> All_factors = {1};
    for (size_t i = 0; i < primeFactors.size(); i++)
    {
        ll currentSize = All_factors.size();
        for (size_t j = 0; j < currentSize; j++)
        {
            All_factors.push_back(All_factors[j] * primeFactors[i]);
        }
        set<T> st;
        for (auto v : All_factors)
            st.insert(v);

        All_factors.clear();
        for (auto v : st)
            All_factors.push_back(v);
    }
    return All_factors;
}
/////////////////////////////////////////////////////////////////////////
// GCC's implementation for I/O of 128-bit integers
template <class integer>
inline integer to_int(const string &s, size_t *idx = 0, int base = 10)
{
    size_t n = s.size(), i = idx ? *idx : 0;
    bool sign = false;
    integer x = 0;
    if (s[i] == '-')
        ++i, sign = true;
    function<int(char)> char_to_digit = [&](char c)
    {
        static const int d[] = {'a' - 10, '0'};
        return tolower(c) - d[isdigit(c)];
    };
    while (i < n)
        x *= base, x += char_to_digit(s[i++]);
    if (idx)
        *idx = i;
    return sign ? -x : x;
}

template <class integer>
inline string to_string(integer x, int base = 10)
{
    bool sign = false;
    string s;
    if (x < 0)
        x = -x, sign = true;
    function<char(int)> digit_to_char = [](int d)
    {
        static const char c[] = {'a' - 10, '0'};
        return c[d < 10] + d;
    };
    do
        s += digit_to_char(x % base), x /= base;
    while (x > 0);
    if (sign)
        s += '-';
    reverse(s.begin(), s.end());
    return s;
}

template <class integer>
inline istream &read_128(istream &is, integer &x)
{
    string s;
    is >> s, x = to_int<integer>(s);
    return is;
}

template <class integer>
inline ostream &print_128(ostream &os, integer x)
{
    return os << to_string(x);
}

inline istream &operator>>(istream &is, i128 &x)
{
    return read_128(is, x);
}
inline ostream &operator<<(ostream &os, i128 x)
{
    return print_128(os, x);
}

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
    // cin >> t;
    while (t--)
    {
        cin >> N >> K;
        vector<ll> pf = Prime_factorize(N);
        if (K > pf.size())
            cout << "-1\n";
        else
        {
            int cnt{};
            ll rem{1};
            int i{0};
            for (NULL; i < K - 1; i++)
                cout << pf[i] << " ";

            for (NULL; i < pf.size(); i++)
                rem *= pf[i];
            cout << rem;
        }
    }
    return 0;
}