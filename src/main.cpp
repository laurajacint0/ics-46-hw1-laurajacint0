#include <iostream>
using namespace std;
#include "String.h"

void test_constructors_and_print()
{
    cout << "Constructor and operator << TESTS" << endl;

    // FYI these two lines and use both constructors, print(), and operator <<
    String s("Hello World");
    cout << "\"" << s << "\"" << endl;

    //...your code continues here
}

void test_assignment()
{
    cout << "Assignment TESTS" << endl;
    //...your code continues here
}

void test_relationals()
{
    cout << "Relational TESTS" << endl;
    //...your code continues here
}

void test_reverse()
{
    cout << "Reverse TESTS" << endl;
    //...your code continues here
}


void test_concatenate()
{
    cout << "Concatenate TESTS" << endl;
    //...your code continues here
}

void test_indexOf()
{
    cout << "indexOf TESTS" << endl;
    //...your code continues here
}

int main()
{
    test_constructors_and_print();
    test_assignment();
    test_relationals();
    test_reverse();
    test_concatenate();
    test_indexOf();
    //...rest of code
    return 0;
}