#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t, n, a[2000005], b[2000005];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  while (t--)
  {
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
      b[i] = max(a[i], b[i - 1]);
    }
    for (int i = n; i >= 1; i--)
    {
      int cur = max(a[i], b[i - 1]);
      cout << sum + cur << " ";

      sum += a[i];
    }

    cout << endl;
  }
}