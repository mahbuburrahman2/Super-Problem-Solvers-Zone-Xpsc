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
    int x, y, z;
    cin >> x >> y >> z;

    int pair1 = min(x, z);
    int pair2 = y / 2;

    int ans = pair1 + pair2;
    cout << ans << "\n";
  }
  return 0;
}
