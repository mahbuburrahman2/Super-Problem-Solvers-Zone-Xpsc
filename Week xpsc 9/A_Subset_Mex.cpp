#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int f[N], t1[4 * N], t2[4 * N];

void build(int n, int b, int e)
{
  if (b == e)
  {
    t1[n] = f[b];
    t2[n] = f[b] - 1;
    return;
  }
  int m = (b + e) >> 1;
  build(n << 1, b, m);
  build(n << 1 | 1, m + 1, e);
  t1[n] = min(t1[n << 1], t1[n << 1 | 1]);
  t2[n] = min(t2[n << 1], t2[n << 1 | 1]);
}

int mexA(int n, int b, int e)
{
  if (t1[n] > 0)
    return -1;
  if (b == e)
    return b;
  int m = (b + e) >> 1;
  if (t1[n << 1] == 0)
    return mexA(n << 1, b, m);
  return mexA(n << 1 | 1, m + 1, e);
}

int mexB(int n, int b, int e)
{
  if (t2[n] > 0)
    return -1;
  if (b == e)
    return b;
  int m = (b + e) >> 1;
  if (t2[n << 1] <= 0)
    return mexB(n << 1, b, m);
  return mexB(n << 1 | 1, m + 1, e);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    memset(f, 0, sizeof f);

    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      f[x]++;
    }

    build(1, 0, 100);

    int a = mexA(1, 0, 100);
    int b = mexB(1, 0, 100);

    if (a == -1)
      a = 101;
    if (b == -1)
      b = 101;

    cout << a + b << '\n';
  }
}