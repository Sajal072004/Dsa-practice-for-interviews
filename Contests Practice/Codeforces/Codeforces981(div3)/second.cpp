#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
#define fast_io                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);

int main()
{
  fast_io
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cin >> arr[i][j];
      }
    }

    int ans = 0;

    
    for (int start = 0; start < n; start++)
    {
      int x = 0, y = start; 
      int mini = INT_MAX;
      while (x < n && y < n)
      {
        mini = min(mini, arr[x][y]);
        x++;
        y++;
      }
      
      if (mini < 0)
      {
        ans += abs(mini);
      }
    }

    
    for (int start = 1; start < n; start++)
    {
      int x = start, y = 0;
      int mini = INT_MAX;
      while (x < n && y < n)
      {
        mini = min(mini, arr[x][y]);
        x++;
        y++;
      }
      
      if (mini < 0)
      {
        ans += abs(mini);
      }
    }

    cout << ans << endl;
  }
}
