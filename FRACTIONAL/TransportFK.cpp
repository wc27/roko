#include <iostream>
using namespace std;

int main() {
    int n;
    float capacity;

    cout << "Enter number of cargo items: ";
    cin >> n;

    float weight[20], profit[20], ratio[20];
    int id[20];  // store original item numbers

    cout << "Enter weight and profit of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> profit[i];
        ratio[i] = profit[i] / weight[i];
        id[i] = i + 1;  // store original ID
    }

    cout << "Enter plane capacity: ";
    cin >> capacity;

    // Sort by ratio in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {

                float temp;

                // swap ratio
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                // swap weight
                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                // swap profit
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;

                // swap ID (important!)
                int t = id[i];
                id[i] = id[j];
                id[j] = t;
            }
        }
    }

    cout << "\nRatios in Descending Order:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << id[i] 
             << " = Ratio: " << ratio[i] << endl;
    }

    float totalProfit = 0;
    float totalWeight = 0;

    cout << "\nSelected Items:\n";

    for (int i = 0; i < n && capacity > 0; i++) {

        if (weight[i] <= capacity) {
            cout << "Item " << id[i] << " taken fully\n";
            totalProfit += profit[i];
            totalWeight += weight[i];
            capacity -= weight[i];
        }
        else {
            float fraction = capacity / weight[i];
            cout << "Item " << id[i] 
                 << " taken fraction: " << fraction << endl;

            totalProfit += profit[i] * fraction;
            totalWeight += weight[i] * fraction;
            capacity = 0;
        }
    }

    cout << "\nTotal Weight Loaded: " << totalWeight << endl;
    cout << "Maximum Profit Obtained: " << totalProfit << endl;

    return 0;
}
