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
