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

    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
      int a;
      cin >> a;
      if (a <= n)
        cnt[a]++;
    }

    vector<int> hit(n + 1, 0);

    for (int d = 1; d <= n; d++)
    {
      if (cnt[d] == 0)
        continue;
      for (int x = d; x <= n; x += d)
      {
        hit[x] += cnt[d];
      }
    }

    int ans = 0;
    for (int x = 1; x <= n; x++)
      ans = max(ans, hit[x]);

    cout << ans << '\n';
  }

  return 0;
}
