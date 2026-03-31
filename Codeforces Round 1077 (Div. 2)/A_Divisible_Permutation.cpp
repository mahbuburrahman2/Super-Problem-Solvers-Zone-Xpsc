#include <iostream>
using namespace std;

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;

    // Place 1 at the beginning, then n, then 2, 3, 4, ..., n-1
    cout << 1 << " " << n << " ";
    for (int i = 2; i < n; i++)
    {
      cout << i << " ";
    }
    cout << endl;
  }

  return 0;
}