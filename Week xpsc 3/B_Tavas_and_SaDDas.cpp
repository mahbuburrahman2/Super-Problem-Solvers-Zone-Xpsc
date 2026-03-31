#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  ll ans = 0;

  for (char c : s)
  {
    ans *= 2;
    if (c == '7')
      ans++;
  }

  int len = s.size();

  ans += (1LL << len) - 1;

  cout << ans << '\n';

  return 0;
}
