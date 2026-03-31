#include <bits/stdc++.h>
using namespace std;

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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
    }

    int dist = -1;

    for (int i = 2; i <= n; i++)
    {
      if (a[i] != a[1])
      {
        dist = i;
        break;
      }
    }

    if (dist == -1)
    {
      cout << "NO" << "\n";
    }
    else
    {
      cout << "YES" << "\n";
      for (int i = 2; i <= n; i++)
      {
        if (a[i] != a[1])
        {
          cout << 1 << " " << i << "\n";
        }
        else
        {
          cout << dist << " " << i << "\n";
        }
      }
    }
  }
  return 0;
}