#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  int n;
  string s;
  cin >> n >> s;

  int diff = 0;
  for (int i = 0; i < n / 2; i++)
    if (s[i] != s[n - 1 - i])
      diff++;

  for (int x = 0; x <= n; x++)
  {
    bool ok = false;

    if (x >= diff && x <= n - diff)
    {
      if (n % 2 == 1)
        ok = true;
      else if ((x - diff) % 2 == 0)
        ok = true;
    }

    if (ok)
      cout << '1';
    else
      cout << '0';
  }
  cout << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  while (tc--)
    solve();
}
