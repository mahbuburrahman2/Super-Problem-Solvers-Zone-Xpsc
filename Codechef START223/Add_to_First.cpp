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
    int n;
    cin >> n;

    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];

    ll mx = -1;
    bool ok = true;

    for (int i = 0; i < n; i++)
    {
      if (a[i] > b[i])
      {
        ok = false;
        break;
      }

      if (b[i] > a[i] && a[i] <= mx)
      {
        ok = false;
        break;
      }

      mx = max(mx, a[i]);
    }

    if (ok)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
