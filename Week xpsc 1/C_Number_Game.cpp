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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
      cin >> x;

    sort(a.begin(), a.end());

    auto ok = [&](int k)
    {
      if (2 * k - 2 >= n)
        return false;

      int d = k, fast = 2 * k - 2, last = k - 1;

      for (int i = fast; i >= last; i--)
      {
        if (a[i] > d)
        {
          return false;
        }
        d--;
      }
      return true;
    };

    int ans = 0;
    for (int k = 0; k <= n; k++)
      if (ok(k))
        ans = k;

    cout << ans << '\n';
  }
  return 0;
}
