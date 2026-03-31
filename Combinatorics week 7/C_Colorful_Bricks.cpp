#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int P = 998244353;
const int N = 2005;

ll fact[N], invFact[N];

ll modPow(ll a, ll b)
{
  ll res = 1;
  a %= P;
  while (b)
  {
    if (b & 1)
      res = res * a % P;
    a = a * a % P;
    b >>= 1;
  }
  return res;
}

ll modInv(ll x)
{
  return modPow(x, P - 2);
}

void init()
{
  fact[0] = 1;
  for (int i = 1; i < N; i++)
    fact[i] = fact[i - 1] * i % P;
  invFact[N - 1] = modInv(fact[N - 1]);
  for (int i = N - 2; i >= 0; i--)
    invFact[i] = invFact[i + 1] * (i + 1) % P;
}

ll C(int n, int k)
{
  if (k < 0 || k > n)
    return 0;
  return fact[n] * invFact[k] % P * invFact[n - k] % P;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  init();

  int n, m, k;
  cin >> n >> m >> k;

  ll ans = C(n - 1, k) * 1LL * m % P * modPow(m - 1, k) % P;
  cout << ans << "\n";

  return 0;
}