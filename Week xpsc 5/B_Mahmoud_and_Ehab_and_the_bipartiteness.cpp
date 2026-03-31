#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> g[100005];
int color[100005];

void dfs(int u, int c)
{
  color[u] = c;
  for (int v : g[u])
  {
    if (!color[v])
      dfs(v, 3 - c);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, 1);

  ll c1 = 0, c2 = 0;
  for (int i = 1; i <= n; i++)
  {
    if (color[i] == 1)
      c1++;
    else
      c2++;
  }

  ll max_add = c1 * c2 - (n - 1);
  cout << max_add << "\n";

  return 0;
}
