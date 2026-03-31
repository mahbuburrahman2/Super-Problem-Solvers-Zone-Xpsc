#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  int tc;
  cin >> tc;

  while (tc--)
  {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int cnt[26] = {0};

    for (auto &c : s)
    {
      c = tolower(c);
      cnt[c - 'a']++;
    }

    int mx1 = 0, mx2 = 0;

    for (int i = 0; i < 26; i++)
    {
      if (cnt[i] > mx1)
      {
        mx2 = mx1;
        mx1 = cnt[i];
      }
      else if (cnt[i] > mx2)
      {
        mx2 = cnt[i];
      }
    }

    int ans = mx1 + mx2;

    cout << ans << "\n";
  }

  return 0;
}
