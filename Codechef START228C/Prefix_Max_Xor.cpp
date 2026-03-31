#include <bits/stdc++.h>
using namespace std;
#define int long long

const int M = 998244353, N = 5e6 + 5;
int f[N], iF[N];

int pw(int a, int b)
{
  int r = 1;
  for (; b; b >>= 1, a = a * a % M)
    if (b & 1)
      r = r * a % M;
  return r;
}

int C(int n, int r) { return n < r ? 0 : f[n] * iF[r] % M * iF[n - r] % M; }

signed main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  f[0] = iF[0] = 1;
  for (int i = 1; i < N; i++)
    f[i] = f[i - 1] * i % M;
  iF[N - 1] = pw(f[N - 1], M - 2);
  for (int i = N - 2; i >= 0; i--)
    iF[i] = iF[i + 1] * (i + 1) % M;

  int t, n;
  for (cin >> t; t--;)
  {
    cin >> n;
    map<int, int> mp;
    for (int i = 0, x; i < n; i++)
      cin >> x, mp[-x]++;

    int v[30][2] = {}, tot = 0, den = f[n];
    for (auto [raw_x, y] : mp)
    {
      int x = -raw_x;
      den = den * iF[y] % M;
      if (!tot)
      {
        for (int i = 0; i < 30; i++)
          v[i][(x >> i & 1) & (y & 1)] = 1;
      }
      else
      {
        // OPTIMIZATION: Calculate even/odd sums once per group instead of 30*Y times
        int s[2] = {0, 0};
        for (int i = 0; i <= y; i++)
        {
          s[i & 1] = (s[i & 1] + C(y - i + tot - 1, tot - 1)) % M;
        }

        for (int j = 0; j < 30; j++)
        {
          int bit = (x >> j & 1);
          int v0 = v[j][0], v1 = v[j][1];
          if (!bit)
          {
            // If bit is 0, XOR parity never changes
            int total_ways = (s[0] + s[1]) % M;
            v[j][0] = v0 * total_ways % M;
            v[j][1] = v1 * total_ways % M;
          }
          else
          {
            // If bit is 1, parity of i flips the state
            v[j][0] = (v0 * s[0] + v1 * s[1]) % M;
            v[j][1] = (v0 * s[1] + v1 * s[0]) % M;
          }
        }
      }
      tot += y;
    }
    int ans = 0;
    for (int i = 0; i < 30; i++)
      ans = (ans + v[i][1] * (1LL << i)) % M;
    cout << ans * pw(den, M - 2) % M << "\n";
  }
}