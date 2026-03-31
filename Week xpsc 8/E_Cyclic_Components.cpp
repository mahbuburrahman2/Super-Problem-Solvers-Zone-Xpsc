#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU
{
  vector<int> par, rnk, siz, edges, deg;

  DSU(int n) : par(n + 1), rnk(n + 1, 0), siz(n + 1, 1), edges(n + 1, 0), deg(n + 1, 0)
  {
    iota(par.begin(), par.end(), 0);
  }

  int find(int i)
  {
    return (par[i] == i ? i : (par[i] = find(par[i])));
  }

  bool same(int u, int v)
  {
    return find(u) == find(v);
  }

  int getsize(int u)
  {
    return siz[find(u)];
  }

  void unite(int u, int v)
  {
    deg[u]++;
    deg[v]++;

    int root_u = find(u);
    int root_v = find(v);

    if (root_u != root_v)
    {
      if (rnk[root_u] > rnk[root_v])
        swap(root_u, root_v);
      par[root_u] = root_v;
      if (rnk[root_u] == rnk[root_v])
        rnk[root_v]++;

      siz[root_v] += siz[root_u];
      edges[root_v] += edges[root_u] + 1;
    }
    else
    {
      edges[root_u]++;
    }
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  if (!(cin >> n >> m))
    return 0;

  DSU dsu(n);
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    dsu.unite(u, v);
  }

  vector<bool> bad(n + 1, false);
  for (int i = 1; i <= n; i++)
  {
    if (dsu.deg[i] != 2)
    {
      bad[dsu.find(i)] = true;
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    if (dsu.par[i] == i)
    {
      if (!bad[i] && dsu.deg[i] > 0)
      {
        ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}