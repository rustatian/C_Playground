#ifndef R9_ANIMAL_H
#define R9_ANIMAL_H

#include <string>

class Animal {
public:
    Animal() = delete;

    explicit Animal(std::string n);

    std::string name() const;

protected:
    std::string name_;
private:
    virtual std::string name_impl() const = 0;
};

#endif //R9_ANIMAL_H
