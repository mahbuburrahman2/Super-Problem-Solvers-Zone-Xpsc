#include <bits/stdc++.h>
using namespace std;

struct DSU
{
  vector<int> par, rnk;
  DSU(int n) : par(n + 1), rnk(n + 1, 0)
  {
    for (int i = 1; i <= n; i++)
      par[i] = i;
  }
  int find(int x) { return par[x] == x ? x : (par[x] = find(par[x])); }
  bool same(int u, int v) { return find(u) == find(v); }
  void merge(int u, int v)
  {
    u = find(u);
    v = find(v);
    if (u == v)
      return;
    if (rnk[u] > rnk[v])
      swap(u, v);
    par[u] = v;
    if (rnk[u] == rnk[v])
      rnk[v]++;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m1, m2;
  cin >> n >> m1 >> m2;

  DSU A(n), B(n);

  for (int i = 0; i < m1; i++)
  {
    int u, v;
    cin >> u >> v;
    A.merge(u, v);
  }

  for (int i = 0; i < m2; i++)
  {
    int u, v;
    cin >> u >> v;
    B.merge(u, v);
  }

  vector<pair<int, int>> ans;
  for (int u = 1; u <= n; u++)
  {
    for (int v = u + 1; v <= n; v++)
    {
      if (!A.same(u, v) && !B.same(u, v))
      {
        A.merge(u, v);
        B.merge(u, v);
        ans.push_back({u, v});
      }
    }
  }

  cout << ans.size() << "\n";
  for (auto [u, v] : ans)
    cout << u << " " << v << "\n";
}