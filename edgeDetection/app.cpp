#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image_write.h"
#include "stb_image.h"


float assignValues (int red, int green, int blue) {
    return 0.2126*red + 0.7152*green + 0.0722*blue;
}


std::vector<float> differentiate(std::vector<float> scalars){
    std::vector<float> slopes;
    for (size_t i = 0; i+1 < scalars.size(); i++) {
        float slope = scalars[i+1] - scalars[i];
        slopes.push_back(slope);
    }
    return slopes;
}

void makeImage(std::vector<float> derivatives, int width, int height) {
    std::vector<unsigned char> pixel(derivatives.size()*3, 0);
    for (int i = 0; i < derivatives.size(); i++) {
        if (derivatives[i] <= 1 && derivatives[i] >= -1) {
            pixel[i*3 + 0] = 255;
            pixel[i*3 + 1] = 255;
            pixel[i*3 + 2] = 255;
        }
    }
    stbi_write_png(
        "edges.png",
        width,
        height,
        3,
        pixel.data(),
        width * 3
    );
}

int main(){
    int width, height, channel;
    int red, green, blue;
    std::vector<float> scalars, derivatives;
    unsigned char* colorValues;
    float scalar;

    unsigned char *image = stbi_load("image.jpg", &width, &height, &channel, 3);
    size_t imageSize = width*height*channel;
        if (!image) {
            std::cout << "Image not accessible";
            return 0;
        }

    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++) {
            colorValues = image + (y*width + x) * 3;
            red = (int)colorValues[0];
            green = (int)colorValues[1];
            blue = (int)colorValues[2];
            scalar = assignValues(red, green, blue);
            scalars.push_back(scalar);
        }
    }
    stbi_image_free(image);

    derivatives = differentiate(scalars);
    makeImage(derivatives, width, height);
    return 0;
}