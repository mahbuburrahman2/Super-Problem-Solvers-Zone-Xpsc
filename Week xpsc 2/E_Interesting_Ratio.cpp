#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e7;
vector<int> allPrimes;

void sieve()
{
  vector<bool> prime(maxN + 1, true);
  prime[0] = prime[1] = false;

  for (int i = 2; i * i <= maxN; i++)
  {
    if (prime[i])
    {
      for (int j = i + i; j <= maxN; j += i)
      {
        prime[j] = false;
      }
    }
  }

  for (int i = 2; i <= maxN; i++)
  {
    if (prime[i])
    {
      allPrimes.push_back(i);
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  sieve();

  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    long long ans = 0;
    for (int p : allPrimes)
    {
      if (p > n)
        break;
      ans += n / p;
    }
    cout << ans << '\n';
  }

  return 0;
}

/*4
5
10
34
10007

4
11
49
24317

*/