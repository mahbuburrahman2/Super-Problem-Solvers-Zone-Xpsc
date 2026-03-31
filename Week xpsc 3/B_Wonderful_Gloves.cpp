#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;
int t, n, k, l[N], r[N];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  while (t--)
  {
    ll ans = 0;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
      cin >> l[i];
    }

    for (int i = 1; i <= n; i++)
    {
      cin >> r[i];

      if (l[i] < r[i])
        swap(l[i], r[i]);

      ans += l[i];
    }

    sort(r + 1, r + 1 + n, greater<int>());

    for (int i = 1; i < k; i++)
      ans += r[i];

    cout << ans + 1 << "\n";
  }
  return 0;
}