#pragma once

#include <ostream>
#include "cmath"
#include "Other.h"

using namespace std;

class BoolVector {
public:
    int n;
    bool *pointerArray;

    BoolVector() {

        n = 3;
        pointerArray = new bool[n];

    }

    BoolVector(int num) {

        n = num;
        pointerArray = new bool[n];

    }

    void setBoolVector() {

        for (int i = 0; i < n; i++) {
            cout << "Введите элемент вектора № " << i << ": ";
            cin >> pointerArray[i];
        }

    }

    void fillingTheBoolVectorRandom() {

        for (int i = 0; i < n; i++) {

            int k = Random(-50, 50);
            k > 0 ? pointerArray[i] = true : pointerArray[i] = false;

        }

    }

    ~BoolVector() {

        delete[] pointerArray;

    }

    BoolVector(const BoolVector &ob) {

        n = ob.n;
        pointerArray = new bool[n + 1];

        if (!pointerArray) {
            cout << "Error";
            cin.get();
            return;
        }
        for (int i = 0; i <= n; i++) {
            pointerArray[i] = ob.pointerArray[i];
        }

    }

    void boolVectorOut() {

        string s = "{";
        for (int i = 0; i < n; i++) {

            s += " " + to_string(pointerArray[i]) + ",";

        }

        s.pop_back();
        s += " }";
        cout << s << endl;

    }

    void boolVectorNegative() {

        for (int i = 0; i <= n; i++) {

            pointerArray[i] = !pointerArray[i];

        }

    }

    void boolVectorDisjunction(BoolVector *anotherVector) {

        if (n == anotherVector->n) {

            for (int i = 0; i < n; i++) {

                pointerArray[i] = anotherVector->pointerArray[i] || pointerArray[i];

            }

        } else {

            cout << "Размерности векторов не равны" << endl;

        }

    }

    void boolVectorConjuction(BoolVector *anotherVector) {

        if (n == anotherVector->n) {

            for (int i = 0; i < n; i++) {

                pointerArray[i] = anotherVector->pointerArray[i] && pointerArray[i];

            }

        } else {

            cout << "Размерности векторов не равны" << endl;

        }

    }

    void boolVectorCounter() {

        int true_count = 0;
        int false_count = 0;

        for (int i = 0; i < n; i++) {

            pointerArray[i] ? ++true_count : ++false_count;

        }

        cout << "1: " << true_count << "\t" << "0: " << false_count << "\t" << endl;

    }

    bool operator==(const BoolVector &rhs) const {

        return pointerArray == rhs.pointerArray;

    }

    bool operator!=(const BoolVector &rhs) const {

        return !(rhs == *this);

    }

    BoolVector operator=(const BoolVector &rhs) const {

        for (int i = 0; i < n; i++) {

            pointerArray[i] = rhs.pointerArray[i];

        }

        return *this;

    }

    BoolVector operator||(const BoolVector &anotherVector) const {

        if (n == anotherVector.n) {

            for (int i = 0; i < n; i++) {

                pointerArray[i] = anotherVector.pointerArray[i] || pointerArray[i];

            }

        } else {

            cout << "Размерности векторов не равны" << endl;

        }

        return *this;

    }

    BoolVector operator&&(const BoolVector &anotherVector) const {

        if (n == anotherVector.n) {

            for (int i = 0; i < n; i++) {

                pointerArray[i] = anotherVector.pointerArray[i] && pointerArray[i];

            }

        } else {

            cout << "Размерности векторов не равны" << endl;

        }

        return *this;

    }


    BoolVector &operator!() {

        boolVectorNegative();

        return *this;

    }


};

BoolVector *changeBoolVector(BoolVector &v1, BoolVector &v2) {

    v2 = !v2;

    BoolVector v1_copy{v1};

    v1 = v1_copy && v2;

    return &v1;

}

void boolVectorMain() {

    int const N = 5;
    BoolVector *data_1[N];
    BoolVector *data_2[N];

    int n = Out("Введите количество элементов в векторах ");

    for (int i = 0; i < N; ++i) {

        data_1[i] = new BoolVector{n};
        data_1[i]->fillingTheBoolVectorRandom();
        cout << " №" << i + 1 << " ";
        data_1[i]->boolVectorOut();

    }

    cout << endl;

    for (int i = 0; i < N; ++i) {

        data_2[i] = new BoolVector{n};
        data_2[i]->fillingTheBoolVectorRandom();
        cout << " №" << i + 1 << " ";
        data_2[i]->boolVectorOut();

    }

    cout << endl;

    for (int i = 0; i < N; ++i) {

        data_1[i] = changeBoolVector(*data_1[i], *data_2[i]);
        cout << " №" << i + 1 << " ";
        data_1[i]->boolVectorOut();

    }


}
