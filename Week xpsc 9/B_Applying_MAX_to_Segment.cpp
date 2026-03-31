#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int lazy[4 * N];
void build(int node, int l, int r)
{
  lazy[node] = 0;
  if (l == r)
    return;
  int mid = (l + r) / 2;
  build(node * 2, l, mid);
  build(node * 2 + 1, mid + 1, r);
}

void update(int node, int l, int r, int ql, int qr, int val)
{
  if (qr < l || r < ql)
    return;
  if (ql <= l && r <= qr)
  {
    lazy[node] = max(lazy[node], val);
    return;
  }
  int mid = (l + r) / 2;
  update(node * 2, l, mid, ql, qr, val);
  update(node * 2 + 1, mid + 1, r, ql, qr, val);
}
int query(int node, int l, int r, int idx)
{
  if (l == r)
    return lazy[node];
  int mid = (l + r) / 2;
  int child_val;
  if (idx <= mid)
    child_val = query(node * 2, l, mid, idx);
  else
    child_val = query(node * 2 + 1, mid + 1, r, idx);
  return max(lazy[node], child_val);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  build(1, 0, n - 1);
  while (m--)
  {
    int type;
    cin >> type;
    if (type == 1)
    {
      int l, r, v;
      cin >> l >> r >> v;

      update(1, 0, n - 1, l, r - 1, v);
    }
    else
    {
      int i;
      cin >> i;
      cout << query(1, 0, n - 1, i) << '\n';
    }
  }
  return 0;
}