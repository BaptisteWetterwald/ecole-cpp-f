#include <iostream>
#include "main.h"
#include "my_class.h"

using namespace std;

int main() {
    // make string from char array
    /*string text = string("Hello World!");
    print(text);*/

    my_class my_class1 = my_class("Hello World!");
    my_class1.print_text();

    return 0;
}

void print(const string& text)  {
    cout << text << endl;
}