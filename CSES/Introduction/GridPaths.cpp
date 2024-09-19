// C++ Code
#include <bits/stdc++.h>
using namespace std;

// Macro to check if a coordinate is valid in the grid
#define isValid(a) (a >= 0 && a < 7 ? 1 : 0)

// Direction constants
#define right 0
#define left 1
#define down 2
#define up 3

// Direction vectors for right, left, down, and up
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

// The path description string
string str;
int vis[7][7];

// Function to count the number of paths that match the
// description
int countPaths(int x, int y, int pos)
{
    // If we have processed all characters in the string and
    // we are at the lower-left square, return 1
    if (pos == (int)str.length())
        return (x == 6 && y == 0);

    // If we have reached the lower-left square before
    // processing all characters, return 0
    if (x == 6 && y == 0)
        return 0;

    // If the current cell is already visited, return 0
    if (vis[x][y])
        return 0;

    // Array to keep track of the visited status of the
    // neighboring cells
   
    // Mark the current cell as visited
    vis[x][y] = 1;

    // Variable to store the number of paths
    int numberOfPaths = 0;

    // If the current character is '?', try all four
    // directions
    if (str[pos] == '?') {
        for (int k = 0; k < 4; k++)
            if (isValid(x + dx[k]) && isValid(y + dy[k]))
                numberOfPaths += countPaths(
                    x + dx[k], y + dy[k], pos + 1);
    }

    // If the current character is a direction, go in that
    // direction
    else if (str[pos] == 'R' && y + 1 < 7)
        numberOfPaths += countPaths(x, y + 1, pos + 1);
    else if (str[pos] == 'L' && y - 1 >= 0)
        numberOfPaths += countPaths(x, y - 1, pos + 1);
    else if (str[pos] == 'U' && x - 1 >= 0)
        numberOfPaths += countPaths(x - 1, y, pos + 1);
    else if (str[pos] == 'D' && x + 1 < 7)
        numberOfPaths += countPaths(x + 1, y, pos + 1);

    // Unmark the current cell
    vis[x][y] = 0;

    // Return the number of paths
    return numberOfPaths;
}

// Driver Code
int main()
{
    // Example 1:
    str = "??????R??????U??????????????????????????LD????"
          "D?";
    cout << countPaths(0, 0, 0) << endl;
}
