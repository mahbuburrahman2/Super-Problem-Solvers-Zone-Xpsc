#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  while (tc--)
  {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    const int INF = 1e9;
    vector<int> dp(m, INF), pos(m, -1);

    for (int i = 0; i < n; i++)
    {
      for (int j = m - 1; j >= 0; j--)
      {
        if (s[i] != t[j])
          continue;

        if (j == 0)
        {
          if (dp[0] > 1 || (dp[0] == 1 && i > pos[0]))
          {
            dp[0] = 1;
            pos[0] = i;
          }
        }
        else if (dp[j - 1] != INF)
        {
          int add = (pos[j - 1] + 1 != i);
          int cand = dp[j - 1] + add;

          if (cand < dp[j] || (cand == dp[j] && i > pos[j]))
          {
            dp[j] = cand;
            pos[j] = i;
          }
        }
      }
    }

    if (dp[m - 1] == INF)
    {
      cout << -1 << '\n';
    }
    else
    {
      cout << dp[m - 1] - 1 << '\n';
    }
  }
  return 0;
}
