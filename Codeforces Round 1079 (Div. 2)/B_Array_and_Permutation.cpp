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

    vector<int> p(n + 1), a(n + 1), pos(n + 1);

    for (int i = 1; i <= n; i++)
    {
      cin >> p[i];
      pos[p[i]] = i;
    }

    for (int i = 1; i <= n; i++)
      cin >> a[i];

    map<int, int> mp;
    for (int i = 1; i <= n; i++)
      mp[pos[i]] = i;

    vector<int> o;
    for (auto &[k, x] : mp)
      o.push_back(x);

    int cur = 1;
    bool ok = true;

    for (int x : o)
    {
      if (cur > n)
        break;
      if (a[cur] != x)
        continue;
      while (cur <= n && a[cur] == x)
        cur++;
    }

    if (cur <= n)
      ok = false;

    if (ok)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}
