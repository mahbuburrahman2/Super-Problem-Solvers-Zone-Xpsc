#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  vector<int> vd[7];
  for (int x = 1; x <= 6; x++)
    for (int y = 1; y <= 6; y++)
      if (x != y && x + y != 7)
        vd[x].push_back(y);

  while (tc--)
  {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
      cin >> x;

    vector<int> dp(7, INT_MAX);
    for (int x = 1; x <= 6; x++)
    {
      if (a[0] == x)
        dp[x] = 0;
      else
        dp[x] = 1;
    }

    for (int i = 1; i < n; i++)
    {
      vector<int> ndp(7, INT_MAX);
      for (int x = 1; x <= 6; x++)
      {
        int cost;
        if (a[i] == x)
          cost = 0;
        else
          cost = 1;

        for (int y : vd[x])
          if (dp[y] + cost < ndp[x])
            ndp[x] = dp[y] + cost;
      }
      for (int x = 1; x <= 6; x++)
        dp[x] = ndp[x];
    }

    int ans = dp[1];
    for (int x = 2; x <= 6; x++)
      if (dp[x] < ans)
        ans = dp[x];

    cout << ans << "\n";
  }
  return 0;
}
