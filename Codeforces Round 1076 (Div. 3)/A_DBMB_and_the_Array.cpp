#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tcc;
  cin >> tcc;
  while (tcc--)
  {
    int n, s, x;
    cin >> n >> s >> x;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      int a;
      cin >> a;
      sum += a;
    }

    int dorkar = s - sum;
    if (dorkar >= 0 && dorkar % x == 0)

      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
