#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int tc, n, x;
set<int> a;
int main()
{
  cin >> tc;
  while (tc--)
  {
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
      cin >> x;
      a.insert(x);
    }
    cout << a.size() << endl;
    a.clear();
  }

  return 0;
}
