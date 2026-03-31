#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  int cnt = 0;

  for (ll i = 1; i <= n; i++)
  {
    ll tmp = i;
    int dgt = 0;

    while (tmp > 0)
    {
      dgt++;
      tmp /= 10;
    }

    if (dgt % 2 == 1)
    {
      cnt++;
    }
  }

  cout << cnt << "\n";

  return 0;
}