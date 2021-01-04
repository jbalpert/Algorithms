#include <iostream>
#include <iterator>
#include <vector>
#include <utility>

using namespace std;

pair<pair<vector<int>::iterator, vector<int>::iterator>, int> Max_Sum_SubarrayBF2(vector<int> &v){
    int maxSum = v[0], sum = v[0], start = 0, end = 0;
    for(size_t i = 1; i < v.size(); i++){
        sum = max(v[i], sum + v[i]);
        if(sum == v[i]){
            start = i;
        }
        maxSum = max(maxSum, sum);
        if(maxSum == sum){
            end = i + 1;
        }
    }
    return {{v.begin() + start, v.begin() + end},maxSum};
}

void printElements(pair<vector<int>::iterator, vector<int>::iterator> itPair){
    cout << "Elements in the sub-array include: \n[";
    for(auto it = itPair.first; it != itPair.second; ++it){
       cout << " " << *it << " ";
   }
   cout << "]\n";
}

pair<int,int> getIndexRange(pair<vector<int>::iterator, vector<int>::iterator> itPair, const vector<int> &v){
    return {itPair.first - v.begin(), itPair.second - v.begin()};
}

int main(){
   vector<int>j =  {-2, -3, 4, -1, 1, 3, 4, -6, -5, 2, 6, -2, 1, 5, -3}; 
   auto max_sum = Max_Sum_SubarrayBF2(j); 
   cout << "Maximum contiguous sum is " << max_sum.second << "\n"; 
   printElements(max_sum.first);
   auto pairIndex = getIndexRange(max_sum.first, j);
   cout << "Indices: [ " << pairIndex.first << " : " << pairIndex.second - 1<< " ]\n";
   return 0; 
}