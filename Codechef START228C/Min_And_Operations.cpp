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

    set<int> a;
    for (int i = 1; i <= n; i++)
      a.insert(i);
    a.insert(0);

    ll ans = 0;

    for (int i = n; i >= 1; i--)
    {
      if (!a.count(i))
        continue;
      a.erase(i);

      auto it = a.lower_bound(i);
      if (it == a.begin())
      {
        ans += i;
        continue;
      }

      it--;
      int best_j = *it;

      if ((i & best_j) != 0 && !a.count(i & best_j))
      {
        best_j = 0;
      }

      ans += max(i, best_j);
      if (best_j != 0)
        a.erase(best_j);
    }

    cout << ans << "\n";
  }
  return 0;
}