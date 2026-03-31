#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e6;
const int MOD = 1000003;

ll fact[N + 5];

// Binary Exponentiation (a^b % MOD)
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

// Modular Inverse using Fermat's Little Theorem
ll modInv(ll n)
{
  return binExp(n, MOD - 2);
}

// nCr = n! / (r! * (n-r)!)
ll nCr(ll n, ll r)
{
  ll numerator = fact[n];
  ll denominator = (fact[r] * fact[n - r]) % MOD;

  return (numerator * modInv(denominator)) % MOD;
}

// nPr = n! / (n-r)!
ll nPr(ll n, ll r)
{
  ll numerator = fact[n];
  ll denominator = fact[n - r];

  return (numerator * modInv(denominator)) % MOD;
}

void solve(int tc)
{
  ll n, r;
  cin >> n >> r;

  cout << "Case " << tc << ": ";
  cout << nCr(n, r) << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // Precompute factorials
  fact[0] = 1;
  for (ll i = 1; i <= N; i++)
  {
    fact[i] = (fact[i - 1] * i) % MOD;
  }

  int t;
  cin >> t;

  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }

  return 0;
}
