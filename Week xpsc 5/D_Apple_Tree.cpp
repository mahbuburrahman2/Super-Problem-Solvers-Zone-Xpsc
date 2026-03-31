#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 200005;

vector<int> g[N];
ll leaf[N];

ll dfs(int u, int p)
{
  if (g[u].size() == 1 && u != 1)
    return leaf[u] = 1;

  leaf[u] = 0;
  for (int v : g[u])
  {
    if (v == p)
      continue;
    leaf[u] += dfs(v, u);
  }
  return leaf[u];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
      g[i].clear();
      leaf[i] = 0;
    }

    for (int i = 0; i < n - 1; i++)
    {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    dfs(1, 0);

    int q;
    cin >> q;
    while (q--)
    {
      int x, y;
      cin >> x >> y;
      cout << leaf[x] * leaf[y] << "\n";
    }
  }

  return 0;
}
