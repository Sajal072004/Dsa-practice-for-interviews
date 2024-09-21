#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> numbers(n);
        for (int i = 0; i < n; ++i) {
            cin >> numbers[i];
        }

        if (n == 1) {
            cout << numbers[0] << endl;
            continue;
        }

        int totalSum = 0;
        for (int number : numbers) {
            totalSum += number;
        }

        int secondlast = numbers[n - 2];
        int result = totalSum - 2 * secondlast;

        cout << result << endl;
    }

    return 0;
}