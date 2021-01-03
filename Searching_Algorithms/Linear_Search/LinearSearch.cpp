#include <iostream>
#include <vector>

using namespace std;

template <typename T> void printVector(const vector<T> &v){
    for(size_t i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n\n";
}

template <typename T> int linearSearch(const vector<T> &v, T value){
    for(size_t i = 0; i < v.size(); i++){
        if(v[i] == value) return i;
    }
    return -1;
}

template <typename T> void vectorSearch(vector<T> &v, T value){
    cout << "I am searching for: "<< value << "\n";
    int index = linearSearch(v, value);
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
    vector<int> v = {1, 5, 2, 4, 3};
    vector<char> s = {'a', 'z', 'b', 'y', 'c'};
    vectorSearch(v, 3);
    vectorSearch(v, 0);
    vectorSearch(s, 'a');
}