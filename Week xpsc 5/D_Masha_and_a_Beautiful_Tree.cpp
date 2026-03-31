#include <bits/stdc++.h>
using namespace std;

const int maxN = 3e5 + 9;

int a[maxN];
bool ok;
int cnt;

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

    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    ok = false;
    cnt = 0;

    for (int k = 1; k < n; k <<= 1)
    {

      for (int i = 0; i < n; i += 2 * k)
      {

        if (abs(a[i] - a[i + k]) != k)
        {
          ok = true;
        }

        if (a[i] > a[i + k])
        {
          swap(a[i], a[i + k]);
          cnt++;
        }
      }
    }

    if (ok)
    {
      cout << -1 << '\n';
    }
    else
    {
      cout << cnt << '\n';
    }
  }

  return 0;
}
