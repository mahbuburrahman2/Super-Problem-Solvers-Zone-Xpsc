#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2000005;
const ll MOD = 1000000007;

ll fact[N], invfact[N];

ll binExp(ll a, ll b)
{
  ll res = 1;
  while (b)
  {
    if (b & 1)
      res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}

ll nCr(ll n, ll r)
{
  if (r > n)
    return 0;
  return (((fact[n] * invfact[r]) % MOD) * invfact[n - r]) % MOD;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  fact[0] = 1;

  for (int i = 1; i < N; i++)
    fact[i] = (fact[i - 1] * i) % MOD;

  invfact[N - 1] = binExp(fact[N - 1], MOD - 2);

  for (int i = N - 2; i >= 0; i--)
    invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;

  int T;
  cin >> T;

  for (int tc = 1; tc <= T; tc++)
  {
    ll n, k;
    cin >> n >> k;

    ll ans = nCr(n + k - 1, k - 1);

    cout << "Case " << tc << ": " << ans << "\n";
  }

  return 0;
}