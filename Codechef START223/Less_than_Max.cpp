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
    int n;
    cin >> n;

    vector<int> dp(n + 2, 0);

    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;

      if (x == 1)
      {
        dp[1]++;
      }
      else if (dp[x - 1] > 0)
      {
        dp[x]++;
      }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
      ans += dp[i];

    cout << ans << "\n";
  }
  return 0;
}
