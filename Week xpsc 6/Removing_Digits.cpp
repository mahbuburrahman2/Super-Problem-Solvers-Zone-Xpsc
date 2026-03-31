#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6 + 9;

int dp[maxN];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  dp[0] = 0;

  for (int i = 1; i <= n; i++)
  {
    dp[i] = 1e9;

    int x = i;
    while (x > 0)
    {
      int d = x % 10;
      x /= 10;

      if (d != 0)
      {
        dp[i] = min(dp[i], dp[i - d] + 1);
      }
    }
  }

  cout << dp[n] << '\n';

  return 0;
}