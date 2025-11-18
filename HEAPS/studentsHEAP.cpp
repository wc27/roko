#include <iostream>
using namespace std;

const int MAX = 100;

// Max Heap (for maximum marks)
int maxHeap[MAX];
int maxSize = 0;

// Min Heap (for minimum marks)
int minHeap[MAX];
int minSize = 0;


void insertMax(int m) {
    maxHeap[++maxSize] = m;
    int i = maxSize;

    // Heapify up
    while (i > 1 && maxHeap[i] > maxHeap[i/2]) {
        int temp = maxHeap[i];
        maxHeap[i] = maxHeap[i/2];
        maxHeap[i/2] = temp;
        i /= 2;
    }
}

int getMax() {
    if (maxSize == 0) return -1;
    return maxHeap[1];
}

void insertMin(int m) {
    minHeap[++minSize] = m;
    int i = minSize;

    // Heapify up
    while (i > 1 && minHeap[i] < minHeap[i/2]) {
        int temp = minHeap[i];
        minHeap[i] = minHeap[i/2];
        minHeap[i/2] = temp;
        i /= 2;
    }
}

int getMin() {
    if (minSize == 0) return -1;
    return minHeap[1];
}

int main() {
    int choice, marks;

    while (true) {
        cout << "\n===== STUDENT MARKS MENU =====\n";
        cout << "1. Insert Marks\n";
        cout << "2. Display Maximum Marks\n";
        cout << "3. Display Minimum Marks\n";
        cout << "4. Display All Marks\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter marks: ";
            cin >> marks;
            insertMax(marks);
            insertMin(marks);
            cout << "Marks inserted.\n";
        }

        else if (choice == 2) {
            if (maxSize == 0) cout << "No marks entered.\n";
            else cout << "Maximum Marks: " << getMax() << endl;
        }

        else if (choice == 3) {
            if (minSize == 0) cout << "No marks entered.\n";
            else cout << "Minimum Marks: " << getMin() << endl;
        }

        else if (choice == 4) {
            if (maxSize == 0) {
                cout << "No marks available.\n";
            } else {
                cout << "\nMarks Stored (Max Heap Order): ";
                for (int i = 1; i <= maxSize; i++)
                    cout << maxHeap[i] << " ";

                cout << "\nMarks Stored (Min Heap Order): ";
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











/*Inserting into a heap

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