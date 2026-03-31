#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU
{
  vector<int> par, rnk, siz;

  DSU(int n) : par(n + 1), rnk(n + 1, 0), siz(n + 1, 1)
  {
    for (int i = 1; i <= n; i++)
      par[i] = i;
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

  void merge(int u, int v)
  {
    u = find(u);
    v = find(v);

    if (u == v)
      return;

    if (rnk[u] > rnk[v])
      swap(u, v);

    par[u] = v;
    siz[v] += siz[u];

    if (rnk[u] == rnk[v])
      rnk[v]++;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int q;
  cin >> q;

  while (q--)
  {
    int n;
    cin >> n;

    vector<int> p(n + 1);

    for (int i = 1; i <= n; i++)
      cin >> p[i];

    DSU dsu(n);

    for (int i = 1; i <= n; i++)
      dsu.merge(i, p[i]);

    for (int i = 1; i <= n; i++)
      cout << dsu.getsize(i) << " ";

    cout << "\n";
  }

  return 0;
}