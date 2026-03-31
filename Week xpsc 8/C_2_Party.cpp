#include <bits/stdc++.h>
using namespace std;

struct DSU
{
  vector<int> par, rnk, sz;

  DSU(int n)
  {
    par.resize(n + 1);
    rnk.resize(n + 1, 0);
    sz.resize(n + 1, 1);
    for (int i = 1; i <= n; i++)
      par[i] = i;
  }

  int find(int x)
  {
    if (par[x] == x)
      return x;
    return par[x] = find(par[x]);
  }

  void unite(int a, int b)
  {
    a = find(a);
    b = find(b);
    if (a == b)
      return;

    if (rnk[a] < rnk[b])
      swap(a, b);

    par[b] = a;
    sz[a] += sz[b];

    if (rnk[a] == rnk[b])
      rnk[a]++;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  DSU dsu(n);

  int k;
  cin >> k;

  for (int i = 0; i < k; i++)
  {
    int u, v;
    cin >> u >> v;
    dsu.unite(u, v);
  }

  int m;
  cin >> m;

  vector<bool> bad(n + 1, false);

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;

    int ru = dsu.find(u);
    int rv = dsu.find(v);

    if (ru == rv)
      bad[ru] = true;
  }

  int ans = 0;

  for (int i = 1; i <= n; i++)
  {
    if (dsu.find(i) == i && !bad[i])
      ans = max(ans, dsu.sz[i]);
  }

  cout << ans << "\n";
}