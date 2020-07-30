#include "animal.h"

#include <cstring>
#include <utility>

Animal::Animal(std::string n) : name_(std::move(n)) {}

std::string Animal::name() const {
    return name_impl();
}