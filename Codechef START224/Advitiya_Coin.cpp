#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  int n;
  ll k;
  cin >> n >> k;

  vector<ll> p(n);
  for (int i = 0; i < n; i++)
    cin >> p[i];

  int ans = 0;
  int i = 0;
  while (i < n)
  {
    ll mn = p[i];
    ll mx = p[i];
    int j = i + 1;
    bool ok = false;

    while (j < n)
    {

      if (abs(p[j] - mn) > k || abs(p[j] - mx) > k)
      {
        ans++;
        i = j + 1;
        ok = true;
        break;
      }
      mn = min(mn, p[j]);
      mx = max(mx, p[j]);
      j++;
    }

    if (!ok)
      break;
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