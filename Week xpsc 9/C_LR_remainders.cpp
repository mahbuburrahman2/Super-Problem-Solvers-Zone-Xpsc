#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
long long seg[4 * MAXN];
int MOD;

void build(int node, int l, int r, vector<int> &a)
{
  if (l == r)
  {
    seg[node] = a[l] % MOD;
    return;
  }
  int mid = (l + r) / 2;
  build(2 * node, l, mid, a);
  build(2 * node + 1, mid + 1, r, a);
  seg[node] = (seg[2 * node] * seg[2 * node + 1]) % MOD;
}

void update(int node, int l, int r, int idx)
{
  if (l == r)
  {
    seg[node] = 1;
    return;
  }
  int mid = (l + r) / 2;
  if (idx <= mid)
    update(2 * node, l, mid, idx);
  else
    update(2 * node + 1, mid + 1, r, idx);
  seg[node] = (seg[2 * node] * seg[2 * node + 1]) % MOD;
}

long long query(int node, int l, int r, int ql, int qr)
{
  if (ql > qr)
    return 1;
  if (ql <= l && r <= qr)
    return seg[node];
  int mid = (l + r) / 2;
  long long res = 1;
  if (ql <= mid)
    res = res * query(2 * node, l, mid, ql, qr) % MOD;
  if (qr > mid)
    res = res * query(2 * node + 1, mid + 1, r, ql, qr) % MOD;
  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--)
  {
    int n, m;
    cin >> n >> m;
    MOD = m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
      cin >> a[i];

    string s;
    cin >> s;

    build(1, 1, n, a);

    int l = 1, r = n;

    for (int i = 0; i < n; i++)
    {
      cout << query(1, 1, n, l, r);
      if (i < n - 1)
        cout << ' ';

      if (s[i] == 'L')
      {
        update(1, 1, n, l);
        l++;
      }
      else
      {
        update(1, 1, n, r);
        r--;
      }
    }
    cout << '\n';
  }

  return 0;
}