#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll p1 = 131, mod1 = 1e9 + 7;
const ll p2 = 137, mod2 = 1e9 + 9;
const int N = 1e6 + 9;
ll pw1[N], pw2[N];

void prec()
{
  pw1[0] = pw2[0] = 1;
  for (int i = 1; i < N; i++)
  {
    pw1[i] = pw1[i - 1] * p1 % mod1;
    pw2[i] = pw2[i - 1] * p2 % mod2;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  prec();

  string s;
  cin >> s;
  int n = s.size();

  vector<ll> h1(n + 1, 0), h2(n + 1, 0);
  for (int i = 0; i < n; i++)
  {
    h1[i + 1] = (h1[i] + (ll)s[i] * pw1[i]) % mod1;
    h2[i + 1] = (h2[i] + (ll)s[i] * pw2[i]) % mod2;
  }

  auto get_h1 = [&](int l, int r) -> ll
  {
    return (h1[r + 1] - h1[l] + mod1) % mod1;
  };
  auto get_h2 = [&](int l, int r) -> ll
  {
    return (h2[r + 1] - h2[l] + mod2) % mod2;
  };

  for (int k = 1; k <= n; k++)
  {
    if (k == n)
    {
      cout << k << " ";
      continue;
    }

    ll lhs1 = get_h1(0, n - k - 1) % mod1 * pw1[k] % mod1;
    ll rhs1 = get_h1(k, n - 1) % mod1 * pw1[0] % mod1;

    ll lhs2 = get_h2(0, n - k - 1) % mod2 * pw2[k] % mod2;
    ll rhs2 = get_h2(k, n - 1) % mod2 * pw2[0] % mod2;

    if (lhs1 == rhs1 && lhs2 == rhs2)
      cout << k << " ";
  }

  return 0;
}
