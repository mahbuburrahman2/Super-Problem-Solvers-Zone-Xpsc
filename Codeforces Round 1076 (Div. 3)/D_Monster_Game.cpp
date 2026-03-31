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
    int n;
    cin >> n;

    vector<ll> a(n), b(n), p(n + 1, 0);
    for (auto &x : a)
      cin >> x;
    for (int i = 0; i < n; i++)
      cin >> b[i];

    sort(a.begin(), a.end());

    for (int i = 1; i <= n; i++)
      p[i] = p[i - 1] + b[i - 1];

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
      ll x = a[i];
      ll s = n - i;

      int l = upper_bound(p.begin(), p.end(), s) - p.begin() - 1;

      ans = max(ans, x * l);
    }

    cout << ans << '\n';
  }
  return 0;
}
