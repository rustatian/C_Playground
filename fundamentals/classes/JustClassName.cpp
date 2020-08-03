#include "JustClassName.h"
#include <stdlib.h>
#include <iostream>

class JustClassName {
private:
    int privateDataMember;

    int privateMemberFunction();

protected:
    float protectedDataMember;

    float protectedMemberFunction();

public:
    double publicDataMember;

    double publicMemberFunction();
};


/// CONST/DESTR

struct Rectangle {
    int height;
    int width;
};

int main() {
    Rectangle rectangle;
    std::cout << "Height: " << rectangle.height << std::endl;
    return EXIT_SUCCESS;
}