#include <iostream>
#include <vector>

using namespace std;

template <typename T> void printVector(const vector<T> &v){
    for(size_t i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n\n";
}

template <typename T> void bubbleSort(vector<T> &v){
    bool swaps;
    for(size_t i = 0; i < v.size() - 1; ++i){
        swaps = false;
        for(size_t j = 0; j < v.size() - i - 1; ++j){
            if(v[j + 1] < v[j]){
                swap(v[j], v[j+1]);
                swaps = true;
            }
        }
        if(!swaps)
            return;
    }
}

template <typename T> void sortVector(vector<T> &v){
    cout << "Original Vector:\n";
    printVector(v); 
    bubbleSort(v);
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