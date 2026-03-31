#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxN = 1e5 + 9;
const int inf = 2e9;

int n, k, h[maxN];
ll dp[maxN];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  for (int i = 1; i <= n; i++)
  {
    cin >> h[i];
  }
  dp[1] = 0;
  for (int i = 2; i <= n; i++)
  {
    dp[i] = 1e18;

    for (int j = 1; j <= k; j++)
    {
      if (i - j >= 1)
      {
        dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
      }
    }
  }
  cout << dp[n] << "\n";
  return 0;
}
