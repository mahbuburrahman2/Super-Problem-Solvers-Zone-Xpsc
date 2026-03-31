#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> ans;

  if (n % 2 == 0)
  {
    for (int i = 0; i < n / 2; i++)
    {
      ans.push_back(2);
    }
  }
  else
  {
    ans.push_back(3);
    for (int i = 0; i < (n - 3) / 2; i++)
    {
      ans.push_back(2);
    }
  }

  cout << ans.size() << '\n';
  for (int x : ans)
  {
    cout << x << " ";
  }

  return 0;
}
