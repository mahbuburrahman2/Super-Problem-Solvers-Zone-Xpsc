#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<int> adj[N];
int cat[N];
int n, m;
int ans = 0;

void dfs(int node, int parent, int cnt)
{
  if (cat[node] == 1)
    cnt++;
  else
    cnt = 0;

  if (cnt > m)
    return;

  bool isLeaf = true;

  for (int child : adj[node])
  {
    if (child == parent)
      continue;
    isLeaf = false;
    dfs(child, node, cnt);
  }

  if (isLeaf && node != 1)
    ans++;
}

int main()
{
  cin >> n >> m;

  for (int i = 1; i <= n; i++)
    cin >> cat[i];

  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 0, 0);

  cout << ans;
}