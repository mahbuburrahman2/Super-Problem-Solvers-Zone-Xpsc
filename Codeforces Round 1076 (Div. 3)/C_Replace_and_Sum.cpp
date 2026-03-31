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
    int n, q;
    cin >> n >> q;

    vector<ll> a(n + 1), b(n + 2);
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    for (int i = 1; i <= n; i++)
      cin >> b[i];

    vector<ll> suf(n + 2, 0);
    for (int i = n; i >= 1; i--)
      suf[i] = max(suf[i + 1], b[i]);

    while (q--)
    {
      int l, r;
      cin >> l >> r;

      ll ans = 0;
      for (int i = l; i <= r; i++)
      {
        ans += max(a[i], suf[i]);
      }
      cout << ans << ' ';
    }
    cout << '\n';
  }
  return 0;
}
