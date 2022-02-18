#include "Matrix.h"

Matrix::Matrix() {
    this->sizeX = 0;
    this->sizeY = 0;
    a.resize(0, vector<int>(0, 0));
}

Matrix::Matrix(int sizeX, int sizeY) {
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    a.resize(sizeY, vector<int>(sizeX, 0));
}

Matrix::Matrix(const vector<vector<int>> &a) {
    this->a = a;
    sizeX = a[0].size();
    sizeY = a.size();
}

bool Matrix::check(const Matrix& m) {
    return m.sizeX == sizeX && m.sizeY == sizeY;
}

bool Matrix::checkM(const Matrix& m) {
    return sizeX == m.sizeY;
}

istream & operator>>(istream &in, Matrix &m) {
    for(int i = 0; i < m.sizeY; i++)
        for(int j = 0; j < m.sizeX; j++)
            in >> m.a[i][j];
}

istream &operator << (ostream &out, Matrix &m) {
    for(int i = 0; i < m.sizeY; i++) {
        for (int j = 0; j < m.sizeX; j++)
            out << m.a[i][j] << " ";
        out << "\n";
    }
}

Matrix Matrix::operator*(int x) {
    vector<vector<int>> q = a;
    for(int i = 0; i < sizeY; i++)
        for(int j = 0; j < sizeX; j++)
            q[i][j] *= x;
    return Matrix(q);
}

Matrix Matrix::operator*(Matrix &m) {
    if (checkM(m)){
        vector<vector<int>> t(sizeY, vector<int>(m.sizeX));
        for(int i = 0; i < sizeY; i++)
          for(int j = 0; j < m.sizeX; j++)
            for(int k = 0; k < sizeX; k++)
              t[i][j] += a[i][k] * m.a[k][j];
        return Matrix(t);
    }
    cout << "\nError\n";
    return Matrix();
}

Matrix Matrix::operator+(Matrix &m) {
    vector<vector<int>> q1 = a;
    vector<vector<int>> q2 = m.a;
    if(check(m))
        for(int i = 0; i < sizeY; i++)
            for(int j = 0; j < sizeX; j++)
                q1[i][j] += q2[i][j];
    else {
        cout << "\nError\n";
        return Matrix();
    }
    return Matrix(q1);
}

Matrix Matrix::operator-(Matrix &m) {
    vector<vector<int>> q1 = a;
    vector<vector<int>> q2 = m.a;
    if (check(m))
        for (int i = 0; i < sizeY; i++)
            for (int j = 0; j < sizeX; j++)
                q1[i][j] -= q2[i][j];
    else {
        cout << "\nError\n";
        return Matrix();
    }
    return Matrix(q1);
}