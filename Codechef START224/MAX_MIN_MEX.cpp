#include <bits/stdc++.h>
using namespace std;
using ll = long long;
long long MOD = 998244353;

void solve()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a)
    cin >> x;
  sort(a.begin(), a.end());

  vector<int> bl;
  int len = 1;
  for (int i = 1; i < n; i++)
  {
    if (a[i] == a[i - 1] + 1)
      len++;
    else
    {
      bl.push_back(len);
      len = 1;
    }
  }
  bl.push_back(len);

  int mx_k = 0;
  for (int b : bl)
    mx_k = max(mx_k, b);

  ll cnt = 0;
  for (int b : bl)
    if (b == mx_k)
      cnt++;

  ll ans = cnt;
  for (int i = 0; i < mx_k - 1; i++)
    ans = (ans * 2) % MOD;
  for (int i = 1; i <= n - mx_k; i++)
    ans = (ans * i) % MOD;

  cout << (n == 0 ? 0 : ans) << "\n";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tc;
  cin >> tc;
  while (tc--)
    solve();
}