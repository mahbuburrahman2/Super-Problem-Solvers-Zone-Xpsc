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
    ll ax, ay, bx, by;
    cin >> n >> ax >> ay >> bx >> by;

    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++)
      cin >> x[i];
    for (int i = 0; i < n; i++)
      cin >> y[i];

    map<ll, vector<ll>> mp;
    for (int i = 0; i < n; i++)
      mp[x[i]].push_back(y[i]);

    vector<pair<ll, ll>> pr;
    for (auto &it : mp)
    {
      auto &v = it.second;
      ll lo = *min_element(v.begin(), v.end());
      ll hi = *max_element(v.begin(), v.end());
      pr.push_back({lo, hi});
    }

    ll dpL = abs(ay - pr[0].second) + (pr[0].second - pr[0].first);
    ll dpR = abs(ay - pr[0].first) + (pr[0].second - pr[0].first);

    ll lastL = pr[0].first;
    ll lastR = pr[0].second;

    for (int i = 1; i < (int)pr.size(); i++)
    {
      ll lo = pr[i].first;
      ll hi = pr[i].second;
      ll span = hi - lo;

      ll hiL = dpL + abs(lastL - hi);
      ll hiR = dpR + abs(lastR - hi);
      ll loL = dpL + abs(lastL - lo);
      ll loR = dpR + abs(lastR - lo);

      ll newL = min(hiL, hiR) + span;
      ll newR = min(loL, loR) + span;

      dpL = newL;
      dpR = newR;
      lastL = lo;
      lastR = hi;
    }

    ll ok = min(
        dpL + abs(lastL - by),
        dpR + abs(lastR - by));

    ll ans = (bx - ax) + ok;
    cout << ans << '\n';
  }
  return 0;
}
