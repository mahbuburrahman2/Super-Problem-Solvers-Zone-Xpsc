#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  ll nb, ns, nc;
  cin >> nb >> ns >> nc;

  ll pb, ps, pc;
  cin >> pb >> ps >> pc;

  ll r;
  cin >> r;

  ll cb = 0, cs = 0, cc = 0;
  for (char c : s)
  {
    if (c == 'B')
      cb++;
    else if (c == 'S')
      cs++;
    else
      cc++;
  }

  auto ok = [&](ll x)
  {
    ll pay = 0;
    pay += max(0LL, cb * x - nb) * pb;
    pay += max(0LL, cs * x - ns) * ps;
    pay += max(0LL, cc * x - nc) * pc;
    return pay <= r;
  };

  ll l = 0, rgt = 1e13, ans = 0;
  while (l <= rgt)
  {
    ll mid = (l + rgt) / 2;
    if (ok(mid))
    {
      ans = mid;
      l = mid + 1;
    }
    else
    {
      rgt = mid - 1;
    }
  }

  cout << ans << '\n';
  return 0;
}
