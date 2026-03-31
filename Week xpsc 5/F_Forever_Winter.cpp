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
    int n, m;
    cin >> n >> m;

    int deg[n + 1]{};
    int c = n;

    for (int i = 0; i < m; i++)
    {
      int u, v;
      cin >> u >> v;

      deg[u]++;
      if (deg[u] == 2)
        c--;

      deg[v]++;
      if (deg[v] == 2)
        c--;
    }

    int x = n - c - 1;
    int y = c / x;

    cout << x << " " << y << "\n";
  }
}
