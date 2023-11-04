#include <iostream>
#include <algorithm>
#define size 3

using namespace std; 

int kp(int denoms[], int target, int idx, int count) {
    if (target <= 0) {
        return count;
    }
    if(idx <= -1) {
        return count;
    }

    int take = INT_MAX;
    if (denoms[idx] <= target) {
        take = kp(denoms, target-denoms[idx], idx, count++);
    }
    
    int n_take;
    if (idx == 0) {
        n_take = INT_MAX;
    } else {
        n_take = kp(denoms, target, idx--, count);
    }

    return min(take, n_take);
}

// Driver code 
int main() { 
    int denom[size] = { 10, 5, 1 };
    int v = 30;
  
    cout << kp(denom, v, size-1, 0);
    return 0; 
} 
