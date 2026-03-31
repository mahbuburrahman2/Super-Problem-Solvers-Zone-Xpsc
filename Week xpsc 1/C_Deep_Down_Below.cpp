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
    ll n;
    cin >> n;
    vector<pair<ll, ll>> c(n);
    for (ll j = 1; j <= n; j++)
    {
      ll k;
      cin >> k;
      ll b = 0;
      for (ll j = 0; j < k; j++)
      {
        ll a;
        cin >> a;
        b = max(b, a - j + 1);
      }
      c[j - 1] = {b, k};
    }
    sort(c.begin(), c.end());
    ll ans = 0;
    ll q = 0;
    for (auto p : c)
    {
      ans = max(ans, p.first - q);
      q += p.second;
    }
    cout << ans << '\n';
  }
}
