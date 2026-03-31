#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 5;

int seg[4 * N];
int lazy[4 * N];
bool mark[4 * N];

void push(int node, int b, int e)
{
  if (mark[node])
  {
    seg[node] = lazy[node];

    if (b != e)
    {
      mark[node << 1] = mark[node << 1 | 1] = true;
      lazy[node << 1] = lazy[node];
      lazy[node << 1 | 1] = lazy[node];
    }

    mark[node] = false;
  }
}

void update(int node, int b, int e, int l, int r, int v)
{
  push(node, b, e);

  if (e < l || b > r)
    return;

  if (l <= b && e <= r)
  {
    mark[node] = true;
    lazy[node] = v;
    push(node, b, e);
    return;
  }

  int m = (b + e) >> 1;
  update(node << 1, b, m, l, r, v);
  update(node << 1 | 1, m + 1, e, l, r, v);

  seg[node] = min(seg[node << 1], seg[node << 1 | 1]);
}

int query(int node, int b, int e, int l, int r)
{
  push(node, b, e);

  if (e < l || b > r)
    return INT_MAX;

  if (l <= b && e <= r)
    return seg[node];

  int m = (b + e) >> 1;
  return min(query(node << 1, b, m, l, r),
             query(node << 1 | 1, m + 1, e, l, r));
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
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