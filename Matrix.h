#ifndef TASK2_MATRIX_H
#define TASK2_MATRIX_H
#include <iostream>
#include <vector>

using namespace std;

class Matrix {
    int sizeX, sizeY;
    vector<vector<int>> a;

public:
    Matrix();
    Matrix(int sizeX, int sizeY);
    Matrix(const vector<vector<int>> &a);
    bool check(const Matrix& m);
    bool checkM(const Matrix& m);
    friend istream & operator >>(istream &, Matrix &);
    friend istream & operator <<(ostream &, Matrix &);
    Matrix operator *(int);
    Matrix operator *(Matrix &);
    Matrix operator +(Matrix &);
    Matrix operator -(Matrix &);

};

#endif //TASK2_MATRIX_H