#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
      cin >> a[i];

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {

      for (int j = i + a[i]; j <= n && j <= i + a[i] * a[i]; j += a[i])
        if (a[i] * a[j] == j - i)
          ans++;

      for (int j = i - a[i]; j >= 1 && j > i - a[i] * a[i]; j -= a[i])
        if (a[i] * a[j] == i - j)
          ans++;
    }

    cout << ans << "\n";
  }
  return 0;
}