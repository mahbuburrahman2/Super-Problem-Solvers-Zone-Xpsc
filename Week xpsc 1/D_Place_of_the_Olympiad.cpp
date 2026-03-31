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
    ll n, m, k;
    cin >> n >> m >> k;

    auto ok = [&](ll L)
    {
      ll blck = m / (L + 1);
      ll use = blck * L;

      ll rem = m % (L + 1);
      use += min(L, rem);

      return use * n >= k;
    };

    ll l = 1, r = m, ans = m;
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
