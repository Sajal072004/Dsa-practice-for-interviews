// approach - just store the previous different character and compare
class Solution
{
public:
  int countKeyChanges(string s)
  {
    char x = s[0];
    int cnt = 0;
    for (int i = 1; i < s.size(); i++)
    {
      if (toupper(s[i]) == toupper(x))
      {
        continue;
      }
      else
      {
        cnt++;
        x = s[i];
      }
    }
    return cnt;
  }
};