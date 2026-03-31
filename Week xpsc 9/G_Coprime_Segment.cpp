#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int ans = INT_MAX;

  vector<pair<ll, int>> prev;

  for (int i = 0; i < n; i++)
  {
    vector<pair<ll, int>> cur;

    cur.push_back({a[i], 1});

    for (auto [g, len] : prev)
    {
      ll new_g = __gcd(g, a[i]);

      if (cur.back().first == new_g)
      {
        cur.back().second = min(cur.back().second, len + 1);
      }
      else
      {
        cur.push_back({new_g, len + 1});
      }
    }

    for (auto [g, len] : cur)
    {
      if (g == 1)
      {
        ans = min(ans, len);
      }
    }

    prev = cur;
  }

  if (ans == INT_MAX)
    cout << -1 << '\n';
  else
    cout << ans << '\n';

  return 0;
}