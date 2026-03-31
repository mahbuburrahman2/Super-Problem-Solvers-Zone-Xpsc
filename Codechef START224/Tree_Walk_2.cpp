#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  vector<int> deg(n + 1, 0);
  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }

  if (n == 1)
  {
    cout << 1 << endl;
    return;
  }

  // Find path 1 to N
  vector<int> parent(n + 1, 0);
  vector<int> q = {1};
  parent[1] = -1;
  for (int i = 0; i < q.size(); i++)
  {
    int u = q[i];
    for (int v : adj[u])
    {
      if (!parent[v])
      {
        parent[v] = u;
        q.push_back(v);
      }
    }
  }

  vector<int> path;
  for (int cur = n; cur != -1; cur = parent[cur])
    path.push_back(cur);

  // The formula: sum(degree(v) for v in path excluding N) - (number of edges in path) + 1
  long long ans = 0;
  int edges_in_path = path.size() - 1;

  for (int i = 1; i < path.size(); i++)
  { // path[0] is N, so start from path[1]
    ans = (ans + deg[path[i]]) % 998244353;
  }

  ans = (ans - (edges_in_path - 1) + 998244353) % 998244353;

  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
}