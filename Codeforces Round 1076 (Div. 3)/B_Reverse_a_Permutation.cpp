#include <bits/stdc++.h>
using namespace std;

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

    vector<int> p(n), pos(n + 1), smx(n); // max suffix
    for (int i = 0; i < n; i++)
    {
      cin >> p[i];
      pos[p[i]] = i;
    }

    smx[n - 1] = p[n - 1];
    for (int i = n - 2; i >= 0; i--)
      smx[i] = max(smx[i + 1], p[i]);

    for (int i = 0; i < n; i++)
    {
      if (smx[i] > p[i])
      {
        int r = pos[smx[i]];
        reverse(p.begin() + i, p.begin() + r + 1);
        break;
      }
    }

    for (int x : p)
      cout << x << ' ';
    cout << '\n';
  }
  return 0;
}
