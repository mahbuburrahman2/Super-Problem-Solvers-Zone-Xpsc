#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  vector<int> x(m + 1);

  for (int i = 0; i <= m; i++)
  {
    cin >> x[i];
  }

  int f = x[m];
  int ans = 0;

  for (int i = 0; i < m; i++)
  {
    int d = x[i] ^ f;
    int cnt = __builtin_popcount(d);

    if (cnt <= k)
      ans++;
  }

  cout << ans << '\n';

  return 0;
}
