#include <iostream>
#include <vector>

using namespace std;

template <typename T> void printVector(const vector<T> &v){
    for(size_t i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n\n";
}

template <typename T> void insertionSort(vector<T> &v){
    int j = -1;
    for(size_t i = 1; i < v.size(); ++i){

        j = i;

        while(j >= 0 && v[j - 1] > v[j]){
            swap(v[j], v[j-1]);
            --j;
        }
    }
}

template <typename T> void sortVector(vector<T> &v){
    cout << "Original Vector:\n";
    printVector(v); 
    insertionSort(v);
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