#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int INF_AND = (1 << 30) - 1;

int seg[4 * MAXN];
int n;

void build(int node, int l, int r, int *a)
{
  if (l == r)
  {
    seg[node] = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build(2 * node, l, mid, a);
  build(2 * node + 1, mid + 1, r, a);
  seg[node] = seg[2 * node] & seg[2 * node + 1];
}

int query(int node, int l, int r, int ql, int qr)
{
  if (ql <= l && r <= qr)
    return seg[node];
  if (qr < l || r < ql)
    return INF_AND;
  int mid = (l + r) / 2;
  return query(2 * node, l, mid, ql, qr) & query(2 * node + 1, mid + 1, r, ql, qr);
}

int solve(int node, int l, int r, int ql, int k, int curAnd)
{
  if (r < ql)
    return -1;
  if (l == r)
    if ((curAnd & seg[node]) >= k)
      return l;
    else
      return -1;
  int mid = (l + r) / 2;
  int leftAnd = curAnd & query(1, 1, n, max(ql, l), mid);

  int res = -1;
  if (leftAnd >= k)
    res = solve(2 * node + 1, mid + 1, r, ql, k, leftAnd);

  if (res != -1)
    return res;
  return solve(2 * node, l, mid, ql, k, curAnd);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    build(1, 1, n, a);
    int q;
    cin >> q;
    while (q--)
    {
      int l, k;
      cin >> l >> k;
      cout << solve(1, 1, n, l, k, INF_AND);
      if (q)
        cout << ' ';
    }
    cout << '\n';
  }
  return 0;
}