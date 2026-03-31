#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  int n;
  cin >> n;
  vector<ll> f(n);
  for (int i = 0; i < n; i++)
    cin >> f[i];

  vector<ll> a(n);

  if (n == 2)
  {
    a[0] = f[1];
    a[1] = f[0];
  }
  else
  {
    for (int i = 1; i < n - 1; i++)
    {
      ll prv_f = f[i - 1];
      ll nxt_f = f[i + 1];
      ll cur_f = f[i];
      a[i] = (prv_f + nxt_f - 2 * cur_f) / 2;
    }

    ll sm_mid = 0;
    for (int i = 1; i < n - 1; i++)
    {
      sm_mid += a[i] * i;
    }
    a[n - 1] = (f[0] - sm_mid) / (n - 1);

    ll dif_1st = f[1] - f[0];
    ll dif_2nd = f[n - 1] - f[n - 2];
    a[0] = (dif_1st + dif_2nd + 2 * a[n - 1]) / 2;
  }

  for (int i = 0; i < n; i++)
  {
    if (i)
      cout << " ";
    cout << a[i];
  }
  cout << "\n";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  while (tc--)
    solve();
}
