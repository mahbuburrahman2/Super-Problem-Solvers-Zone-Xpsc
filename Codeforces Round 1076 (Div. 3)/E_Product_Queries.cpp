#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  while (tc--)
  {
    int n;
    cin >> n;

    vector<int> a(n), cnt(n + 1, 0);
    for (int &x : a)
    {
      cin >> x;
      cnt[x]++;
    }

    vector<int> dp(n + 1, INF);

    for (int i = 1; i <= n; i++)
      if (cnt[i])
        dp[i] = 1;

    for (int x = 1; x <= n; x++)
    {
      if (!cnt[x])
        continue;
      for (int m = x * 2; m <= n; m += x)
      {
        if (dp[m / x] != INF)
          dp[m] = min(dp[m], dp[m / x] + 1);
      }
    }

    for (int i = 1; i <= n; i++)
    {
      if (dp[i] == INF)
        cout << -1 << ' ';
      else
        cout << dp[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
