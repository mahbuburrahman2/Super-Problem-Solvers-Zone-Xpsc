#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int ax, ay;
  cin >> ax >> ay;

  int bx, by;
  cin >> bx >> by;

  int cx, cy;
  cin >> cx >> cy;

  bool X = (bx > ax) == (cx > ax);
  bool Y = (by > ay) == (cy > ay);

  if (X && Y)
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}
