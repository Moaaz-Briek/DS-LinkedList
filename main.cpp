#include <iostream>

using namespace std;

#include "LinkedList.h"

void test_case_1() {
    LinkedList L;
    L.add(5);
    L.add(10);
    L.add(15);
    L.add(20);
    L.display();

    L.Remove(10);
    L.display();

    L.Remove(5);
    L.display();

    L.Remove(20);
    L.display();
}

void test_case_2() {
    LinkedList L;
    L.add(5);
    L.insertAfter(10, 5);
    L.insertAfter(15, 10);
    L.display();
}

void test_case_3() {
    LinkedList L;
    L.add(5);
    L.insertBefore(10, 5);
    L.insertBefore(15, 10);
    L.display();
}

void test_case_4() {
    LinkedList L;
    L.add(5);
    L.add(91);
    L.insertBefore(10, 5);
    L.insertBefore(15, 10);
    cout << L.getCount();
}

void test_case_5() {
    LinkedList L;
    L.add(5);
    L.add(91);
    L.insertBefore(10, 5);
    L.insertBefore(15, 10);
    L.getIndex(0);
}

int main()
{
    test_case_5();
    return 0;
}
