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

struct Square {
    int size;
};

class Rectangle {
public:
    Rectangle();

    Rectangle(Square square);
};

void use_rectangle(Rectangle rectangle);


int main() {
    Square square;
    use_rectangle(square);
    Rectangle obj;
    Rectangle obj2(square);

    return EXIT_SUCCESS;
}