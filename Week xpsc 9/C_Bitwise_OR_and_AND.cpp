#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 5;

int n, m;
int seg[4 * N], lazy[4 * N];

void push(int node, int b, int e)
{
  if (lazy[node])
  {
    seg[node] |= lazy[node];

    if (b != e)
    {
      lazy[node << 1] |= lazy[node];
      lazy[node << 1 | 1] |= lazy[node];
    }

    lazy[node] = 0;
  }
}

void update(int node, int b, int e, int l, int r, int v)
{
  push(node, b, e);

  if (e < l || b > r)
    return;

  if (l <= b && e <= r)
  {
    lazy[node] |= v;
    push(node, b, e);
    return;
  }

  int m = (b + e) >> 1;
  update(node << 1, b, m, l, r, v);
  update(node << 1 | 1, m + 1, e, l, r, v);

  seg[node] = seg[node << 1] & seg[node << 1 | 1];
}

int query(int node, int b, int e, int l, int r)
{
  push(node, b, e);

  if (e < l || b > r)
    return (1 << 30) - 1;

  if (l <= b && e <= r)
    return seg[node];

  int m = (b + e) >> 1;
  return query(node << 1, b, m, l, r) &
         query(node << 1 | 1, m + 1, e, l, r);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  while (m--)
  {
    int t;
    cin >> t;

    if (t == 1)
    {
      int l, r, v;
      cin >> l >> r >> v;
      update(1, 0, n - 1, l, r - 1, v);
    }
    else
    {
      int l, r;
      cin >> l >> r;
      cout << query(1, 0, n - 1, l, r - 1) << '\n';
    }
  }
  return 0;
}
