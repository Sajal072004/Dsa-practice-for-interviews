#include <bits/stdc++.h>
using namespace std;

void solve(int from, int to, int aux, vector<pair<int, int>> &ans, int n)
{
  if (n == 0)
    return;

  solve(from, aux, to, ans, n - 1);
  ans.push_back({from, to});
  solve(aux, to, from, ans, n - 1);
}

int main()
{
  int n;
  cin >> n;
  vector<pair<int, int>> ans;
  solve(1, 3, 2, ans, n);
  cout << ans.size() << endl;
  for (auto x : ans)
    cout << x.first << " " << x.second << endl;
}