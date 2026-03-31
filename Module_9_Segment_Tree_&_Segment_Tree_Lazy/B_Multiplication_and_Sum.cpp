#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 9;
const long long MOD = 1e9 + 7;

long long t[maxN * 4], lazy[maxN * 4];

void build(int n, int b, int e)
{
  if (b == e)
  {
    t[n] = 1;
    return;
  }
  int mid = (b + e) / 2;
  build(2 * n, b, mid);
  build(2 * n + 1, mid + 1, e);
  t[n] = (t[2 * n] + t[2 * n + 1]) % MOD;
}

void push(int n, int b, int e)
{
  if (lazy[n] == 1)
    return;

  t[n] = (t[n] * lazy[n]) % MOD;

  if (b != e)
  {
    lazy[2 * n] = (lazy[2 * n] * lazy[n]) % MOD;
    lazy[2 * n + 1] = (lazy[2 * n + 1] * lazy[n]) % MOD;
  }

  lazy[n] = 1;
}

void update(int n, int b, int e, int i, int j, long long v)
{
  push(n, b, e);

  if (e < i || j < b)
    return;

  if (b >= i && e <= j)
  {
    lazy[n] = (lazy[n] * v) % MOD;
    push(n, b, e);
    return;
  }

  int mid = (b + e) / 2;
  update(2 * n, b, mid, i, j, v);
  update(2 * n + 1, mid + 1, e, i, j, v);

  t[n] = (t[2 * n] + t[2 * n + 1]) % MOD;
}

long long query(int n, int b, int e, int i, int j)
{
  push(n, b, e);

  if (e < i || j < b)
    return 0;

  if (b >= i && e <= j)
  {
    return t[n];
  }

  int mid = (b + e) / 2;
  return (query(2 * n, b, mid, i, j) +
          query(2 * n + 1, mid + 1, e, i, j)) %
         MOD;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  // initialize lazy with 1 (important!)
  for (int i = 0; i < 4 * maxN; i++)
    lazy[i] = 1;

  build(1, 1, n);

  while (m--)
  {
    int type;
    cin >> type;

    if (type == 1)
    {
      int l, r;
      long long v;
      cin >> l >> r >> v;
      l++; // 0-index to 1-index
      update(1, 1, n, l, r, v);
    }
    else
    {
      int l, r;
      cin >> l >> r;
      l++;
      cout << query(1, 1, n, l, r) << '\n';
    }
  }
}