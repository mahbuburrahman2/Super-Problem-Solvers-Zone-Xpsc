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
    int n, k;
    cin >> n >> k;

    vector<int> x(k);
    for (int i = 0; i < k; i++)
      cin >> x[i];

    sort(x.begin(), x.end());

    auto ok = [&](int mid)
    {
      ll used = 0;
      for (int i = k - mid; i < k; i++)
      {
        used += (n - x[i]);
        if (used >= n)
          return false;
      }
      return true;
    };

    int l = 0, r = k, ans = 0;
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
