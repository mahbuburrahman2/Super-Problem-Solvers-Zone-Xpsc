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
    ll n;
    cin >> n;

    ll l = 1, r = 2e9;
    while (r - l > 1)
    {
      ll m = (l + r) / 2;
      if (m * (m - 1) / 2 <= n)
        l = m;
      else
        r = m;
    }
    ll rem = n - (l * (l - 1) / 2);
    ll ans = l + rem;
    cout << ans << '\n';
  }
  return 0;
}
