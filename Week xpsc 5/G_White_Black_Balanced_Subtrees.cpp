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

    vector<int> parent(n + 1), sum(n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
      cin >> parent[i];
    }

    string s;
    cin >> s;

    int ans = 0;

    for (int i = n; i >= 1; i--)
    {

      if (s[i - 1] == 'W')
        sum[i]++;
      else
        sum[i]--;

      if (i != 1)
        sum[parent[i]] += sum[i];

      if (sum[i] == 0)
        ans++;
    }

    cout << ans << "\n";
  }

  return 0;
}
