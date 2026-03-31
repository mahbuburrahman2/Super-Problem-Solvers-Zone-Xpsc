#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
  {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a)
      cin >> x;

    auto ok = [&](int x)
    {
      if (x == 0)
        return true;

      unordered_set<int> s;
      int seg = 0;

      for (int v : a)
      {
        if (v < x)
          s.insert(v);
        if ((int)s.size() == x)
        {
          seg++;
          s.clear();
        }
      }
      return seg >= k;
    };

    int l = 0, r = n, ans = 0;
    while (l <= r)
    {
      int mid = (l + r) / 2;
      if (ok(mid))
      {
        ans = mid;
        l = mid + 1;
      }
      else
      {
        r = mid - 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
