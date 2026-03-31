#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  int k;
  cin >> k;
  while (k--)
  {
    int n;
    string s;
    cin >> n >> s;
    int c = 0;
    if (s[0] == '1')
      c++;
    for (int i = 0; i < n - 1; i++)
    {
      if (s[i] != s[i + 1])
        c++;
    }
    int ans = n;

    if (c != 0)
      ans += max(1, c - 2);

    cout << ans << endl;
  }
  return 0;
}