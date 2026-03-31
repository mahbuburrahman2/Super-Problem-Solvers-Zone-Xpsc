#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int k, n;
  cin >> k >> n;

  vector<ll> a(n);
  ll sum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    sum += a[i];
  }

  ll lo = 0, hi = sum / k, ans = 0;

  while (lo <= hi)
  {
    ll mid = (lo + hi) / 2;
    ll cnt = 0;

    for (ll x : a)
      cnt += min(x, mid);

    if (cnt >= mid * k)
    {
      ans = mid;
      lo = mid + 1;
    }
    else
    {
      hi = mid - 1;
    }
  }
  cout << ans << "\n";
  return 0;
}
