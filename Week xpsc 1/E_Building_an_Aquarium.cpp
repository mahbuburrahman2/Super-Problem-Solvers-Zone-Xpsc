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
    int n;
    ll x;
    cin >> n >> x;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    auto ok = [&](ll h)
    {
      ll sum = 0;
      for (int i = 0; i < n; i++)
      {
        if (h > a[i])
        {
          sum += h - a[i];
          if (sum > x)
            return false;
        }
      }
      return sum <= x;
    };

    ll l = 1, r = 2e9, ans = 0;
    while (l <= r)
    {
      ll mid = l + (r - l) / 2;
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
