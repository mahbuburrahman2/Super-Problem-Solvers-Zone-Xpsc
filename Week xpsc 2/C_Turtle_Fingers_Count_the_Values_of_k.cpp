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
    ll a, b, l;
    cin >> a >> b >> l;

    set<ll> s;

    ll curA = 1;
    while (l % curA == 0)
    {

      ll curB = 1;
      while (l % (curA * curB) == 0)
      {

        s.insert(l / (curA * curB));
        curB *= b;
      }

      curA *= a;
    }

    cout << s.size() << '\n';
  }
}
