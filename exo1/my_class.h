//
// Created by Baptiste  WETTERWALD on 09/11/2023.
//

#ifndef CPP_ISMAILFAWAZ_MY_CLASS_H
#define CPP_ISMAILFAWAZ_MY_CLASS_H

#include <string>
#include <iostream>

class my_class {
private:
    std::string text;
public:
    void print_text(){
        std::cout << text << std::endl;
    }
    my_class(const std::string text);
};


#endif //CPP_ISMAILFAWAZ_MY_CLASS_H
