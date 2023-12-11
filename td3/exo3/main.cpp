//
// Created by Baptiste WETTERWALD on 11/12/2023.
//

#include <iostream>
#include <queue>
#include <stack>
#include <cctype>

using namespace std;

bool isPalindrome(const string& input){
    stack<char> stack;
    queue<char> queue;

    for (char c : input) {
        if (isalpha(c)) {
            stack.push(c);
            queue.push(c);
        }
    }

    while (!stack.empty()) {
        if (stack.top() != queue.front()) {
            return false;
        }
        stack.pop();
        queue.pop();
    }

    return true;
}

int main(){
    cout << boolalpha;
    cout << "Is 'racecar' a palindrome? "
        << isPalindrome("racecar") << endl;
    cout << "Is 'hello' a palindrome? "
        << isPalindrome("hello") << endl;

    return 0;
}