#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class compare{
    public:
        bool operator()(pair<int,int> &p1, pair<int,int> &p2) {
            return (1.0 * p1.first/p1.second) > (1.0 * p2.first/p2.second);
        }
};

int fractional_knapsack(vector<int> profit, vector<int> wt, int capacity) {
    int n = profit.size();
    vector<pair<int,int>> vec(n);
    for(int i = 0; i < n; i++) {
        vec[i] = {profit[i],wt[i]};
    }

    sort(begin(vec),end(vec), compare());

    double result = 0;
    for(int i = 0; i < n; i++) {
        if(vec[i].second <= capacity) {
            result += vec[i].first;
            capacity -= vec[i].second;
        }else {
            result += (1.0 * vec[i].first/vec[i].second) * capacity;
            break;
        }
    }
    return result;
}

int main() {
    vector<int> profit = {100,280,120};
    vector<int> wt = {10,40,20};
    int capacity = 50;

    cout<<"\nMaximum Profit = "<<fractional_knapsack(profit, wt, capacity)<<endl;
}

/*
Complexity analysis
Creating pairs	O(n)
Sorting	O(nlog n)
Selecting items	O(n)

Total time	O(nlog n)

Auxiliary space	O(n)
*/