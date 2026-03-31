#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll a[200001];

map<tuple<int, ll, int, int>, int> dp;

int f(int p, ll h, int x, int y)
{
  if (p == n + 1)
    return 0;

  auto state = make_tuple(p, h, x, y);
  if (dp.count(state))
    return dp[state];

  int ans = 0;

  if (a[p] < h)
  {
    ans = 1 + f(p + 1, h + (a[p] / 2), x, y);
  }
  else
  {
    int use2 = 0, use3 = 0;

    if (x > 0)
      use2 = f(p, h * 2, x - 1, y);

    if (y > 0)
      use3 = f(p, h * 3, x, y - 1);

    ans = max(use2, use3);
  }

  return dp[state] = ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--)
  {
    dp.clear();

    ll h;
    cin >> n >> h;

    for (int i = 1; i <= n; i++)
      cin >> a[i];

    sort(a + 1, a + n + 1);

    cout << f(1, h, 2, 1) << "\n";
  }

  return 0;
}