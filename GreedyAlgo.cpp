#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
};

// Function to compare items based on value/weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2; // higher ratio first
}

double fractionalKnapsack(Item items[], int n, int capacity) {
    // Step 1: Sort items by decreasing value/weight ratio
    sort(items, items + n, compare);

    double totalValue = 0.0;

    // Step 2: Pick items greedily
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            // Take the whole item
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take fraction of the remaining item
            double fraction = (double)capacity / items[i].weight;
            totalValue += items[i].value * fraction;
            break; // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int n = 3; // number of items
    Item items[] = { {10, 60}, {20, 100}, {30, 120} };
    int capacity = 50; // maximum capacity of knapsack

    double maxValue = fractionalKnapsack(items, n, capacity);

    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}


//user input
int main() {
    int n, capacity;

    // Take number of items
    cout << "Enter number of items: ";
    cin >> n;

    // Declare array of items
    Item items[n];

    // Take weight and value for each item
    cout << "Enter weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " - Weight: ";
        cin >> items[i].weight;
        cout << "Item " << i + 1 << " - Value: ";
        cin >> items[i].value;
    }

    // Take capacity
    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    // Calculate max value
    double maxValue = fractionalKnapsack(items, n, capacity);

    cout << "\nMaximum value in Knapsack = " << maxValue << endl;

    return 0;
}
