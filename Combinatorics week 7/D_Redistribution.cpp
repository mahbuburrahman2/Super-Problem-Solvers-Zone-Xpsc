#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2005;
const int MOD = 1000000007;

ll fact[N + 5];

ll binExp(ll a, ll b)
{
  if (b == 0)
    return 1;
  ll x = binExp(a, b / 2);
  x = x * x % MOD;
  if (b & 1)
    x = x * a % MOD;
  return x;
}

ll modInv(ll n)
{
  return binExp(n, MOD - 2);
}

ll nCr(ll n, ll r)
{
  if (r < 0 || r > n)
    return 0;
  ll res = fact[n] * modInv(fact[r]) % MOD;
  res = res * modInv(fact[n - r]) % MOD;
  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  fact[0] = 1;
  for (ll i = 1; i <= N; i++)
    fact[i] = fact[i - 1] * i % MOD;

  int S;
  cin >> S;

  ll ans = 0;
  for (int k = 1; k * 3 <= S; k++)
  {
    ans = (ans + nCr(S - 2 * k - 1, k - 1)) % MOD;
  }

  cout << ans << "\n";
}