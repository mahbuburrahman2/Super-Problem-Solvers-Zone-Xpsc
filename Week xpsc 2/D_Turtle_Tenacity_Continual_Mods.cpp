#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    sort(a.begin(), a.end());

    if (a[0] != a[1])
    {
      cout << "YES\n";
      continue;
    }

    bool ok = false;
    for (int i = 1; i < n; i++)
    {
      if (a[i] % a[0] != 0)
      {
        ok = true;
        break;
      }
    }

    cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}
