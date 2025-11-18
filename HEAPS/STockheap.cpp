#include <iostream>
using namespace std;

const int MAX = 100;

// Max Heap (Highest Price)
int maxHeap[MAX];
int maxSize = 0;

// Min Heap (Lowest Price)
int minHeap[MAX];
int minSize = 0;


// Insert into Max Heap
void insertMax(int price) {
    maxHeap[++maxSize] = price;
    int i = maxSize;

    // Heapify Up
    while (i > 1 && maxHeap[i] > maxHeap[i/2]) {
        int t = maxHeap[i];
        maxHeap[i] = maxHeap[i/2];
        maxHeap[i/2] = t;
        i /= 2;
    }
}

// Get Highest Price
int getMax() {
    if (maxSize == 0) return -1;
    return maxHeap[1];
}

// Delete Highest (Top) Price
void deleteMax() {
    if (maxSize == 0) return;

    maxHeap[1] = maxHeap[maxSize--];
    int i = 1;

    // Heapify Down
    while (true) {
        int left = 2*i, right = 2*i + 1;
        int largest = i;

        if (left <= maxSize && maxHeap[left] > maxHeap[largest])
            largest = left;
        if (right <= maxSize && maxHeap[right] > maxHeap[largest])
            largest = right;

        if (largest == i) break;

        int t = maxHeap[i];
        maxHeap[i] = maxHeap[largest];
        maxHeap[largest] = t;

        i = largest;
    }
}


void insertMin(int price) {
    minHeap[++minSize] = price;
    int i = minSize;

    // Heapify Up
    while (i > 1 && minHeap[i] < minHeap[i/2]) {
        int t = minHeap[i];
        minHeap[i] = minHeap[i/2];
        minHeap[i/2] = t;
        i /= 2;
    }
}

// Get Lowest Price
int getMin() {
    if (minSize == 0) return -1;
    return minHeap[1];
}

void deleteFromMinHeap(int value) {
    int newArr[MAX];
    int newSize = 0;

    // Copy all except the deleted value
    for (int i = 1; i <= minSize; i++) {
        if (minHeap[i] != value)
            newArr[++newSize] = minHeap[i];
    }

    minSize = newSize;

    // Copy back to main heap array
    for (int i = 1; i <= minSize; i++)
        minHeap[i] = newArr[i];

    // Reheapify (Bottom-up)
    for (int i = minSize/2; i >= 1; i--) {
        int j = i;

        while (true) {
            int left = 2*j, right = 2*j + 1;
            int smallest = j;

            if (left <= minSize && minHeap[left] < minHeap[smallest])
                smallest = left;
            if (right <= minSize && minHeap[right] < minHeap[smallest])
                smallest = right;

            if (smallest == j) break;

            int t = minHeap[j];
            minHeap[j] = minHeap[smallest];
            minHeap[smallest] = t;

            j = smallest;
        }
    }
}

int main() {
    int choice, price;

    while (true) {
        cout << "\n===== STOCK PRICE MENU =====\n";
        cout << "1. Insert Stock Price\n";
        cout << "2. Display Highest & Lowest Price\n";
        cout << "3. Delete Highest Price\n";
        cout << "4. Display Prices (Ascending & Descending)\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter stock price: ";
            cin >> price;
            insertMax(price);
            insertMin(price);
            cout << "Price inserted.\n";
        }

        else if (choice == 2) {
            if (maxSize == 0) cout << "No prices available.\n";
            else {
                cout << "Highest Price: " << getMax() << endl;
                cout << "Lowest Price: " << getMin() << endl;
            }
        }

        else if (choice == 3) {
            if (maxSize == 0) cout << "No prices to delete.\n";
            else {
                int highest = getMax();
                cout << "Deleted Highest Price: " << highest << endl;

                deleteMax();              // Remove from Max Heap
                deleteFromMinHeap(highest); // Remove from Min Heap
            }
        }

        else if (choice == 4) {
            if (maxSize == 0) cout << "No prices.\n";
            else {
                cout << "\nDescending Order (Max Heap): ";
                for (int i = 1; i <= maxSize; i++)
                    cout << maxHeap[i] << " ";

                cout << "\nAscending Order (Min Heap): ";
                for (int i = 1; i <= minSize; i++)
                    cout << minHeap[i] << " ";

                cout << endl;
            }
        }

        else if (choice == 5) {
            cout << "Exiting...\n";
            break;
        }

        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}








/*1. Inserting into a heap

Each insertion takes
Time: O(log n)
Space: O(1) (heap grows by one element)

2. Getting Max or Min

Retrieving top() from heap
Time: O(1)
Space: O(1)

3. Deleting the top element

Removing from heap
Time: O(log n)

When deleting from BOTH heaps, we rebuild one heap:
Time: O(n) (simple beginner method)

4. Creating a heap

If inserting N elements one by one:
Time: O(n log n)
If using heapify (advanced), it is O(n).

5. Displaying leaderboard (sorted order)

We copy and pop all heap elements:
Time: O(n log n)
Space: O(n)*/