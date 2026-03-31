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
    ll b, c, d;
    cin >> b >> c >> d;

    ll x = b ^ d;

    ll val = (x | b) - (x & c);

    if (val == d)
      cout << x << "\n";
    else
      cout << -1 << "\n";
  }

  return 0;
}
