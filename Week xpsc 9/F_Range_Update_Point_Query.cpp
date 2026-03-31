#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int a[MAXN];
int seg[4 * MAXN];

void build(int node, int l, int r)
{
  if (l == r)
  {
    seg[node] = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build(2 * node, l, mid);
  build(2 * node + 1, mid + 1, r);
  seg[node] = max(seg[2 * node], seg[2 * node + 1]);
}

int digitSum(int x)
{
  int s = 0;
  while (x > 0)
  {
    s += x % 10;
    x /= 10;
  }
  return s;
}

void update(int node, int l, int r, int ql, int qr)
{
  if (seg[node] <= 9)
    return;
  if (l == r)
  {
    a[l] = digitSum(a[l]);
    seg[node] = a[l];
    return;
  }
  int mid = (l + r) / 2;
  if (ql <= mid)
    update(2 * node, l, mid, ql, qr);
  if (qr > mid)
    update(2 * node + 1, mid + 1, r, ql, qr);
  seg[node] = max(seg[2 * node], seg[2 * node + 1]);
}

int query(int node, int l, int r, int idx)
{
  if (l == r)
    return a[l];
  int mid = (l + r) / 2;
  if (idx <= mid)
    return query(2 * node, l, mid, idx);
  else
    return query(2 * node + 1, mid + 1, r, idx);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
  {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    build(1, 1, n);
    while (q--)
    {
      int type;
      cin >> type;
      if (type == 1)
      {
        int l, r;
        cin >> l >> r;
        update(1, 1, n, l, r);
      }
      else
      {
        int x;
        cin >> x;
        cout << query(1, 1, n, x) << '\n';
      }
    }
  }
  return 0;
}