#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

    int c = 0, ans = 0;

    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;

      if (x > 0)
      {
        c++;
        ans = max(ans, c);
      }
      else
      {
        c = 0;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
