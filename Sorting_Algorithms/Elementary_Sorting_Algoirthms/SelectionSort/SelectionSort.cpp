#include <iostream>
#include <vector>

using namespace std;

template <typename T> void printVector(const vector<T> &v){
    for(size_t i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n\n";
}

template <typename T> void selectionSort(vector<T> &v){
    size_t minIndex;
    for(size_t i = 0; i < v.size() - 1; i++){
        minIndex = i;
        for(size_t j = i + 1; j < v.size(); j++){
            if(v[j] < v[minIndex]){
                minIndex = j;
            }
        }
        swap(v[i], v[minIndex]);
    }
}

template <typename T> void sortVector(vector<T> &v){
    cout << "Original Vector:\n";
    printVector(v); 
    selectionSort(v);
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