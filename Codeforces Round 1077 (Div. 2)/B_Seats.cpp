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
    string s;
    cin >> n >> s;

    int ans = 0;

    // count existing students
    for (char c : s)
      if (c == '1')
        ans++;

    for (int i = 0; i < n;)
    {
      if (s[i] == '1')
      {
        i++;
        continue;
      }

      int j = i;
      while (j < n && s[j] == '0')
        j++;
      int len = j - i;

      if (i == 0 || j == n)
      {
        // edge segment
        ans += len / 2;
      }
      else
      {
        // middle segment
        ans += (len - 1) / 2;
      }

      i = j;
    }

    cout << ans << '\n';
  }
}
