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

    bool ace = 0;

    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;

      if (x == 67)
        ace = 1;
    }

    if (ace)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}
