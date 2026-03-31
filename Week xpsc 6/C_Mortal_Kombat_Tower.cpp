#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 9;
int a[maxN];
int dp[maxN][2];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
    }

    dp[n + 1][0] = dp[n + 1][1] = 0;
    dp[n + 2][0] = dp[n + 2][1] = 0;

    for (int i = n; i >= 1; i--)
    {

      int cost1 = a[i];
      int cost2 = a[i] + a[i + 1];

      dp[i][0] = min(
          cost1 + dp[i + 1][1],
          cost2 + dp[i + 2][1]);

      dp[i][1] = min(
          dp[i + 1][0],
          dp[i + 2][0]);
    }

    cout << dp[1][0] << '\n';
  }

  return 0;
}