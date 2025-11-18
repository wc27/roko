#include <iostream>
using namespace std;

int main() {

    int n;
    float capital;

    cout << "Enter number of stocks: ";
    cin >> n;

    float invest[20], profit[20], ratio[20];
    int id[20];

    cout << "Enter investment amount and return (profit) for each stock:\n";
    for (int i = 0; i < n; i++) {
        cin >> invest[i] >> profit[i];
        ratio[i] = profit[i] / invest[i];   // return per unit investment
        id[i] = i + 1;
      
    }
   
     

    cout << "Enter total capital available: ";
    cin >> capital;

    // Sort based on ratio (descending)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {

                // swap ratio
                float temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                // swap investment
                temp = invest[i];
                invest[i] = invest[j];
                invest[j] = temp;

                // swap profit
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;

                // swap id
                int t = id[i];
                id[i] = id[j];
                id[j] = t;
            }
        }
          
    }

    cout << "\nRatios in Descending Order :\n";
    for (int i = 0; i < n; i++) {
        cout << "Stock " << id[i] 
             << " = Ratio: " << ratio[i] << endl;
    }

    float totalProfit = 0;
    float totalInvested = 0;
    
    
    cout << "\nSelected Stocks:\n";

    for (int i = 0; i < n && capital > 0; i++) {

        if (invest[i] <= capital) {
            // take full stock investment
            cout << "Stock " << id[i] << " taken fully\n";
            totalProfit += profit[i];
            totalInvested += invest[i];
            capital -= invest[i];
        }
        else {
            // take fractional investment
            float fraction = capital / invest[i];
            cout << "Stock " << id[i] << " taken fraction: " << fraction << endl;

            totalProfit += profit[i] * fraction;
            totalInvested += invest[i] * fraction;
            capital = 0;
        }
    }

    cout << "\nTotal Amount Invested: " << totalInvested << endl;
    cout << "Total Profit Earned: " << totalProfit << endl;
    return 0;
    
}

    



