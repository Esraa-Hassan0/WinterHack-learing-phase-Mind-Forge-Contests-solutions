#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

struct segmentTree
{
#define L (2 * node + 1)
#define R (2 * node + 2)
#define mid ((left + right) >> 1)
private:
    struct Node
    {
        ll mx;
        // Constructors
        Node() {}
        Node(const ll &val) : mx(val) {}
    };
    int size;
    vector<Node> seg;
    Node merge(const Node &leftNode, const Node &rightNode)
    {
        Node res;
        res.mx = max(leftNode.mx, rightNode.mx);
        return res;
    }
    void build(int left, int right, int node, const vector<ll> &arr)
    {
        if (left == right)
        {
            if (left < arr.size())
                seg[node] = arr[left];
            return;
        }
        // Building left node
        build(left, mid, L, arr);

        // Building right node
        build(mid + 1, right, R, arr);

        // Returning to parent nodes
        seg[node] = merge(seg[L], seg[R]);
    }
    void update(int left, int right, int node, int idx, int val)
    {
        if (left == right)
        {
            seg[node].mx += val;
            return;
        }
        if (idx <= mid)
            update(left, mid, L, idx, val);
        else
            update(mid + 1, right, R, idx, val);
        // Updating while returning to parent nodes
        seg[node] = merge(seg[L], seg[R]);
    }
    Node query(int left, int right, int node, int k)
    {
        if (left == right)
            return (seg[node].mx >= k ? left : -1);
        if (k <= seg[L].mx)
            return query(left, mid, L, k);
        else
            return query(mid + 1, right, R, k);
    }

public:
    segmentTree(const vector<ll> &arr)
    {
        size = 1;
        int n = arr.size();
        while (size < n)
            size <<= 1;
        seg = vector<Node>(2 * size, 0);
        build(0, size - 1, 0, arr);
    }
    void update(int idx, int val)
    {
        update(0, size - 1, 0, idx, val);
    }
    ll query(int k)
    {
        Node ans = query(0, size - 1, 0, k);
        return ans.mx;
    }

#undef L
#undef R
#undef mid
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
    ll N, M;
    cin >> N >> M;
    vector<ll> vc(N);
    for (int i{}; i < N; i++)
        cin >> vc[i];

    segmentTree segTree(vc);
    while (M--)
    {
        ll x;
        cin >> x;
        int idx = segTree.query(x);
        cout << idx + 1 << " ";
        if (idx >= 0)
            segTree.update(idx, -x);
    }
    return 0;
}