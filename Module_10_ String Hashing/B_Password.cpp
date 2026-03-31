#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;
  int n = s.size();

  vector<int> lps(n, 0);

  for (int i = 1; i < n; i++)
  {
    int j = lps[i - 1];

    while (j > 0 && s[i] != s[j])
    {
      j = lps[j - 1];
    }

    if (s[i] == s[j])
    {
      j++;
    }

    lps[i] = j;
  }

  int len = lps[n - 1];

  while (len > 0)
  {
    for (int i = 0; i < n - 1; i++)
    {
      if (lps[i] == len)
      {
        cout << s.substr(0, len);
        return 0;
      }
    }
    len = lps[len - 1];
  }

  cout << "Just a legend";
  return 0;
}