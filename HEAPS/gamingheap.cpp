#include <iostream>
using namespace std;

const int MAX = 100;   // maximum number of scores

// Arrays for heaps
int maxHeap[MAX];
int minHeapArr[MAX];

int maxSize = 0;   // current size of max heap
int minSize = 0;   // current size of min heap

void maxHeapInsert(int score) {
    maxHeap[++maxSize] = score;  
    int i = maxSize;

    while (i > 1 && maxHeap[i] > maxHeap[i / 2]) {
        int temp = maxHeap[i];
        maxHeap[i] = maxHeap[i / 2];
        maxHeap[i / 2] = temp;
        i /= 2;
    }
}

int maxHeapTop() {
    if (maxSize == 0) return -1;
    return maxHeap[1];
}

void maxHeapDelete() {
    if (maxSize == 0) return;
    
    maxHeap[1] = maxHeap[maxSize--];  
    int i = 1;

    while (true) {
        int left = i * 2;
        int right = i * 2 + 1;
        int largest = i;

        if (left <= maxSize && maxHeap[left] > maxHeap[largest])
            largest = left;

        if (right <= maxSize && maxHeap[right] > maxHeap[largest])
            largest = right;

        if (largest == i) break;

        int temp = maxHeap[i];
        maxHeap[i] = maxHeap[largest];
        maxHeap[largest] = temp;

        i = largest;
    }
}


void minHeapInsert(int score) {
    minHeapArr[++minSize] = score;
    int i = minSize;

    // Fix heap upwards
    while (i > 1 && minHeapArr[i] < minHeapArr[i / 2]) {
        int temp = minHeapArr[i];
        minHeapArr[i] = minHeapArr[i / 2];
        minHeapArr[i / 2] = temp;
        i /= 2;
    }
}

int minHeapTop() {
    if (minSize == 0) return -1;
    return minHeapArr[1];
}

void minHeapDeleteValue(int value) {
    int newArr[MAX];
    int newSize = 0;

    for (int i = 1; i <= minSize; i++) {
        if (minHeapArr[i] != value) {
            newArr[++newSize] = minHeapArr[i];
        }
    }

    minSize = newSize;

    for (int i = 1; i <= minSize; i++) {
        minHeapArr[i] = newArr[i];
    }

    // re-heapify
    for (int i = minSize / 2; i >= 1; i--) {
        int j = i;

        while (true) {
            int left = j * 2;
            int right = j * 2 + 1;
            int smallest = j;

            if (left <= minSize && minHeapArr[left] < minHeapArr[smallest])
            smallest = left;

            if (right <= minSize && minHeapArr[right] < minHeapArr[smallest])
                smallest = right;

            if (smallest == j) break;

            int temp = minHeapArr[j];
            minHeapArr[j] = minHeapArr[smallest];
            minHeapArr[smallest] = temp;

            j = smallest;
        }
    }
}

int main() {
    int choice, score;

    while (true) {
        cout << "\n===== MENU =====\n";
        cout << "1. Insert Player Score\n";
        cout << "2. Show Max and Min Score\n";
        cout << "3. Delete Top Score (Max)\n";
        cout << "4. Display Leaderboard (Sorted High to Low)\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter score: ";
            cin >> score;

            maxHeapInsert(score);
            minHeapInsert(score);
            cout << "Inserted!\n";
        }

        else if (choice == 2) {
            if (maxSize == 0)
                cout << "No scores yet!\n";
            else {
                cout << "Max Score: " << maxHeapTop() << endl;
                cout << "Min Score: " << minHeapTop() << endl;
            }
        }

        else if (choice == 3) {
            if (maxSize == 0)
                cout << "Nothing to delete!\n";
            else {
                int top = maxHeapTop();
                cout << "Deleted top score: " << top << endl;
                maxHeapDelete();
                minHeapDeleteValue(top);
            }
        }

        else if (choice == 4) {
            if (maxSize == 0)
                cout << "Leaderboard empty!\n";
            else {
                cout << "Leaderboard (High -> Low): ";
                for (int i = 1; i <= maxSize; i++) {
                    cout << maxHeap[i] << " ";
                }
                cout << endl;
            }
        }

        else if (choice == 5) {
            cout << "Goodbye!\n";
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