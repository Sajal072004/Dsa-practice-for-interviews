#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vpii vector<pair<int, int>>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
#define vin(arr, n)           \
  for (int i = 0; i < n; i++) \
    cin >> arr[i];
#define vout(arr)    \
  for (auto x : arr) \
    cout << x << " ";
#define fast_io                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);
#define vpin(arr, n)          \
  for (int i = 0; i < n; i++) \
  {                           \
    cin >> arr[i].first;      \
    cin >> arr[i].second;     \
  }

int main()
{
  fast_io;
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vi arr(n);
    vin(arr, n);

    int ans = 0;
    for (int i = 0; i + 1 < n; i++)
    {
      if (arr[i] == arr[i + 1])
        ans++;
    }

    for (int i = 0; i < n / 2; i++)
    {
      int temp = ans;
      if (arr[i] == arr[i + 1])
        temp--;
      if (arr[n - i - 1] == arr[n - i - 2])
        temp--;

      swap(arr[i], arr[n - i - 1]);

      if (arr[i] == arr[i + 1])
        temp++;
      if (arr[n - i - 1] == arr[n - i - 2])
        temp++;

      ans = min(ans, temp);

      swap(arr[i], arr[n - i - 1]);
    }

    cout << ans << endl;
  }
}
