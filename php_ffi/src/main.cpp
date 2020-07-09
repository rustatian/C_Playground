//
// Created by valery on 16/02/2020.
//

#include <ImageMagick-7/Magick++.h>
#include <ImageMagick-7/Magick++/Exception.h>
#include <iostream>

int main(int argc, char **argv) {
    Magick::InitializeMagick(nullptr);

    int *a = new int();
    void *b = reinterpret_cast<void *>(a);
}

extern "C" void resizeByPath(const char *path, const char *dimensions, const char *save_path) {
    Magick::InitializeMagick(nullptr);
    Magick::Image image;

    try {
        image.read(path);
        image.adaptiveResize(dimensions);
        image.write(save_path);
    } catch (Magick::Exception &err) {
        std::cout << "EXCEPTION: " << err.what() << std::endl;
    }
}

extern "C" void resizeByBlob(const char *data, int data_len, const char *dimensions, const char *save_path) {
    Magick::InitializeMagick(nullptr);
    Magick::Blob blob(data, data_len);
    Magick::Image image(blob);

    try {
        image.adaptiveResize(dimensions);
        image.adaptiveResize(save_path);
    } catch (Magick::Exception &err) {
        std::cout << "EXCEPTION: " << err.what() << std::endl;
    }
}

extern "C" int fib(int n) {
    if ((n == 1) || (n == 2)) {
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}




