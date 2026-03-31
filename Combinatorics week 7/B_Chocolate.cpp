#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e6;
const int MOD = 1000003;

ll fact[N + 5];

ll binExp(ll a, ll b)
{
  if (b == 0)
    return 1 % MOD;

  ll x = binExp(a, b / 2);

  if (b & 1)
    return ((x * x) % MOD * a) % MOD;
  else
    return (x * x) % MOD;
}

ll modInv(ll n)
{
  return binExp(n, MOD - 2);
}

ll nCr(ll n, ll r)
{
  ll numerator = fact[n];
  ll denominator = (fact[r] * fact[n - r]) % MOD;

  return (numerator * modInv(denominator)) % MOD;
}

ll nPr(ll n, ll r)
{
  ll numerator = fact[n];
  ll denominator = fact[n - r];

  return (numerator * modInv(denominator)) % MOD;
}

void solve()
{
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  ll ans = 1;
  int last = -1;
  int ones = 0;

  for (int i = 0; i < n; i++)
  {
    if (a[i] == 1)
    {
      ones++;

      if (last != -1)
        ans *= (i - last);

      last = i;
    }
  }

  if (ones == 0)
    ans = 0;

  cout << ans << "\n";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  fact[0] = 1;
  for (ll i = 1; i <= N; i++)
    fact[i] = (fact[i - 1] * i) % MOD;

  solve();

  return 0;
}