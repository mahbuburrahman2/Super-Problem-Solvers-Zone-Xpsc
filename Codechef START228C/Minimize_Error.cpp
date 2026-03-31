#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  ll n, q;
  cin >> n >> q;

  ll K = (n + q) / (q + 1);
  ll ans = K / 2;

  cout << ans << "\n";
}

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tc;
  cin >> tc;
  while (tc--)
  {
    solve();
  }
  return 0;
}