#pragma once

#include "Other.h"
#include <algorithm>
#include <ostream>

using namespace std;

class Stack {
public:

    int size;
    int *ptrStack;
    int n;

    Stack(Fill fill) {

        int n = Out("Введите число элементов в стэке");

        switch (fill) {

            case rnd:

                this->n = n;
                ptrStack = new int[n];
                size = 0;

                for (int i = 0; i < n; ++i) {

                    ptrStack[i] = Random(-100, 100);
                    ++size;

                }

                break;

            case empty:

                this->n = n;
                ptrStack = new int[n];
                size = 0;

                break;

            case manual:

                this->n = n;
                ptrStack = new int[n];
                size = 0;

                for (int i = 0; i < n; ++i) {

                    ptrStack[i] = Out("Введите элемент стека №:" + to_string(i + 1) + " ");
                    ++size;

                }

                break;

        }

    }

    Stack(int n) {

        this->n = n;
        ptrStack = new int[n];
        size = 0;

    }

    ~Stack() {

        delete[] ptrStack;
        cout << "Стэк удален " << endl;

    }

    void stackInput() {

        int i = 0;

        while (n != size) {

            ptrStack[i] = Out("Введите элемент стека №:" + to_string(i + 1) + " ");
            ++i;
            ++size;

        }

    }

    void stackOut() {

        string s = "[";
        if (size > 0) {

            for (int i = size - 1; i >= 0; --i) {

                s += " " + to_string(ptrStack[i]) + ",";

            }

            s.pop_back();

        }

        s += " ]";
        cout << s << endl;


    }

    void fillingTheStackRandom() {

        for (int i = 0; i < n; ++i) {

            ptrStack[i] = Random(-100, 100);
            ++size;

        }

    }

    void stackInfo() {

        cout << "Стэк: " << endl;
        this->stackOut();
        cout << "Всего места: \t" << this->n << "\t Свободно места: \t" << this->n - this->size << endl;

    }

    void stackPush(int k) {

        if (size < n) {

            this->ptrStack[size] = k;
            size++;

        } else {


            auto *ptr_newStack = new Stack{size + 1};
            ptr_newStack->n = n + 1;
            ptr_newStack->size = 0;

            for (int i = 0; i < n; ++i) {

                ptr_newStack->ptrStack[i] = ptrStack[i];
                ++ptr_newStack->size;

            }

            ptr_newStack->ptrStack[n] = k;
            ++ptr_newStack->size;

            ptrStack = new int[ptr_newStack->n];
            n++;
            size = ptr_newStack->size;

            for (int i = 0; i < ptr_newStack->n; ++i) {

                ptrStack[i] = ptr_newStack->ptrStack[i];

            }

            delete ptr_newStack;

        }

    }

    void stackfewPush() {

        int m = Out("Сколько элементов хотите добавить?");

        if (size + m > n) {

            for (int i = 0; i < m; ++i) {

                int k = Out("Введите элемент: ");

                this->stackPush(k);

            }

        }

    }

    int stackPopReturn() {

        int k = ptrStack[size - 1];
        ptrStack[size - 1] = NAN;
        --size;

        return k;

    }

    void stackPop() {

        ptrStack[size - 1] = NAN;
        --size;

    }

    int *stackFewPopReturnRequest() { // последний элемент NULL

        int m = Out("Сколько элементов вытащить? ");
        int *ptr_arr = new int[m];

        for (int i = 0; i < m; ++i) {

            ptr_arr[i] = stackPopReturn();

        }

        return ptr_arr;

    }

    int *stackFewPopReturnNonRequest(int k) {

        int *ptr_arr = new int[k];

        for (int i = 0; i < k; ++i) {

            ptr_arr[i] = stackPopReturn();

        }
        reverse(ptr_arr, ptr_arr + k);

        return ptr_arr;

    }

    void stackFewPop(int k) {

        for (int i = 0; i < k; ++i) {

            stackPop();

        }

    }

    Stack operator+(int k) {

        this->stackPush(k);

        return *this;

    }

    Stack operator+=(int k) {

        this->stackPush(k);

        return *this;

    }

    Stack operator-(int k) {

        if (n < k) {
            cout << "Вы пытаетесь удалить больше элементов, чем в есть в стэке " << endl;
            cin.get();
            return *this;

        }

        stackFewPop(k);

        return *this;

    }

    Stack operator-=(int k) {

        if (n < k) {
            cout << "Вы пытаетесь удалить больше элементов, чем в есть в стэке " << endl;
            cin.get();
            return *this;

        }

        stackFewPop(k);

        return *this;

    }

};

Stack *deleteIthStackElement(Stack *ptr_Stack) {

    int index = Out("Какой элемент удалить из стека? ");

    if (index == 1) {

        ptr_Stack->stackPop();

    } else {

        int *ptr_arr = ptr_Stack->stackFewPopReturnNonRequest(index - 1);

        ptr_Stack->stackPop();

        for (int i = 0; i < index - 1; i++) {

            ptr_Stack->stackPush(ptr_arr[i]);

        }

        delete[] ptr_arr;

    }

    return ptr_Stack;

}

void stackMain() {

    int const N = 5;
    Stack *data[N];

    int n = Out("Введите количество элементов в стэках ");

    for (int i = 0; i < N; ++i) {

        data[i] = new Stack{n};
        data[i]->fillingTheStackRandom();
        cout << " №" << i + 1 << " ";
        data[i]->stackInfo();

    }

    for (int i = 0; i < N; ++i) {

        data[i] = deleteIthStackElement(data[i]);
        data[i]->stackInfo();

    }


}