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
    ll a, b;
    cin >> a >> b;
    ll ans = a ^ b;
    cout << ans << '\n';
  }

  return 0;
}
