#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  int ans = 1;
  for (int bit = 0; bit <= 20; bit++)
  {
    int last = 0;
    for (int j = 1; j <= n; j++)
    {
      if ((a[j] >> bit) & 1)
      {
        ans = max(ans, j - last);
        last = j;
      }
    }
    if (last)
      ans = max(ans, n + 1 - last);
  }
  cout << ans << "\n";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
}
