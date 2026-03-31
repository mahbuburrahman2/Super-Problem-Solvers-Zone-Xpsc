#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<bool> prime(n + 1, true);
  vector<int> cnt(n + 1, 0);

  for (int i = 2; i * i <= n; i++)
  {
    if (prime[i])
    {
      for (int j = i + i; j <= n; j += i)
      {
        prime[j] = false;
      }
    }
  }
  for (int i = 2; i <= n; i++)
  {
    if (prime[i])
    {
      for (int j = i; j <= n; j += i)
      {
        cnt[j]++;
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    if (cnt[i] == 2)
    {
      ans++;
    }
  }

  cout << ans << '\n';
  return 0;
}
/*
10
2

21
8
*/