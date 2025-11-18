#include <iostream>
using namespace std;

int main() {
    int n;
    float timeLimit;

    cout << "Enter number of tasks: ";
    cin >> n;

    float timeReq[20], profit[20], ratio[20];
    int id[20];  // store original task numbers

    cout << "Enter execution time and profit for each task:\n";
    for (int i = 0; i < n; i++) {
        cin >> timeReq[i] >> profit[i];
        ratio[i] = profit[i] / timeReq[i];  // profit per time unit
        id[i] = i + 1;                      // store original ID
    }

    cout << "Enter total available server time: ";
    cin >> timeLimit;

    // Sort by ratio in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {

                float temp;

                // swap ratio
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                // swap timeReq
                temp = timeReq[i];
                timeReq[i] = timeReq[j];
                timeReq[j] = temp;

                // swap profit
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;

                // swap ID
                int t = id[i];
                id[i] = id[j];
                id[j] = t;
            }
        }
    }

    cout << "\nRatios in Descending Order:\n";
    for (int i = 0; i < n; i++) {
        cout << "Task " << id[i] 
             << " = Ratio: " << ratio[i] << endl;
    }

    float totalProfit = 0;
    float totalTime = 0;

    cout << "\nScheduled Tasks:\n";

    // Greedy Fractional Allocation
    for (int i = 0; i < n && timeLimit > 0; i++) {

        if (timeReq[i] <= timeLimit) {
            // take full task
            cout << "Task " << id[i] << " taken fully\n";
            totalProfit += profit[i];
            totalTime += timeReq[i];
            timeLimit -= timeReq[i];
        }
        else {
            // take fractional part
            float fraction = timeLimit / timeReq[i];
            cout << "Task " << id[i]
                 << " taken fraction: " << fraction << endl;

            totalProfit += profit[i] * fraction;
            totalTime += timeReq[i] * fraction;
            timeLimit = 0;
        }
    }

    cout << "\nTotal Time Used: " << totalTime << endl;
    cout << "Total Profit Achieved: " << totalProfit << endl;

    return 0;
}
