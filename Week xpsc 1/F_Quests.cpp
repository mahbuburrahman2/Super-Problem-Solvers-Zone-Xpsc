#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
  {
    ll n, c, d;
    cin >> n >> c >> d;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    sort(a.begin(), a.end(), greater<ll>());

    vector<ll> pref(n + 1, 0);
    for (int i = 0; i < n; i++)
      pref[i + 1] = pref[i] + a[i];

    if (pref[min(n, d)] >= c)
    {
      cout << "Infinity\n";
      continue;
    }

    auto ok = [&](ll k)
    {
      ll cycle = k + 1;
      ll total = (d / cycle) * pref[min(n, cycle)];
      total += pref[min(n, d % cycle)];
      return total >= c;
    };

    if (!ok(0))
    {
      cout << "Impossible\n";
      continue;
    }

    ll l = 0, r = d, ans = 0;
    while (l <= r)
    {
      ll mid = (l + r) / 2;
      if (ok(mid))
      {
        ans = mid;
        l = mid + 1;
      }
      else
      {
        r = mid - 1;
      }
    }

    cout << ans << '\n';
  }
  return 0;
}
