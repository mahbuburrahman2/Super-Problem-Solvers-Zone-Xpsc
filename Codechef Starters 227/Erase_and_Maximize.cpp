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
    ll n, s;
    cin >> n >> s;

    ll mx = 6 * n;
    ll lmt = 5 * n;

    if (s <= lmt)
    {
      cout << mx << '\n';
    }
    else
    {
      cout << mx - (s - lmt) << '\n';
    }
  }
  return 0;
}