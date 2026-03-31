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

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
      cin >> a[i];

    map<int, vector<int>> p, v;
    for (int i = 1; i <= n; i++)
    {
      int x = i;

      while (x % 2 == 0)
        x /= 2;

      p[x].push_back(i);
      v[x].push_back(a[i]);
    }

    bool ok = true;

    for (auto &it : p)
    {
      int k = it.first;

      auto &pl = p[k];
      auto &vl = v[k];

      sort(pl.begin(), pl.end());
      sort(vl.begin(), vl.end());

      if (pl != vl)
      {
        ok = false;
        break;
      }
    }

    if (ok)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}
