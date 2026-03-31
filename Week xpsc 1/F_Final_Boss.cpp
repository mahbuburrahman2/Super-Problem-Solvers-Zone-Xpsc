#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  while (tc--)
  {
    ll h;
    int n;
    cin >> h >> n;

    vector<ll> a(n), c(n);
    for (ll &x : a)
      cin >> x;
    for (ll &x : c)
      cin >> x;

    auto ok = [&](ll t)
    {
      ll dmg = 0;
      for (int i = 0; i < n; i++)
      {
        ll hit = 1 + (t - 1) / c[i];

        if (hit > (h + a[i] - 1) / a[i])
          hit = (h + a[i] - 1) / a[i];

        dmg += hit * a[i];
        if (dmg >= h)
          return true;
      }
      return false;
    };

    ll l = 1, r = 2e18, ans = r;
    while (l <= r)
    {
      ll mid = (l + r) >> 1;
      if (ok(mid))
      {
        ans = mid;
        r = mid - 1;
      }
      else
      {
        l = mid + 1;
      }
    }

    cout << ans << '\n';
  }
  return 0;
}
