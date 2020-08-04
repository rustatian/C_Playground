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
    Rectangle(): width(0), height(0) {

    };

    explicit Rectangle(Square square);

public:
    int width;
    int height;
};

void use_rectangle(Rectangle rectangle);


struct Rectangle2 {
    int lenght;
};

int main() {
    Square square;
    // use_rectangle(square); // error when explicit

    Rectangle rectangle;
    std::cout << "Width: " << rectangle.width << std::endl;  // 0
    std::cout << "Height: " << rectangle.height << std::endl; // 0

    return EXIT_SUCCESS;
}