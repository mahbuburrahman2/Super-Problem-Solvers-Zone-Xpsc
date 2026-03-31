#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, x, y;
  cin >> n >> x >> y;

  ll first = min(x, y);
  ll need = n - 1;

  auto ok = [&](ll mid)
  {
    ll dupli = mid / x + mid / y;
    return dupli >= need;
  };

  ll l = 0, r = max(x, y) * need;
  ll ans = r;

  while (l <= r)
  {
    ll mid = l + (r - l) / 2;
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

  cout << first + ans << "\n";
  return 0;
}
