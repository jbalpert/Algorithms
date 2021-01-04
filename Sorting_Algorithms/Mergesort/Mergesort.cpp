#include <iostream>
#include <vector>

using namespace std;

/*
Mergesort - Divide and Conquer algorithm. The worst case of merge sort is nlogn. This will happen when the merge sort
will have to do the maximum number of comparisons. Mergesort is a stable sort

Top Down Implementation - Divides the input container into two halves
calls itself on each of the halves until there are < 2 items
Once the container is divided into subsections that are < 2 items 
the merge() function is called which merges two sorted halves. 
Since we are dividing in logn time and merging two sorted containers
takes linear time O(a * b) (worst case) where a and b are the size of container a 
and size of container b, Merge sort performs is nlogn and is insensitive to input.
O(n) additional memory cose, while Quicksort is implace, typically slow than quicksort.

Bottom Up Implementation - Starts with N ordered sublists of size 1, performs 1-by-1 merges
to produce N/2 sublists of 2, scan through lists performing 2-by-2 merges to produce N/4
ordered sublists of 4...

*/

template <typename T> void printVector(const vector<T> &v){
    for(size_t i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n\n";
}

template <typename T> void merge(vector<T> &v, size_t l, size_t m, size_t r){
    size_t n = r - l;
    vector<T> c(n);
    
    for(size_t i = l, j = m, k = 0; k < n; ++k){
        if(i == m){
            c[k] = v[j++];
        }
        else if(j == r){
            c[k] = v[i++];
        }
        else{
            c[k] = (v[i] <= v[j] ? v[i++] : v[j++]);
        }
    }
    copy(c.begin(), c.end(), &v[l]);
}

template <typename T> void mergeSortTD(vector<T> &v, size_t l, size_t r){
    if(r < l + 2){
        return;
    }
        size_t m = l + (r - l) /2;
        mergeSort(v, l, m);
        mergeSort(v, m, r);
        merge(v, l, m, r);
}

template <typename T> void mergeSortBU(vector<T> &v, size_t l, size_t r){
    for(size_t size = 1; size <= r - l; size *= 2){
        for(size_t i = l; i <= r - size; i += 2 * size){
            merge(v, i, i + size, min(i + 2 * size, r));
        }
    }
}

template <typename T> void sortVector(vector<T> &v){
    cout << "Original Vector:\n";
    printVector(v); 
    //mergeSortTD(v, 0, v.size());
    mergeSortBU(v, 0, v.size());
    cout << "Sorted Vector\n"; 
    printVector(v);  
    cout << "\n\n";
}

int main(){
    vector<int> v = {1, 5, 2, 4, 3};
    vector<char> s = {'a', 'z', 'b', 'y', 'c'};
    sortVector(v);
    sortVector(s);
}