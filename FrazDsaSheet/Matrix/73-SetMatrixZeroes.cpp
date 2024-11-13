class Solution
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> row(m, 1);
    vector<int> col(n, 1);

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (matrix[i][j] == 0)
        {
          row[i] = 0;
          col[i] = 0;
        }
      }
    }

    for (int i = 0; i < row.size(); i++)
    {
      if (row[i] == 0)
      {
        for (int j = 0; j < n; j++)
          matrix[i][j] = 0;
      }
    }
    for (int i = 0; i < col.size(); i++)
    {
      if (col[i] == 0)
      {
        for (int j = 0; j < m; j++)
          matrix[j][i] = 0;
      }
    }
  }
};