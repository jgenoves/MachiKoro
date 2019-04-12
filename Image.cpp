//
// Created by Ethan Nerney on 2018-12-09.
//

#include <fstream>
#include <array>
#include "Image.h"
using namespace std;

Image::Image(std::string filename): Shape(0,0), dimensions(173.,264.), start(0,0) {
    readBMP(filename, *this);
    //readPNG(filename, pixels);
}

void Image::draw() const {
    glBegin (GL_POINTS);
    for (int h = start.y; h < start.y + dimensions.y; h++) {
        for (int w = start.x; w < start.x + dimensions.x; w++) {
            if (h < pixels.size() and w < pixels[0].size()) {
                Pixel p = pixels[h][w];
                glColor3f(p.color.r, p.color.g, p.color.b);
                glVertex2f(position.x + p.pos.x - start.x, position.y + p.pos.y - start.y);
            }
        }
    }
    glEnd();
}


double Image::calculateArea() const {return 0.;}
double Image::calculatePerimeter() const {return 0.;}


void readBMP(string filename, Image &i) {
    filename = "../" + filename;
    static constexpr size_t HEADER_SIZE = 54;

    std::ifstream bmp(filename, std::ios::binary);

    std::array<char, HEADER_SIZE> header;
    bmp.read(header.data(), header.size());

    auto fileSize = *reinterpret_cast<uint32_t *>(&header[2]);
    auto dataOffset = *reinterpret_cast<uint32_t *>(&header[10]);
    auto width = *reinterpret_cast<uint32_t *>(&header[18]);
    auto height = *reinterpret_cast<uint32_t *>(&header[22]);
    auto depth = *reinterpret_cast<uint16_t *>(&header[28]);

    std::cout << "fileSize: " << fileSize << std::endl;
    std::cout << "dataOffset: " << dataOffset << std::endl;
    std::cout << "width: " << width << std::endl;
    std::cout << "height: " << height << std::endl;
    std::cout << "depth: " << depth << "-bit" << std::endl;

    std::vector<char> img(dataOffset - HEADER_SIZE);
    bmp.read(img.data(), img.size());

    auto dataSize = ((width * 3 + 3) & (~3)) * height;
    img.resize(dataSize);
    bmp.read(img.data(), img.size());

    char temp = 0;

    vector <RGBColor> colors;

    for (int i = dataSize - 4; i >= 0; i -= 3)
    {
        temp = img[i];
        img[i] = img[i+2];
        img[i+2] = temp;

        int r,g,b;
        r = img[i] & 0xff;
        g = img[i] & 0xff;
        b = img[i+2] & 0xff;

        for (int i = 0; i < 1; i++) {
            colors.push_back(RGBColor(r, g, b));
        }

        //std::cout << "R: " << int(img[i] & 0xff) << " G: " << int(img[i+1] & 0xff) << " B: " << int(img[i+2] & 0xff) << std::endl;

    }
    std::cout << "Length of Colors: " << colors.size() << std::endl;
    std::cout << "Number of Pixels: " << width * height << std::endl;
    int j = 0;
    for (int c = 0; c < height; c++) {
        vector<Pixel> col;
        for (int r = 0; r < width; r++) {
            Pixel p(Vector2D(r,c), colors[j]);
            col.push_back(p);
            j++;
        }

        i.pixels.push_back(col);
    }



}
