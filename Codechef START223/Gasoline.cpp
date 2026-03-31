#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 998244353;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--)
  {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
      cin >> A[i];

    vector<int> L(N), R(N);
    stack<int> st;

    // Previous smaller
    for (int i = 0; i < N; i++)
    {
      while (!st.empty() && A[st.top()] >= A[i])
        st.pop();
      L[i] = st.empty() ? -1 : st.top();
      st.push(i);
    }

    while (!st.empty())
      st.pop();

    // Next smaller or equal
    for (int i = N - 1; i >= 0; i--)
    {
      while (!st.empty() && A[st.top()] > A[i])
        st.pop();
      R[i] = st.empty() ? N : st.top();
      st.push(i);
    }

    long long ans = 0;

    for (int i = 0; i < N; i++)
    {
      long long left = i - L[i];
      long long right = R[i] - i;

      // total usable length limited by K
      long long maxlen = min((long long)K, left + right - 1);

      long long cnt;
      if (maxlen <= min(left, right))
      {
        cnt = maxlen * (maxlen + 1) / 2;
      }
      else
      {
        long long small = min(left, right);
        long long big = max(left, right);
        cnt = small * (small + 1) / 2;
        long long rem = min(maxlen, big) - small;
        cnt += rem * small;
      }

      cnt %= MOD;
      ans = (ans + cnt * A[i]) % MOD;
    }

    cout << ans << '\n';
  }
  return 0;
}
