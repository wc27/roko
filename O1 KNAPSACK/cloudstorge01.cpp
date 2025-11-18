#include <iostream>
using namespace std;

int main() {
    int n, S;
    cout << "Enter number of files: ";
    cin >> n;

    int size[20], importance[20];
    cout << "Enter file size and importance value for each file:\n";
    for (int i = 1; i <= n; i++)
        cin >> size[i] >> importance[i];

    cout << "Enter total storage capacity (in GB): ";
    cin >> S;

    int dp[20][50] = {0}; // dp[i][w] = max importance using first i files within size limit w

    // Build DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= S; w++) {
            if (size[i] <= w)
                dp[i][w] = max(importance[i] + dp[i-1][w - size[i]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    int maxImportance = dp[n][S];
    cout << "\nMaximum Importance Achieved: " << maxImportance << endl;

    // Backtrack to find selected files
    int w = S;
    cout << "Selected Files: ";
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i-1][w]) {
            cout << i << " ";
            w -= size[i];
        }
    }

    cout << "\nTotal Storage Used: " << S - w << " GB" << endl;

    return 0;
}
