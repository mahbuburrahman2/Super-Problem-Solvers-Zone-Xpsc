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
    map<int, int> a;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      a[x]++;
    }

    multiset<int> ml;
    for (auto it : a)
    {
      ml.insert(it.second);
    }
    int sum = ml.size();

    for (auto i : ml)
    {
      if (k >= i)
      {
        sum--;
        k = k - i;
      }
    }

    if (sum < 1)
      cout << 1 << endl;
    else
      cout << sum << endl;
  }

  return 0;
}
