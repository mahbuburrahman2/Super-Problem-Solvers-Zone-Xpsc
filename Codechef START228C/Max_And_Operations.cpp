#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll inv2 = 500000004;

ll modpow(ll base, ll exp, ll mod)
{
  ll res = 1;
  base %= mod;
  while (exp > 0)
  {
    if (exp & 1)
      res = res * base % mod;
    base = base * base % mod;
    exp >>= 1;
  }
  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  while (tc--)
  {
    ll n, m;
    cin >> n >> m;

    vector<ll> powN(m + 2);
    for (ll i = 0; i <= m; ++i)
    {
      powN[i] = modpow(i, n, MOD);
    }

    ll sm_1_to_M = m % MOD * ((m + 1) % MOD) % MOD * inv2 % MOD;

    ll m_pow = modpow(m, n - 1, MOD);

    ll total_sum = n % MOD * m_pow % MOD * sm_1_to_M % MOD;

    ll sm_min = 0;
    for (ll k = 1; k <= m; ++k)
    {
      ll cnt_min_k = (powN[m - k + 1] - powN[m - k] + MOD) % MOD;

      ll contrib = cnt_min_k * (k % MOD) % MOD;

      sm_min = (sm_min + contrib) % MOD;
    }

    ll ans = (total_sum - sm_min + MOD) % MOD;
    cout << ans << "\n";
  }

  return 0;
}