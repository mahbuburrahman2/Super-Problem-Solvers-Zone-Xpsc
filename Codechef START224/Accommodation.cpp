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
    ll b, g, x, y, n;
    cin >> b >> g >> x >> y >> n;

    if (x + y > n)
    {
      cout << -1 << "\n";
      continue;
    }

    ll all = b + g;

    ll k = (all + n - 1) / n;

    int ans;
    if (b < k * x || g < k * y)
      ans = -1;
    else
      ans = k;

    cout << ans << "\n";
  }

  return 0;
}
