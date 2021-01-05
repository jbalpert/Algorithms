#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// This is O(log(n))
/*

Binary Search is an efficient searching algorithm that can be used
on sorted data sets. Basic idea is we find the mid point and split the data in half each time
and ask whether the value is higher or less than the value we want to find
if its higher we look at the right half of the data since we know that the value is greater than the
midpoint and can eliminate the other half of the data, we can do the same if the value is smaller
if we found that the mid == val then we return mid which is the index

int mid = (left + right) / 2;

V.S. 

int mid = left + (right - left) / 2;

They output the same (do the maths :)

(left + right) / 2 = left + (right - left) / 2
left / 2 + right / 2 = left + right / 2 - left/2
left / 2 + right / 2 = left / 2 + right / 2

We just use mid = left + (right - left) / 2 so
integer overflow cannot happen by adding left + right

*/

template <typename T> void printVector(const vector<T> &v){
    for(size_t i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n\n";
}

// Recursive Solution
template<typename T> int binary_search_RC(vector<T> &v, int l, int r, T val){
    if(r > l){
        int mid = l + (r - l) / 2;
        if(val < v[mid]){
            return binary_search_RC(v, l, mid, val);
        }
        else if(val > v[mid]){
            return binary_search_RC(v, mid + 1, r, val);
        }
        else{
            return mid;
        }
    }
    return -1;
}

// Iterative Solution
template<typename T> int binary_search_IT(vector<T> &v, int l, int r, T val){
    while(r > l){
        int mid = l + (r - l) / 2;
        if(val < v[mid]){
            r = mid;
        }
        else if(val > v[mid]){
            l = mid + 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

template <typename T> void vectorSearch(vector<T> &v, T value){
    cout << "I am searching for: "<< value << "\n";
    int index = binary_search_IT(v, 0, v.size(), value);
    if(index != -1){
        cout << "After the search the value " << value << " can be found on index " << index << "\n";
    }
    else{
        cout << "The value is not stored in this vector\n";
    }
    printVector(v);  
    cout << "\n\n";
}

int main(){
    vector<int> v = {1, 2, 3, 4, 5};
    vector<char> s = {'a', 'b', 'c', 'd', 'e'};
    vectorSearch(v, 3);
    vectorSearch(v, 5);
    vectorSearch(v, 1);
    vectorSearch(v, 0);
    vectorSearch(s, 'a');
    return 0;
}