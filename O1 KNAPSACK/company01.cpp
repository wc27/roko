#include <iostream>
using namespace std;

int main() {
    int n, B;
    cout << "Enter number of projects: ";
    cin >> n;

    int cost[20], profit[20];
    cout << "Enter investment cost and expected profit for each project:\n";
    for (int i = 1; i <= n; i++)
        cin >> cost[i] >> profit[i];

    cout << "Enter maximum budget: ";
    cin >> B;

    int dp[20][50] = {0}; // dp[i][w] = max profit using first i projects within budget w

    // Build DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= B; w++) {
            if (cost[i] <= w)
                dp[i][w] = max(profit[i] + dp[i-1][w - cost[i]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    int maxProfit = dp[n][B];
    cout << "\nMaximum Profit Achieved: " << maxProfit << endl;

    // Backtrack to find selected projects
    int w = B;
    cout << "Selected Projects: ";
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i-1][w]) {
            cout << i << " ";
            w -= cost[i];
        }
    }

    cout << "\nTotal Investment Used: " << B - w << endl;

    return 0;
}
