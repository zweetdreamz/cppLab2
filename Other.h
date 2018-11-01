#pragma once

#include <string>
#include <iostream>
#include <random>

using namespace std;

int Random(int min, int max) {

    if (min > max) {
        cout << "Некоректно введены данные" << endl;
        cin.get();
        return NAN;
    }
    random_device rd;   //  недетерминированный генератор
    mt19937 gen(rd());  // ядро рандома
    uniform_int_distribution<> dist(min, max); // распределитель результатов между

    return dist(gen);

};

int Out(string s) {

    int x;
    cout << s << endl;
    cin >> x;
    return x;

}

enum Fill {
    rnd,
    empty,
    manual
};