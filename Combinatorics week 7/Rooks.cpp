#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll nCr(ll n, ll r)
{
  if (r > n)
    return 0;

  ll res = 1;
  for (ll i = 1; i <= r; i++)
  {
    res = res * (n - r + i) / i;
  }
  return res;
}

ll nPr(ll n, ll r)
{
  if (r > n)
    return 0;

  ll res = 1;
  for (ll i = 0; i < r; i++)
  {
    res *= (n - i);
  }
  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  for (int tc = 1; tc <= T; tc++)
  {
    ll n, k;
    cin >> n >> k;

    ll ans = 0;

    if (k <= n)
      ans = nCr(n, k) * nPr(n, k);

    cout << "Case " << tc << ": " << ans << "\n";
  }

  return 0;
}