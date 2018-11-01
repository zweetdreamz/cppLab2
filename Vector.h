#pragma once

#include <ostream>
#include "cmath"
#include "Other.h"

using namespace std;

class Vector {
public:
    int n;
    int *pointerArray;

    Vector() {

        n = 3;
        pointerArray = new int[n];

    }

    Vector(int num) {

        n = num;
        pointerArray = new int[n];

    }

    void setVector() {

        for (int i = 0; i < this->n; i++) {

            cout << "Введите элемент вектора № " << i << ": ";
            cin >> *(pointerArray + i);

        }

    }

    ~Vector() {

        delete[] pointerArray;

    }

    Vector(const Vector &ob) {

        n = ob.n;
        pointerArray = new int[n + 1];

        if (!pointerArray) {
            cout << "Error";
            cin.get();
            return;
        }
        for (int i = 0; i <= n; i++) {

            pointerArray[i] = ob.pointerArray[i];

        }

    }

    void vectorOut() {

        string s = "{";
        for (int i = 0; i < n; i++) {

            s += " " + to_string(*(pointerArray + i)) + ",";

        }

        s.pop_back();
        s += " }";
        cout << s << endl;

    }

    double vectorModul() {

        double modul = 0;
        for (int i = 0; i < n; i++) {

            modul += *(pointerArray + i) * *(pointerArray + i);

        }

        return sqrt(modul);

    }

    double vectorScalar(Vector *anotherVector) {

        double scalar = 0;

        if (n == anotherVector->n) {

            for (int i = 0; i < n; i++) {

                scalar += *(pointerArray + i) * *(anotherVector->pointerArray + i);

            }

        } else {

            cout << "Размерности векторов не равны" << endl;
            scalar = NAN;

        }

        return scalar;

    }

    void vectorSum(Vector *anotherVector) {

        if (n == anotherVector->n) {

            for (int i = 0; i < n; i++) {

                *(pointerArray + i) += *(anotherVector->pointerArray + i);

            }

        } else {

            cout << "Размерности векторов не равны" << endl;

        }

    }

    void vectorDif(Vector *anotherVector) {

        if (n == anotherVector->n) {

            for (int i = 0; i < n; i++) {

                *(pointerArray + i) -= *(anotherVector->pointerArray + i);

            }

        } else {

            cout << "Размерности векторов не равны" << endl;

        }

    }

    void vectorConstMultiply(const int k) {

        for (int i = 0; i < n; i++) {

            *(pointerArray + i) += *(pointerArray + i) * k;

        }

    }

    Vector operator*(const int k) {

        vectorConstMultiply(k);

        return *this;

    }

    Vector operator*=(const int k) {

        vectorConstMultiply(k);

        return *this;

    }

    Vector operator+(Vector &anotherVector) {

        if (n != anotherVector.n) {
            cout << "Error";
            cin.get();
            return *this;
        }

        vectorSum(&anotherVector);

        return *this;

    }

    Vector operator+=(Vector &anotherVector) {

        if (n != anotherVector.n) {
            cout << "Error";
            cin.get();
            return *this;
        }

        vectorSum(&anotherVector);

        return *this;

    }

    Vector operator+(const int k) {

        for (int i = 0; i < n; i++) {
            pointerArray[i] += k;
        }

        return *this;

    }

    Vector operator+=(const int k) {

        for (int i = 0; i < n; i++) {
            pointerArray[i] += k;
        }

        return *this;

    }

    Vector operator-(Vector &anotherVector) {

        if (n != anotherVector.n) {
            cout << "Error";
            cin.get();
            return *this;
        }

        vectorDif(&anotherVector);

        return *this;

    }

    Vector operator-=(Vector &anotherVector) {

        if (n != anotherVector.n) {
            cout << "Error";
            cin.get();
            return *this;
        }

        vectorDif(&anotherVector);

        return *this;

    }

    Vector operator-(const int k) {

        for (int i = 0; i < this->n; i++) {

            pointerArray[i] -= n;

        }

        return *this;

    }

    Vector operator-=(const int k) {

        for (int i = 0; i < n; i++) {

            pointerArray[i] -= k;

        }

        return *this;

    }

    Vector operator=(Vector &anotherVector) {

        if (n != anotherVector.n) {
            cout << "Error";
            cin.get();
            return *this;
        }
        for (int i = 0; i < this->n; i++) {

            pointerArray[i] = anotherVector.pointerArray[i];

        }

        return *this;

    }

    Vector operator=(const int k) {

        for (int i = 0; i < n; i++) {

            pointerArray[i] = k;

        }

        return *this;

    }

    Vector operator++() {

        for (int i = 0; i < n; i++) {

            ++pointerArray[i];

        }

        return *this;

    } // префикс

    Vector operator++(int) {

        for (int i = 0; i < n; i++) {

            pointerArray[i]++;

        }

        return *this;

    } // постфикс

    Vector operator--() {

        for (int i = 0; i < n; i++) {

            --pointerArray[i];

        }

        return *this;

    }

    Vector operator--(int) {

        for (int i = 0; i < n; i++) {

            pointerArray[i]--;

        }

        return *this;

    }

    int operator[](const int index) {

        if (index > n) {
            cout << "Error";
            cin.get();
        }

       return pointerArray[index];

    }

    bool operator==(Vector &anotherVector) {

        int c = 0;

        for (int i = 0; i < this->n; i++) {

            c += (pointerArray[i] - anotherVector.pointerArray[i]);

        }

        return c == 0;

    }


};

bool Orthogonality(Vector *v1, Vector *v2) {

    return v1->vectorScalar(v2) == 0;

}

bool Collinearity(Vector *v1, Vector *v2) {

    return v1->vectorScalar(v2) / ((*v1).vectorModul() * (*v2).vectorModul()) == 1;

}

void orthogonalityFunc(Vector *v1, Vector *v2) {

    cout << (Orthogonality(v1, v2) ? "Векторы ортогональны" : "Векторы не ортогональны") << endl;

}

void collinearityFunc(Vector *v1, Vector *v2) {

    cout << (Collinearity(v1, v2) ? "Векторы коллинеарны" : "Векторы не коллинеарны") << endl;

}

void vectorMain() {

    const unsigned int N = 10;
    Vector *data[N];

    for (int i = 0; i < N; ++i) {

        int rnd = Random(1, 5);
        data[i] = new Vector{rnd};

        for (int j = 0; j < rnd; ++j) {
            data[i]->pointerArray[j] = Random(-50, 50);
        }

        cout << "№" << i << ": ";
        data[i]->vectorOut();

    }

    cout << "Какие 2 вектора сравнить??" << endl;
    int index1, index2;
    cin >> index1;
    cin >> index2;
    orthogonalityFunc(data[index1], data[index2]);
    collinearityFunc(data[index1], data[index2]);


    cout << "Введите вектор размерности 3" << endl;
    Vector v1{3};
    v1.setVector();
    v1.vectorOut();
    v1++.vectorOut();
    (v1 * 5).vectorOut();

    delete data[N];
    cout << "Массив удален" << endl;


};

