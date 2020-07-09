//
// Created by Valery Piashchynski on 11/10/19.
//

#include <thread>

class background_task {
public:
    void operator()() const {
//        do_something();
//        do_something_else();
    }
};

background_task f;
std::thread my_thread(f);

std::thread my_thread2((background_task() // <-- overloaded operator
));
std::thread my_thread3{background_task()}; //declare my_thread3 as variable

// thread and lambda expression
std::thread my_thread4([] {
   //operation1
   //operation2
});