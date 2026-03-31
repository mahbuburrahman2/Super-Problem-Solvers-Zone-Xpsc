#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAXN = 300005;

int n;
int left_child[MAXN], right_child[MAXN];
long long dp[MAXN], ans[MAXN];

void dfs1(int u)
{
  if (left_child[u] == 0 && right_child[u] == 0)
  {
    dp[u] = 1;
    return;
  }

  dfs1(left_child[u]);
  dfs1(right_child[u]);

  dp[u] = (dp[left_child[u]] + dp[right_child[u]] + 2) % MOD;
}

void dfs2(int u, long long parent_ans)
{
  if (u == 0)
    return;

  ans[u] = (parent_ans + dp[u]) % MOD;

  dfs2(left_child[u], ans[u]);
  dfs2(right_child[u], ans[u]);
}

void solve()
{
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> left_child[i] >> right_child[i];
  }

  dfs1(1);
  dfs2(1, 0);

  for (int i = 1; i <= n; i++)
  {
    cout << ans[i] << (i < n ? " " : "");
  }
  cout << "\n";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--)
  {
    solve();
  }

  return 0;
}