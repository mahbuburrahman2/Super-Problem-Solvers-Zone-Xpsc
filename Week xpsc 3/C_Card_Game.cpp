#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  int n;
  cin >> n;

  string s;
  cin >> s;

  int cntB = count(s.begin(), s.end(), 'B');

  bool bob = false;

  if (s[n - 1] == 'B' && cntB > 1)
    bob = true;

  if (s[0] == 'B' && s[n - 2] == 'B')
    bob = true;

  if (bob)
    cout << "Bob\n";
  else
    cout << "Alice\n";
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  while (tc--)
    solve();
  return 0;
}