//Iterative Fibonacci with step counter
#include <iostream>
using namespace std;

long long fib_iterative(int n, int &steps) {
    steps = 0;
    if (n == 0) {
        steps++;
        return 0;
    } 
    else if (n == 1) {
        steps++;
        return 1;
    }

    long long a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        steps++;
        long long temp = b;
        b = a + b;
        a = temp;
    }
    return b;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int steps;
    long long result = fib_iterative(n, steps);

    cout << "Fibonacci(" << n << ") = " << result << endl;
    cout << "Step count (iterative) = " << steps << endl;

    return 0;
}



// Recursive Fibonacci with step counter
#include <iostream>
using namespace std;

long long fib_recursive(int n, int &steps) {
    steps++;
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib_recursive(n - 1, steps) + fib_recursive(n - 2, steps);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int steps = 0;
    long long result = fib_recursive(n, steps);

    cout << "Fibonacci(" << n << ") = " << result << endl;
    cout << "Step count (recursive) = " << steps << endl;

    return 0;
}
