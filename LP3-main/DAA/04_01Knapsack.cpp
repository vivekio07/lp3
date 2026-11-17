#include <iostream>
#include <vector>
using namespace std;


//Dynamic Programming (Bottom-Up approach)
// TC => O(n*capacity)     
//SC => O(n*capacity) dp table

int knapsack(vector<int> profit, vector<int> wt, int capacity) {
    int n = profit.size();

    vector<vector<int>> t(n+1,vector<int>(capacity+1,0));
    
    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < capacity+1; j++) {
            if(wt[i-1] <= j) {
                t[i][j] = max(profit[i-1] + t[i-1][j - wt[i-1]], t[i-1][j]);
            }
            else t[i][j] = t[i-1][j];
        }
    }

    return t[n][capacity];
}

int main() {
    vector<int> profit = {1,4,5,7};
    vector<int> wt = {1,3,4,5};
    int capacity = 7;

    cout<<"\nMaximum Profit = "<<knapsack(profit, wt, capacity)<<endl;
}