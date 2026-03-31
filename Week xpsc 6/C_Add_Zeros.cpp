#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;

    vector<ll> a(n + 1);
    vector<pair<ll, ll>> v;

    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
      ll need = a[i] + i - 1;
      if (i > 1)
        v.push_back({need, i - 1});
    }

    sort(v.begin(), v.end());

    map<ll, ll> dp;

    for (int i = (int)v.size() - 1; i >= 0; i--)
    {
      ll need = v[i].first;
      ll add = v[i].second;

      dp[need] = max(dp[need], dp[need + add] + add);
    }

    cout << dp[n] + n << "\n";
  }
}