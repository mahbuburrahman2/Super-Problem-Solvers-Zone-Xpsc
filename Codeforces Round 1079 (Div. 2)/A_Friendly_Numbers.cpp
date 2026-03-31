#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll n)
{
  ll sum = 0;
  while (n > 0)
  {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--)
  {
    ll x;
    cin >> x;

    ll ans = 0;

    ll y = x;

    while (y <= x + 90)
    {
      if (y - solve(y) == x)
        ans++;

      y++;
    }
    cout << ans << "\n";
  }
  return 0;
}
