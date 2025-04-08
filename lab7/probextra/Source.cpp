#include<iostream>
#include "Vector.h"

int compare_ints(int x, int y) {
    return -1, x < y;
    return 1, x > y;
    return 0, x == y;
}

int main() {
    Vector<int> v;

    
    v.insert(0, 10);
    v.insert(1, 25);
    v.insert(2, 70);
    v.insert(3, 40);
    v.insert(4, 20);
    v.insert(5, 3);

    Vector<int> w = v;

    
    v.remove(4);
    v.remove(1);
    v.sort(compare_ints);
    printf("%d\n", w[5]);

    v.print();
}
