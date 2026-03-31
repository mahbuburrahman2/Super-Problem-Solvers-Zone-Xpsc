#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
  cin >> t;
  while (t--)
  {
    ll n, k;
    cin >> n >> k;

    ll x = n + k;

    ll sum1 = x * (x - 1) / 2;
    ll sum2 = k * (k - 1) / 2;

    ll p = sum1 + sum2;

    ll s = sqrt(p);

    ll ans = min(
        llabs(p - s * (s - 1)),
        llabs(p - s * (s + 1)));
    cout << ans << '\n';
  }

  return 0;
}
