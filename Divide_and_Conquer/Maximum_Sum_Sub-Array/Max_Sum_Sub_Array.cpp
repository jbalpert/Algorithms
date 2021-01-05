#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// This is O(nlog(n)) time O(logn) Space

int max_crossing_subarray(const vector<int> &v, int low, int mid, int high){
    int left_sum = numeric_limits<int>::min();
    int sum = 0;
    for(int i = mid; i >= low; --i){
        sum += v[i];
        if(sum > left_sum){
            left_sum = sum;
        }
    }
    int right_sum = numeric_limits<int>::min();
    sum = 0;
    for(int i = mid + 1; i < high; i++){
        sum += v[i];
        if(sum > right_sum){
            right_sum = sum;
        }
    }
    return left_sum + right_sum;
}

int max_sum_subarrayDC(const vector<int> &v, int low, int high){
    if(high == low){ // base case: only contain one element
        return v[low];
    }
    int mid = (high + low)/2;
    
    int left_subarray = max_sum_subarrayDC(v, low, mid);
    int right_subarray = max_sum_subarrayDC(v, mid+1, high);
    int crossing_subarray = max_crossing_subarray(v, low, mid, high); 
}

int main(){
   vector<int>j =  {-2, -3, 4, -1, 1, 3, 4, -6, -5, 2, 6, -2, 1, 5, -3}; 
   int max_sum = max_sum_subarrayDC(j, 0, j.size() - 1); 
   cout << "Maximum contiguous sum is " << max_sum << "\n"; 
   return 0; 
}