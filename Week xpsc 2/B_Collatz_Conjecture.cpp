#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll x, y, k;
int tc;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> tc;
  while (tc--)
  {
    cin >> x >> y >> k;

    while (k && x > 1)
    {
      ll add = y - (x % y);
      if (add > k)
        add = k;

      x += add;
      k -= add;

      while (x % y == 0)
        x /= y;
    }
    k %= (y - 1);
    cout << x + k << '\n';
  }

  return 0;
}
