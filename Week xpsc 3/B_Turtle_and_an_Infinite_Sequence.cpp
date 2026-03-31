#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  int tc;
  cin >> tc;

  while (tc--)
  {
    int n, m;
    cin >> n >> m;

    int ans = n - m;
    if (ans < 0)
      ans = 0;

    int lmt = n + m;
    while (ans < lmt)
    {
      ans = ans | (ans + 1);
    }

    cout << ans << endl;
  }

  return 0;
}
