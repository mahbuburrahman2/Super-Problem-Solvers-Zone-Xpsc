#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--)
  {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++)
      cin >> A[i];

    sort(A.begin(), A.end());

    vector<int> R(N);
    for (int i = 0; i < N; i++)
    {
      auto it = upper_bound(A.begin(), A.end(), 2 * A[i]);
      R[i] = distance(A.begin(), it) - 1;
    }

    vector<ll> p2(N + 1, 1);
    for (int i = 1; i <= N; i++)
      p2[i] = (p2[i - 1] * 2) % MOD;

    vector<ll> dp(N, 0), ways(N, 0);
    ll sum_dp = 0, sum_way = 0, total_ans = 0;
    int ptr = -1;

    for (int i = 0; i < N; i++)
    {
      while (ptr + 1 < i && 2 * A[ptr + 1] < A[i])
      {
        ptr++;
        ll weight = p2[R[ptr] - ptr];
        sum_way = (sum_way + ways[ptr] * weight) % MOD;
        sum_dp = (sum_dp + dp[ptr] * weight) % MOD;
      }

      ways[i] = (1 + sum_way) % MOD;
      dp[i] = (ways[i] + sum_dp) % MOD;

      ll cur = (dp[i] * p2[R[i] - i]) % MOD;
      total_ans = (total_ans + cur) % MOD;
    }

    cout << total_ans << "\n";
  }
}