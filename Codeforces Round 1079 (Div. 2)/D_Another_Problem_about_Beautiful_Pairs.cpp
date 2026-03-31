#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  int n;
  cin >> n;
  vector<ll> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  ll ans = 0;

  for (int i = 1; i <= n; i++)
  {
    if (a[i] >= n)
      continue;

    ll j = i + a[i];
    ll k = 1;
    while (j <= n)
    {
      if (a[j] == k)
        ans++;
      k++;
      j += a[i];
    }
  }

  cout << ans << "\n";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
