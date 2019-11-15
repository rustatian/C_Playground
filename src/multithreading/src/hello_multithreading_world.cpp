//
// Created by Valery Piashchynski on 11/10/19.
//

#include <iostream>
#include <thread>
#include <numeric>
#include "../include/hello_multithreading_world.hpp"

void hello() {
    std::cout << "Hello concurrent world!";
}


int main(int, char **) {
    //std::terminate();
//    std::thread t(hello);
//    t.join();
//    oops();

//    void some_function();
//    void some_other_function();
//
//    std::thread t1(some_function);
//    std::thread t2=std::move(t1);
//    t1=std::thread(some_other_function);
//    std::thread t3;
//    t3=std::move(t2);
//    t1=std::move(t3);

    std::cout << std::thread::hardware_concurrency();
    std::accumulate(1,)
    return 0;
}

//std::thread g() {
//    void some_other_function2();
//    return std::thread(some_other_function2);
//}


class X {
public:
    void do_lengthy_work();
};

//X my_x;
//
//std::thread t2(&X::do_lengthy_work, &my_x);

///////////////////////////////// MOVE /////////////////////////////
//void process_big_object(std::unique_ptr<int>);

//std::unique_ptr<int> p(new int);
// p->prepare_data(42);
//std::thread t(process_big_object, std::move(p)); // by specifying std::move(p), the ownership of big_object
// is transferred into internal storage for the newly created thread and then into process_big_object