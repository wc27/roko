#include <iostream>
using namespace std;

// Recursive function to calculate Fibonacci number
int fibonacciRecursive(int n) {
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Non-recursive (iterative) function to print Fibonacci series
void fibonacciIterative(int n) {
    int a = 0, b = 1, c;

    cout << "Fibonacci Series (Iterative): ";
    if (n <= 0) {
        cout << endl;
        return;
    }
    if (n >= 1) cout << a << " ";
    if (n >= 2) cout << b << " ";

    for (int i = 3; i <= n; i++) {
        c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }
    cout << endl;
}

int main() {
    int n;

    cout << "Enter number of terms: ";
    cin >> n;

    // Iterative method
    fibonacciIterative(n);

    // Recursive method
    cout << "Fibonacci Series (Recursive): ";
    for (int i = 0; i < n; i++) {
        cout << fibonacciRecursive(i) << " ";
    }
    cout << endl;

    return 0;
}







/*Method	Time Complexity	Space Complexity	Reason
Recursive	O(2ⁿ)	O(n)	Expands into a binary recursion tree; stack depth n
Iterative	O(n)	O(1)	Single loop; uses constant variables*/