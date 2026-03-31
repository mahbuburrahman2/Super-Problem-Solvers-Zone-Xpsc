#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<ll> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  auto ok = [&](ll mid)
  {
    int cnt = 1;
    ll last = a[0];

    for (int i = 1; i < n; i++)
    {
      if (a[i] - last >= mid)
      {
        cnt++;
        last = a[i];
      }
    }
    return cnt >= k;
  };

  ll l = 0, r = a[n - 1] - a[0], ans = 0;

  while (l <= r)
  {
    ll mid = l + (r - l) / 2;
    if (ok(mid))
    {
      ans = mid;
      l = mid + 1;
    }
    else
    {
      r = mid - 1;
    }
  }

  cout << ans << '\n';
  return 0;
}
