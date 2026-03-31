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

    int x;

    int OR = 0;
    int AND = (1 << 10) - 1;

    for (int i = 0; i < n; i++)
    {
      cin >> x;

      OR |= x;
      AND &= x;
    }

    cout << OR - AND << '\n';
  }

  return 0;
}
