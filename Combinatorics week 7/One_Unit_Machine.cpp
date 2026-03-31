#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
const int N = 1000005;

ll fact[N], invFact[N];

ll modPow(ll a, ll b)
{
  ll res = 1;
  a %= MOD;
  while (b)
  {
    if (b & 1)
      res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

ll modInv(ll x)
{
  return modPow(x, MOD - 2);
}

void init()
{
  fact[0] = 1;
  for (int i = 1; i < N; i++)
    fact[i] = fact[i - 1] * i % MOD;
  invFact[N - 1] = modInv(fact[N - 1]);
  for (int i = N - 2; i >= 0; i--)
    invFact[i] = invFact[i + 1] * (i + 1) % MOD;
}

ll C(int n, int k)
{
  if (k < 0 || k > n)
    return 0;
  return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  init();
  int T;
  cin >> T;
  for (int cs = 1; cs <= T; cs++)
  {
    int n;
    cin >> n;
    vector<int> k(n);
    for (int i = 0; i < n; i++)
      cin >> k[i];

    ll ans = 1;
    int total = k[0];
    for (int i = 1; i < n; i++)
    {
      ans = ans * C(total + k[i] - 1, k[i] - 1) % MOD;
      total += k[i];
    }

    cout << "Case " << cs << ": " << ans << "\n";
  }
  return 0;
}