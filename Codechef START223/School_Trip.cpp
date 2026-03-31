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
    int n, x, k;
    cin >> n >> x >> k;

    int r = x % k;
    int ans = min(r, k - r);

    if (x + (k - r) > n)
      ans = r;
    cout << ans << "\n";
  }
  return 0;
}
