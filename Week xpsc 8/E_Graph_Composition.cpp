#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU
{
  vector<int> par;
  int cnt;

  DSU(int n) : par(n + 1), cnt(n)
  {
    iota(par.begin(), par.end(), 0);
  }

  int find(int i)
  {
    return (par[i] == i ? i : (par[i] = find(par[i])));
  }

  bool unite(int u, int v)
  {
    int root_u = find(u), root_v = find(v);
    if (root_u != root_v)
    {
      par[root_u] = root_v;
      cnt--;
      return true;
    }
    return false;
  }
};

void solve()
{
  int n, m1, m2;
  cin >> n >> m1 >> m2;

  vector<pair<int, int>> edgesF(m1);
  for (int i = 0; i < m1; i++)
    cin >> edgesF[i].first >> edgesF[i].second;

  DSU dsuG(n);
  for (int i = 0; i < m2; i++)
  {
    int u, v;
    cin >> u >> v;
    dsuG.unite(u, v);
  }

  DSU dsuF(n);
  int delet = 0;

  for (auto &edge : edgesF)
  {
    int u = edge.first;
    int v = edge.second;
    if (dsuG.find(u) == dsuG.find(v))
    {
      dsuF.unite(u, v);
    }
    else
    {
      delet++;
    }
  }

  int add = dsuF.cnt - dsuG.cnt;

  cout << delet + add << "\n";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}