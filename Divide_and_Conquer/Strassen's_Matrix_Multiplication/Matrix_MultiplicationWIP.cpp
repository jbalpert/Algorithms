#include <iostream>
#include <limits>
#include <vector>
#include <utility>

using namespace std;
using matrix = vector<vector<int>>;

// Matrix Print:

void MatrixPrint(const matrix &v){
    for(size_t i = 0; i < v.size(); i++){
        cout << "| ";
        for(size_t j = 0; j < v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << "|\n\n";
    }
}

// Naive Method O(n^3)
// Required: two matrices must be able to be multiplied (of the form (a x n) (n x b)
matrix Matrix_Multiplication(const matrix &a, const matrix &b, int n){
    matrix res(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < n; ++k){
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}

// Divide and Conquer Method O(n^log(7)) approx O(n^2.8)

/*
Warning: typically not preferred over the naive method since recursion takes up space
however, slightly faster asymptotically for very large matrices and much more complicated
*/

// add two matrices
matrix addition(const matrix &a, const matrix &b, int n) {
    matrix v(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            v[i][j] = a[i][j] + b[i][j];
        }
    }
    return v;
}

matrix subtract(const matrix &a, const matrix &b, int n) {
    matrix v(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            v[i][j] = a[i][j] - b[i][j];
        }
    }
    return v;
}

// Returns a pair of matrix a divided into a11 a12 a21 a22 and
// b divided into 11 12 21 22 into quaters: each pair is a vector that contains
// the four matrices: 11 12 21 22 that describe the matrix coordinates

pair<vector<matrix>, vector<matrix>> divideMatrices(matrix &a, matrix &b, int newSize){
    // Initialize all vectors

    vector<int> innerVector(newSize, 0);
    matrix a11(newSize, innerVector), a12(newSize, innerVector), a21(newSize, innerVector), a22(newSize, innerVector),
    b11(newSize, innerVector), b12(newSize, innerVector), b21(newSize, innerVector), b22(newSize, innerVector);

    for(int i = 0; i < newSize; i++){
        for(int j = 0; j < newSize; j++){
            a11[i][j] = a[i][j];
            a12[i][j] = a[i][j + newSize];
            a21[i][j] = a[i + newSize][j];
            a22[i][j] = a[i + newSize][j + newSize];

            b11[i][j] = b[i][j];
            b12[i][j] = b[i][j + newSize];
            b21[i][j] = b[i + newSize][j];
            b22[i][j] = b[i + newSize][j + newSize];
        }
    }
    // return pair of vector of a matrices and b matrices (a divided matrices (adm)/ b divided matrices (bdm))
    return {{a11, a12, a21, a22}, {b11, b12, b21, b22}};
}

matrix strassen(matrix &a, matrix &b, int n){
    int newSize = 1;
    if(n == 1){
        return {{a[0][0] * b[0][0]}};
    }
    else{
        newSize = n / 2;
        pair<vector<matrix>, vector<matrix>> m = divideMatrices(a, b, newSize);

        auto s1 = subtract(m.second[1], m.second[3], newSize),
        s2 = addition(m.first[0], m.first[1], newSize),
        s3 = addition(m.first[2], m.first[3], newSize),
        s4 = subtract(m.second[2], m.second[0], newSize),
        s5 = addition(m.first[0], m.first[3], newSize),
        s6 = addition(m.second[0], m.second[3], newSize),
        s7 = addition(m.first[1], m.first[3], newSize),
        s8 = addition(m.second[2], m.second[3], newSize),
        s9 = addition(m.first[0], m.first[2], newSize),
        s10 = addition(m.second[0], m.second[1], newSize);

        auto p1 = strassen(m.first[0], s1, newSize),
        p2 = strassen(s2, m.second[3], newSize),
        p3 = strassen(s3, m.second[0], newSize),
        p4 = strassen(m.first[3], s4, newSize),
        p5 = strassen(s5, s6, newSize),
        p6 = strassen(s7, s8, newSize),
        p7 = strassen(s9, s10, newSize);

        auto c11 = subtract(addition(addition(p5, p4, newSize), p6, newSize), p2 ,newSize),
        c12 = addition(p1,p2,newSize),
        c21 = addition(p3,p4,newSize),
        c22 = subtract(subtract(addition(p5,p1,newSize), p3, newSize), p7, newSize);

        //initialize new matrix to put pieces back together
        vector<int> innerVector(n, 0);
        matrix v(n, innerVector);
        for(int i = 0; i < newSize; i++){
            for(int j = 0; j < newSize; j++){
                v[i][j] = c11[i][j];
                v[i][j + newSize] = c12[i][j];
                v[i + newSize][j] = c21[i][j];
                v[i + newSize][j + newSize] = c22[i][j];
            }
        }

                // print s values to console for matrices of n = 2
        if (n == 2) {
            cout << endl;
            cout << "S1: " << s1[0][0] << endl;
            cout << "S2: " << s2[0][0] << endl;
            cout << "S3: " << s3[0][0] << endl;
            cout << "S4: " << s4[0][0] << endl;
            cout << "S5: " << s5[0][0] << endl;
            cout << "S6: " << s6[0][0] << endl;
            cout << "S7: " << s7[0][0] << endl;
            cout << "S8: " << s8[0][0] << endl;
            cout << "S9: " << s9[0][0] << endl;
            cout << "S10: " << s10[0][0] << endl;
        }
        return v;
    }
}

/*
Base case is 1x1 matrices
*/


void MatrixMultiplyPrint(matrix &a, matrix &b, int n){
    cout << "Multiplying a " << n << " x " << n << " matrix: \n\n";
    MatrixPrint(a);
    cout << "*\n";
    MatrixPrint(b);
    cout << "------------ANSWER-------------\n\n";
    MatrixPrint(strassen(a, b, n));
}

int main(){
    matrix a = {
        {1, 6},
        {2, 7}
    };
    matrix b = {
        {6, 3},
        {4, 12}
    };
    MatrixMultiplyPrint(a, b, 2);

    matrix c = {
        {1, 6, 1, 6},
        {2, 7, 2, 7},
        {1, 6, 1, 6},
        {2, 7, 2, 7}
    };
    matrix d = {
        {6, 3, 6, 3},
        {4, 12, 4, 12},
        {6, 3, 6, 3},
        {4, 12, 4, 12}
    };
    MatrixMultiplyPrint(c, d, 4);
    return 0; 
}