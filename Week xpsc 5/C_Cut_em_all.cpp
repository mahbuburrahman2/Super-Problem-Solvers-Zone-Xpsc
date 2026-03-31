#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<int> g[N];
int ans = 0;

int dfs(int u, int p)
{
  int sz = 1;
  for (int v : g[u])
  {
    if (v == p)
      continue;
    int child = dfs(v, u);
    if (child % 2 == 0)
      ans++;
    else
      sz += child;
  }
  return sz;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (n % 2)
  {
    cout << -1;
    return 0;
  }

  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, 0);
  cout << ans;

  return 0;
}
