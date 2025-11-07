#include <iostream>
#include <algorithm>
using namespace std;

// Function to return maximum value that can be put in knapsack
int knapsack(int W, int weight[], int value[], int n) {
    int dp[n + 1][W + 1];

    // Build table dp[][] bottom-up
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i - 1] <= w)
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]],
                               dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}

int main() {
    int value[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int W = 50; // Capacity of knapsack
    int n = 3;  // Number of items

    int maxValue = knapsack(W, weight, value, n);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}


//user input
int main() {
    int n, W;

    // Take number of items
    cout << "Enter number of items: ";
    cin >> n;

    int weight[n], value[n];

    // Take weight and value of each item
    cout << "Enter weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " - Weight: ";
        cin >> weight[i];
        cout << "Item " << i + 1 << " - Value: ";
        cin >> value[i];
    }

    // Take capacity
    cout << "Enter capacity of knapsack: ";
    cin >> W;

    // Compute maximum value
    int maxValue = knapsack(W, weight, value, n);
    cout << "\nMaximum value in Knapsack = " << maxValue << endl;

    return 0;
}
