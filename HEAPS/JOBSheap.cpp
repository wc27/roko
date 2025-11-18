#include <iostream>
using namespace std;

const int MAX = 100;

// Max Heap (Highest Priority Jobs)
int maxHeap[MAX];
int maxSize = 0;

// Min Heap (Lowest Priority Jobs)
int minHeap[MAX];
int minSize = 0;

// Insert into Max Heap
void insertMax(int priority) {
    maxHeap[++maxSize] = priority;
    int i = maxSize;

    // Heapify Up
    while (i > 1 && maxHeap[i] > maxHeap[i/2]) {
        int t = maxHeap[i];
        maxHeap[i] = maxHeap[i/2];
        maxHeap[i/2] = t;
        i /= 2;
    }
}

// Return Highest Priority
int getMax() {
    if (maxSize == 0) return -1;
    return maxHeap[1];
}

// Delete Highest Priority Job
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

// Insert into Min Heap
void insertMin(int priority) {
    minHeap[++minSize] = priority;
    int i = minSize;

    // Heapify Up
    while (i > 1 && minHeap[i] < minHeap[i/2]) {
        int t = minHeap[i];
        minHeap[i] = minHeap[i/2];
        minHeap[i/2] = t;
        i /= 2;
    }
}

// Return Lowest Priority Job
int getMin() {
    if (minSize == 0) return -1;
    return minHeap[1];
}


// Delete from Min Heap (sync with max heap)
void deleteFromMin(int value) {
    int newArr[MAX];
    int newSize = 0;

    // Copy all except deleted value
    for (int i = 1; i <= minSize; i++) {
        if (minHeap[i] != value)
            newArr[++newSize] = minHeap[i];
    }

    minSize = newSize;

    // Copy back
    for (int i = 1; i <= minSize; i++)
        minHeap[i] = newArr[i];

    // Reheapify bottom-up
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
    int choice, priority;

    while (true) {
        cout << "\n===== JOB PRIORITY MENU =====\n";
        cout << "1. Insert Job Priority\n";
        cout << "2. Display Highest & Lowest Priority Jobs\n";
        cout << "3. Delete Highest Priority Job\n";
        cout << "4. Display All Jobs (Priority Order)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter job priority: ";
            cin >> priority;
            insertMax(priority);
            insertMin(priority);
            cout << "Job inserted successfully.\n";
        }

        else if (choice == 2) {
            if (maxSize == 0)
                cout << "No jobs available.\n";
            else {
                cout << "Highest Priority Job: " << getMax() << endl;
                cout << "Lowest Priority Job: " << getMin() << endl;
            }
        }

        else if (choice == 3) {
            if (maxSize == 0)
                cout << "No jobs to delete.\n";
            else {
                int high = getMax();
                cout << "Deleting Highest Priority Job: " << high << endl;

                deleteMax();          // Remove from max heap
                deleteFromMin(high);  // Remove same job from min heap
            }
        }

        else if (choice == 4) {
            if (maxSize == 0)
                cout << "No jobs to display.\n";
            else {
                cout << "\nDescending Priority (Max Heap): ";
                for (int i = 1; i <= maxSize; i++)
                    cout << maxHeap[i] << " ";

                cout << "\nAscending Priority (Min Heap): ";
                for (int i = 1; i <= minSize; i++)
                    cout << minHeap[i] << " ";

                cout << endl;
            }
        }

        else if (choice == 5) {
            cout << "Exiting program...\n";
            break;
        }

        else {
            cout << "Invalid choice! Try again.\n";
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
