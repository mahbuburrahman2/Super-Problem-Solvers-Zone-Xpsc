#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;
const int MAXN = 200005;

vector<int> g[MAXN];
int sz[MAXN];
ll nodes, edges;
int n;

void dfs(int u, int p)
{
  sz[u] = 1;
  ll prod = 1;

  for (int v : g[u])
  {
    if (v == p)
      continue;

    dfs(v, u);
    sz[u] += sz[v];

    prod = prod * (sz[v] + 1) % MOD;

    ll s1 = sz[v];
    ll s2 = n - sz[v];
    edges = (edges + ((s1 + 1) * (s2 + 1) - 1 + MOD) % MOD) % MOD;
  }

  if (p != -1)
    prod = prod * (n - sz[u] + 1) % MOD;

  nodes = (nodes + (2 * prod - 1 + MOD) % MOD) % MOD;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--)
  {
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
      g[i].clear();
    }

    for (int i = 1; i < n; i++)
    {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    nodes = edges = 0;
    dfs(1, 0);

    cout << (nodes - edges + MOD) % MOD << "\n";
  }

  return 0;
}