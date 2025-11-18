#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of airlines: ";
    cin >> n;

    string airline[20];
    cout << "Enter airline names:\n";
    for (int i = 0; i < n; i++)
        cin >> airline[i];

    int adjList[20][20];
    int strength[20][20];
    int size[20] = {0};

    int p;
    cout << "Enter number of partnerships: ";
    cin >> p;

    cout << "Enter partnerships (A B strength):\n";
    for (int i = 0; i < p; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        adjList[a][size[a]] = b;
        strength[a][size[a]] = w;
        size[a]++;

        adjList[b][size[b]] = a;
        strength[b][size[b]] = w;
        size[b]++;
    }

    int choice;
    while (true) {
        cout << "\n--- LIST MENU ---\n";
        cout << "1. Check partnership\n";
        cout << "2. Display all connected airlines\n";
        cout << "3. Print adjacency list\n";
        cout << "4. Exit\n";
        cin >> choice;

        if (choice == 1) {
            int a, b;
            cin >> a >> b;

            bool found = false;
            for (int i = 0; i < size[a]; i++)
                if (adjList[a][i] == b)
                    found = true;

            if (found)
                cout << airline[a] << " and " << airline[b] << " HAVE a partnership.\n";
            else
                cout << airline[a] << " and " << airline[b] << " have NO partnership.\n";
        }

        else if (choice == 2) {
            int a;
            cin >> a;

            cout << "Airlines connected to " << airline[a] << ":\n";
            for (int i = 0; i < size[a]; i++)
                cout << " - " << airline[adjList[a][i]]
                     << " (Strength " << strength[a][i] << ")\n";
        }

        else if (choice == 3) {
            cout << "\nAdjacency List:\n";
            for (int i = 0; i < n; i++) {
                cout << i << ": ";
                for (int j = 0; j < size[i]; j++)
                    cout << adjList[i][j] << " ";
                cout << endl;
            }
        }

        else break;
    }
}
