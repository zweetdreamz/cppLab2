#pragma once

#include <iomanip>
#include "Other.h"

using namespace std;

class SquareMatrix {
public:
    unsigned int n;
    float **pointerArray;

    SquareMatrix(Fill fill) {

        unsigned int n;
        cout << "Введите количество столбцов и строк " << endl;
        cin >> n;


        switch (fill) {
            case rnd:

                this->n = n;
                pointerArray = new float *[n];
                for (int i = 0; i < n; ++i) {
                    pointerArray[i] = new float[n];
                }

                this->fillingThemMatrixRandom();

                break;

            case empty:

                this->n = n;
                pointerArray = new float *[n];
                for (int i = 0; i < n; ++i) {
                    pointerArray[i] = new float[n];
                }

                break;

            case manual:

                this->n = n;
                pointerArray = new float *[n];
                for (int i = 0; i < n; ++i) {
                    pointerArray[i] = new float[n];
                }

                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {

                        float elem;
                        cout << "Введите элемент " << i + 1 << ", " << j + 1 << " " << endl;
                        cin >> elem;
                        pointerArray[i][j] = elem;

                    }
                }

                break;

        }

    }

    SquareMatrix(unsigned int n) {

        this->n = n;
        pointerArray = new float *[n];
        for (int i = 0; i < n; ++i) {
            pointerArray[i] = new float[n];
        }

    }

    SquareMatrix(const SquareMatrix &ob) {

        n = ob.n;
        pointerArray = new float *[n];
        for (int i = 0; i < n; i++) {
            pointerArray[i] = new float[n];
        }
        if (!pointerArray) {
            cout << "Error";
            cin.get();
            return;
        }
        for (int i = 0; i < ob.n; ++i) {
            for (int j = 0; j < ob.n; ++j) {
                pointerArray[i][j] = ob.pointerArray[i][j];
            }
        }

    }

    ~SquareMatrix() {

        delete[] pointerArray;

    }

    void fillingThemMatrixRandom() {

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                pointerArray[i][j] = Random(-20, 20);
            }
        }

    }

    void matrixOut() {

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << setw(5) << pointerArray[i][j];
            }
            cout << endl;
        }

    }

    void matrixSum(SquareMatrix *anotherMatrix) {

        if (n != anotherMatrix->n) {
            cout << "Размерности матриц не равны" << endl;
            cin.get();
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                pointerArray[i][j] += anotherMatrix->pointerArray[i][j];
            }
        }


    }

    void matrixDif(SquareMatrix *anotherMatrix) {

        if (n != anotherMatrix->n) {
            cout << "Размерности матриц не равны" << endl;
            cin.get();
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                pointerArray[i][j] += anotherMatrix->pointerArray[i][j];
            }
        }


    }

    void matrixMultiply(SquareMatrix *anotherMatrix) {



        SquareMatrix *m = new SquareMatrix{n};

        for (auto i = 0; i < n; i++) {
            for (auto j = 0; j < n; j++) {
                m->pointerArray[i][j] = 0;
                for (auto t = 0; t < n; t++) {
                    m->pointerArray[i][j] += pointerArray[i][t] * anotherMatrix->pointerArray[t][j];
                }
            }
        }

        *this = *m;

        delete m;

    }

    void matrixConstSum(int k) {

        SquareMatrix m{n};

        for (auto i = 0; i < n; i++) {
            for (auto j = 0; j < n; j++) {
                i == j ? m.pointerArray[i][j] = 1 : m.pointerArray[i][j] = 0;
            }
        }

        m * k;

        *this + m;

    }

    void matrixConstDif(int k) {

        SquareMatrix m{n};

        for (auto i = 0; i < n; i++) {
            for (auto j = 0; j < n; j++) {
                i == j ? m.pointerArray[i][j] = 1 : m.pointerArray[i][j] = 0;
            }
        }

        m * k;

        *this - m;

    }

    void matrixConstMultiply(int k) {

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                pointerArray[i][j] *= k;
            }
        }

    }

    void matrixConstDiv(int k) {

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                pointerArray[i][j] /= k;
            }
        }

    }

    float normOfMatrix() {

        float norm = 0;
        for (int j = 0; j < n; j++) {

            float s = 0.0;
            for (int i = 0; i < n; i++) {
                s += abs(pointerArray[i][j]);
            }
            if (norm < s) { norm = s; }
        }

        return norm;

    }

    SquareMatrix operator+(SquareMatrix &anotherMatrix) {

        if (n != anotherMatrix.n) {
            cout << "Error";
            cin.get();
            return *this;
        }

        matrixSum(&anotherMatrix);

        return *this;

    }

    SquareMatrix operator+=(SquareMatrix &anotherMatrix) {

        if (n != anotherMatrix.n) {
            cout << "Error";
            cin.get();
            return *this;
        }

        matrixSum(&anotherMatrix);

        return *this;

    }

    SquareMatrix operator-(SquareMatrix &anotherMatrix) {

        if (n != anotherMatrix.n) {
            cout << "Error";
            cin.get();
            return *this;
        }

        matrixDif(&anotherMatrix);

        return *this;

    }

    SquareMatrix operator-=(SquareMatrix &anotherMatrix) {

        if (n != anotherMatrix.n) {
            cout << "Error";
            cin.get();
            return *this;
        }

        matrixDif(&anotherMatrix);

        return *this;

    }

    SquareMatrix operator=(SquareMatrix &anotherMatrix) {

        if (n != anotherMatrix.n) {
            cout << "Error";
            cin.get();
            return *this;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                pointerArray[i][j] = anotherMatrix.pointerArray[i][j];
            }
        }

        return *this;

    }

    SquareMatrix operator=(int k) {

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                pointerArray[i][j] = k;
            }
        }

        return *this;

    }

    SquareMatrix operator*(SquareMatrix &anotherMatrix) {

        if (n != anotherMatrix.n) {
            cout << "Error";
            cin.get();
            return *this;
        }

        matrixMultiply(&anotherMatrix);

        return *this;

    }

    SquareMatrix operator*=(SquareMatrix &anotherMatrix) {

        if (n != anotherMatrix.n) {
            cout << "Error";
            cin.get();
            return *this;
        }

        matrixMultiply(&anotherMatrix);

        return *this;

    }

    SquareMatrix operator+(int k) {

        matrixConstSum(k);

        return *this;

    }

    SquareMatrix operator+=(int k) {

        matrixConstSum(k);

        return *this;

    }

    SquareMatrix operator-(int k) {

        matrixConstDif(k);

        return *this;

    }

    SquareMatrix operator-=(int k) {

        matrixConstDif(k);

        return *this;

    }

    SquareMatrix operator*(int k) {

        matrixConstMultiply(k);

        return *this;

    }

    SquareMatrix operator*=(int k) {

        matrixConstMultiply(k);

        return *this;

    }

    SquareMatrix operator/(int k) {

        matrixConstDiv(k);

        return *this;

    }

    SquareMatrix operator/=(int k) {

        matrixConstDiv(k);

        return *this;

    }

    bool operator==(SquareMatrix &anotherMatrix) {

        float c = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                c += (pointerArray[i][j] - anotherMatrix.pointerArray[i][j]);
            }
        }

        return c == 0;

    }

};

void sqrTheIthMatrix(SquareMatrix *data[]) {

    int index = Out("Какую матрицу возвести в квадрат? ");

    data[index - 1]->matrixMultiply(data[index - 1]);
    data[index - 1]->matrixOut();

}

void squareMatrixMain() {

    int const N = 5;
    SquareMatrix *data[N];

    unsigned int n = Out("Введите количество строк и стобцов ");

    for (int i = 0; i < N; ++i) {

        data[i] = new SquareMatrix{n};
        data[i]->fillingThemMatrixRandom();
        cout << " №" << i + 1 << ": " << endl;
        data[i]->matrixOut();

    }

    sqrTheIthMatrix(data);

}