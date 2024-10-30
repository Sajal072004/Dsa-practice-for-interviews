#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int x, y, k;
        cin >> x >> y >> k;
        int len = min(x, y);

        int Ax = 0, Ay = 0, Bx = len, By = len;
        int Cx = 0, Cy = len, Dx = len, Dy = 0;

        cout << Ax << " " << Ay << " " << Bx << " " << By << '\n';
        cout << Cx << " " << Cy << " " << Dx << " " << Dy << '\n';
    }
}
