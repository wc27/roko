#include <iostream>
using namespace std;

int main() {
    int n, B;
    cout << "Enter number of machines: ";
    cin >> n;

    int cost[20], gain[20];
    cout << "Enter upgrade cost and performance gain for each machine:\n";
    for (int i = 1; i <= n; i++)
        cin >> cost[i] >> gain[i];

    cout << "Enter total upgrade budget: ";
    cin >> B;

    int dp[20][50] = {0}; // dp[i][w] = max gain using first i machines within budget w

    // Build DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= B; w++) {
            if (cost[i] <= w)
                dp[i][w] = max(gain[i] + dp[i-1][w - cost[i]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    int maxGain = dp[n][B];
    cout << "\nMaximum Performance Gain: " << maxGain << endl;

    // Backtrack to find which machines were upgraded
    int w = B;
    cout << "Machines Selected for Upgrade: ";
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i-1][w]) {
            cout << i << " ";
            w -= cost[i];
        }
    }

    cout << "\nTotal Investment Made: " << B - w << endl;
    return 0;
}
  
