#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU
{
  vector<int> par, rnk, siz;
  DSU(int n) : par(n + 1, -1), rnk(n + 1, 0), siz(n + 1, 1)
  {
    for (int i = 1; i <= n; i++)
    {
      par[i] = i;
    }
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
    return siz[find(u)]
  }
  void marge(int u, int v)
  {
    if (u = find(u))
      == (v = find(v))
      {
        return;
      }
    if (rnk[u] > rnk[v])
    {
      swap(u, v);
    }
    else if (rnk[u] == rnk[v])
    {
      rnk[v]++;
    }
    par[u] = par[v];
    siz[v] = siz[u];
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  return 0;
}
