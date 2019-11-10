//
// Created by Valery Piashchynski on 11/10/19.
//

#include <iostream>
#include <thread>
#include "../include/hello_multithreading_world.hpp"

void hello() {
    std::cout << "Hello concurrent world!";
}

// passing args
void f(int i, std::string const &s);

std::thread t(f, 3, "hello");


int main(int, char **) {
    //std::terminate();
//    std::thread t(hello);
//    t.join();
    oops();
}

void f3(int i,std::string const& s);
void oops1(int some_param)
{
    char buffer[1024];
    sprintf(buffer, "%i",some_param);
    std::thread t2(f3,3,buffer);
    t2.detach();
}



void f2(int i,std::string const& s);
void oops(int some_param)
{
    char buffer[1024];
    sprintf(buffer, "%i",some_param);
    std::thread t(f2,3,buffer); // <-- implicit convertation, there is a big chance that function over before
    // buffer would be converted from char to std::string (UB)
    t.detach();
}


class X {
public:
    void do_lengthy_work();
};

X my_x;

std::thread t2(&X::do_lengthy_work, &my_x);
