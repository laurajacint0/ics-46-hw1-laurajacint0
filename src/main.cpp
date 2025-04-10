#include <iostream>
using namespace std;
#include "String.h"

void test_constructors_and_print()
{
    cout << "Constructor and operator << TESTS" << endl;

    // FYI these two lines and use both constructors, print(), and operator <<
    String s("Hello World");
    cout << "\"" << s << "\"" << endl;

    // Testing the copy constructor
    String copy_s = s;
    cout << "Copy constructor: \"" << copy_s << "\"" << endl;

    // Testing the move constructor
    String move_s = String("Move Test");
    cout << "Move constructor: \"" << move_s << "\"" << endl;
}

void test_assignment()
{
    cout << "Assignment TESTS" << endl;
    // Testing the assignment operator (copy assignment)
    String s1("Original String");
    String s2;
    s2 = s1;
    cout << "Copy assignment: \"" << s2 << "\"" << endl;

    // Testing the move assignment operator
    String s3("Temporary String");
    String s4;
    s4 = move(s3);
    cout << "Move assignment: \"" << s4 << "\"" << endl;
}

void test_relationals()
{
    cout << "Relational TESTS" << endl;
    String s1("Hello");
    String s2("Hello");
    String s3("World");

    // Testing equality operator
    if (s1 == s2) {
        cout << "Equality operator: s1 == s2" << endl;
    }

    // Testing inequality operator
    if (s1 != s3) {
        cout << "Inequality operator: s1 != s3" << endl;
    }

    // Testing relational operators
    if (s1 < s3) {
        cout << "Less than operator: s1 < s3" << endl;
    }
    if (s3 > s1) {
        cout << "Greater than operator: s3 > s1" << endl;
    }
    if (s1 <= s2) {
        cout << "Less than or equal to operator: s1 <= s2" << endl;
    }
    if (s2 >= s1) {
        cout << "Greater than or equal to operator: s2 >= s1" << endl;
    }
}

void test_reverse()
{
    cout << "Reverse TESTS" << endl;
    String s("Reverse Me");
    String reversed = s.reverse();
    cout << "Reversed String: \"" << reversed << "\"" << endl;
}

void test_concatenate()
{
    cout << "Concatenate TESTS" << endl;
    String s1("Hello");
    String s2(" World");
    String concatenated = s1 + s2;
    cout << "Concatenated String: \"" << concatenated << "\"" << endl;

    s1 += s2;
    cout << "After using operator+=: \"" << s1 << "\"" << endl;
}


void test_indexOf()
{
    cout << "indexOf TESTS" << endl;
    String s("Find the index");
    
    // Testing indexOf(char)
    int index = s.indexOf('t');
    cout << "First occurrence of 't': " << index << endl;

    // Testing indexOf(String)
    index = s.indexOf(String("the"));
    cout << "First occurrence of 'the': " << index << endl;
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