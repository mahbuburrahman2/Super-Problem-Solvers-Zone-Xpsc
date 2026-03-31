#include <bits/stdc++.h>
using namespace std;

struct DSU
{
  vector<int> parent, rnk;

  DSU(int n)
  {
    parent.resize(n + 1);
    rnk.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
      parent[i] = i;
  }

  int find(int x)
  {
    if (parent[x] != x)
      parent[x] = find(parent[x]);
    return parent[x];
  }

  void unite(int a, int b)
  {
    a = find(a);
    b = find(b);
    if (a != b)
    {
      if (rnk[a] < rnk[b])
        swap(a, b);
      parent[b] = a;
      if (rnk[a] == rnk[b])
        rnk[a]++;
    }
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, k;
  cin >> n >> m >> k;

  // Read edges but we don't need them
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
  }

  vector<string> type(k);
  vector<int> u(k), v(k);

  for (int i = 0; i < k; i++)
    cin >> type[i] >> u[i] >> v[i];

  DSU dsu(n);
  vector<string> ans;

  for (int i = k - 1; i >= 0; i--)
  {
    if (type[i] == "ask")
    {
      if (dsu.find(u[i]) == dsu.find(v[i]))
        ans.push_back("YES");
      else
        ans.push_back("NO");
    }
    else
    { // cut -> reverse add
      dsu.unite(u[i], v[i]);
    }
  }

  reverse(ans.begin(), ans.end());

  for (auto &x : ans)
    cout << x << "\n";

  return 0;
}