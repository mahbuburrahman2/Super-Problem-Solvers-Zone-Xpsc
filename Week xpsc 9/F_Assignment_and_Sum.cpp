#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 5;

long long seg[4 * N];
long long lazy[4 * N];
bool mark[4 * N];

void push(int node, int b, int e)
{
  if (mark[node])
  {
    seg[node] = (e - b + 1) * lazy[node];

    if (b != e)
    {
      mark[node << 1] = mark[node << 1 | 1] = true;
      lazy[node << 1] = lazy[node];
      lazy[node << 1 | 1] = lazy[node];
    }

    mark[node] = false;
  }
}

void update(int node, int b, int e, int l, int r, long long v)
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

  seg[node] = seg[node << 1] + seg[node << 1 | 1];
}

long long query(int node, int b, int e, int l, int r)
{
  push(node, b, e);

  if (e < l || b > r)
    return 0;

  if (l <= b && e <= r)
    return seg[node];

  int m = (b + e) >> 1;
  return query(node << 1, b, m, l, r) +
         query(node << 1 | 1, m + 1, e, l, r);
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
      int l, r;
      long long v;
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