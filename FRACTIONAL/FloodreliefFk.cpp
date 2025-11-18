#include <iostream>
using namespace std;

int main() {
    int n;
    float capacity;

    cout << "Enter number of packages: ";
    cin >> n;

    float weight[20], benefit[20], ratio[20];
    int id[20];  // store original package numbers

    cout << "Enter weight and benefit of each package:\n";
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> benefit[i];
        ratio[i] = benefit[i] / weight[i];
        id[i] = i + 1;  // store original ID
    }

    cout << "Enter truck capacity: ";
    cin >> capacity;

    // Sort by ratio in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {

                // swap ratio
                float temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                // swap weight
                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                // swap benefit
                temp = benefit[i];
                benefit[i] = benefit[j];
                benefit[j] = temp;

                // swap ID (important!)
                int t = id[i];
                id[i] = id[j];
                id[j] = t;
            }
        }
    }

     cout << "\nRatios in Descending Order :\n";
    for (int i = 0; i < n; i++) {
        cout << "Packages " << id[i] 
             << " = Ratio: " << ratio[i] << endl;
    }

    float totalBenefit = 0;
    float totalWeight = 0;

    cout << "\nSelected Packages:\n";

    for (int i = 0; i < n && capacity > 0; i++) {

        if (weight[i] <= capacity) {
            cout << "Package " << id[i] << " taken fully\n";
            totalBenefit += benefit[i];
            totalWeight += weight[i];
            capacity -= weight[i];
        }
        else {
            float fraction = capacity / weight[i];
            cout << "Package " << id[i] 
                 << " taken fraction: " << fraction << endl;

            totalBenefit += benefit[i] * fraction;
            totalWeight += weight[i] * fraction;
            capacity = 0;
        }
    }

    cout << "\nTotal Weight Used: " << totalWeight << endl;
    cout << "Total Benefit Obtained: " << totalBenefit << endl;
    cout << "\nRatios in Descending Order:\n";
       

    return 0;
}












