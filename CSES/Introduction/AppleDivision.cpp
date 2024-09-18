#include <bits/stdc++.h>
using namespace std;

long long solve(long long i, long long sum1 , long long sum2 , vector<long long>&arr){

if(i == arr.size()) return abs(sum1 - sum2);

long long notChoose = solve(i+1,sum1, sum2+arr[i],arr);
long long choose = solve(i+1,sum1+arr[i], sum2,arr);
return min(choose , notChoose);

}

int main()
{
  long long n;
  cin >> n;
  vector<long long> arr(n);
  long long sum = 0;
  for (long long i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  cout << solve(0,0,0,arr);
}