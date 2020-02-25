//
// Created by valery on 16/02/2020.
//

#include <ImageMagick-7/Magick++.h>
#include <ImageMagick-7/Magick++/Geometry.h>
#include <ImageMagick-7/Magick++/Exception.h>
#include <iostream>

int main(int argc, char **argv) {
    Magick::InitializeMagick(*argv);

    // Construct the image object. Seperating image construction from the
    // the read operation ensures that a failure to read the image file
    // doesn't render the image object useless.
    Magick::Image image;
    try {
        // Read a file into image object
        image.read("girl.gif");

        // Crop the image to specified size (width, height, xOffset, yOffset)
        image.crop(Magick::Geometry(100, 100, 100, 100));

        // Write the image to a file
        image.write("x.gif");
    }
    catch (Magick::Exception &error_) {
        std::cout << "Caught exception: " << error_.what() << std::endl;
        return 1;
    }
    return 0;
}


