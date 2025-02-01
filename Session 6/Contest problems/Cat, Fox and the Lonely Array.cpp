#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define L 2 * node + 1
#define R 2 * node + 2
#define mid (left + right) / 2

struct item
{
    ll val;
};

item make_item(ll val)
{
    item i = {val};
    return i;
}

item merge(item first, item second)
{
    return make_item(first.val | second.val);
}

class segmentTree
{
    int size;
    vector<item> seg;
    item Neutral;

    void build(int left, int right, int node, const vector<ll> &vc)
    {
        if (left == right)
        {
            if (left < vc.size())
                seg[node] = make_item(vc[left]);
            return;
        }
        build(left, mid, L, vc);
        build(mid + 1, right, R, vc);
        seg[node] = merge(seg[L], seg[R]);
    }
    void update(int left, int right, int node, int idx, ll val)
    {
        if (left == right)
        {
            seg[node] = make_item(val);
            return;
        }
        if (idx <= mid)
            update(left, mid, L, idx, val);
        else
            update(mid + 1, right, R, idx, val);
        seg[node] = merge(seg[L], seg[R]);
    }
    item query(int left, int right, int node, int Lq, int Rq)
    {
        if (left > Rq || right < Lq)
            return Neutral;
        if (left >= Lq && right <= Rq)
            return seg[node];
        item leftseg = query(left, mid, L, Lq, Rq);
        item rightseg = query(mid + 1, right, R, Lq, Rq);
        return merge(leftseg, rightseg);
    }

public:
    segmentTree(const vector<ll> &vc)
    {
        Neutral = {0};
        int s = vc.size();
        size = 1;
        while (size < s)
            size *= 2;
        seg.resize(2 * size, Neutral);
        build(0, size - 1, 0, vc);
    }
    void update(int idx, ll val)
    {
        update(0, size - 1, 0, idx, val);
    }
    int query(int left, int right)
    {
        item i = query(0, size - 1, 0, left, right);
        return i.val;
    }
};

#undef L
#undef R
#undef mid

bool good(int k, segmentTree &segTree, int n)
{
    int ans = segTree.query(0, k - 1);
    for (int i = 1; i < n - k + 1; i++)
    {
        int temp = segTree.query(i, i + k - 1);
        if (temp != ans)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> vc(n);
        for (auto &i : vc)
            cin >> i;
        segmentTree segtree(vc);
        int l = 0;
        int r = n;
        int mid;
        while (r > l + 1)
        {
            mid = (r + l) / 2;
            if (good(mid, segtree, n))
                r = mid;
            else
                l = mid;
        }
        cout << r << "\n";
    }
    return 0;
}