#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  ll ans = 0;

  for (ll i = 1; i < n; i++)
  {
    ll cnt = (n - 1) / i;
    ans += cnt;
  }

  cout << ans << "\n";

  return 0;
}