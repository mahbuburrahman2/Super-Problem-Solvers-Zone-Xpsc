#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> col(n, 0);

  for (int i = 0; i < k; i++)
  {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++)
      col[j] |= 1 << (s[j] - 'a');
  }

  for (int d = 1; d <= n; d++)
    if (n % d == 0)
    {
      string base(d, '?');
      bool ok = 1;
      for (int i = 0; i < d; i++)
      {
        int mask = (1 << 26) - 1;
        for (int j = i; j < n; j += d)
          mask &= col[j];
        if (!mask)
        {
          ok = 0;
          break;
        }
        base[i] = 'a' + __builtin_ctz(mask);
      }
      if (ok)
      {
        for (int i = 0; i < n / d; i++)
          cout << base;
        cout << "\n";
        break;
      }
    }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--)
    solve();
}