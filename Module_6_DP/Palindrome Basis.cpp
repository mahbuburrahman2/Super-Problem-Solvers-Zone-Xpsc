#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxN = 4e4, N = 5e2, M = 4e4 + 9, MOD = 1e9 + 7;
ll dp[N][M];
vector<int> palin;

ll f(int i, int sum)
{
   if (i >= palin.size())
   {
      return (sum == 0);
   }

   if (dp[i][sum] != -1)
   {
      return dp[i][sum];
   }

   ll ans = 0;
   if (palin[i] <= sum)
   {
      ans += f(i, sum - palin[i]) % MOD;
   }
   ans += f(i + 1, sum) % MOD;

   return dp[i][sum] = ans % MOD;
}

void prec()
{
   for (int i = 1; i <= maxN; i++)
   {
      string s = to_string(i), t = s;
      reverse(s.begin(), s.end());
      if (s == t)
      {
         palin.push_back(i);
      }
   }
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   prec();
   memset(dp, -1, sizeof(dp));

   int t;
   cin >> t;
   while (t--)
   {
      int targetSum;
      cin >> targetSum;
      cout << f(0, targetSum) << '\n';
   }

   return 0;
}