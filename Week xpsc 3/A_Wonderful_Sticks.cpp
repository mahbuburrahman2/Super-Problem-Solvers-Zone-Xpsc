#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  int n;
  string str;
  cin >> n;
  cin >> str;
  vector<int> a(n);
  int i = 1;
  int j = n;
  int e = n - 1;
  for (int k = n - 2; k >= 0; k--)
  {
    if (str[k] == '<')
      a[e] = i++;
    else
      a[e] = j--;
    e--;
  }

  if (i == 0)
    a[e] = j;
  else
    a[e] = i;
  for (int s : a)
    cout << s << " ";
  cout << endl;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}