#include <iostream>
using namespace std;

int main() {
    int n, B;
    cout << "Enter number of campaigns: ";
    cin >> n;

    int cost[20], reach[20];
    cout << "Enter cost and expected reach for each campaign:\n";
    for (int i = 1; i <= n; i++)
        cin >> cost[i] >> reach[i];

    cout << "Enter total budget: ";
    cin >> B;

    int dp[20][50] = {0}; // dp[i][w] = max reach using first i campaigns within budget w

    // Build table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= B; w++) {
            if (cost[i] <= w)
                dp[i][w] = max(reach[i] + dp[i-1][w - cost[i]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    int maxReach = dp[n][B];
    cout << "\nMaximum Reach Achieved: " << maxReach << endl;

    // Find selected campaigns
    int w = B;
    cout << "Selected Campaigns: ";
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i-1][w]) {
            cout << i << " ";
            w -= cost[i];
        }
    }

    cout << "\nTotal Cost Used: " << B - w << endl;
    return 0;
}
