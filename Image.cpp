//
// Created by Ethan Nerney on 2018-12-09.
//

#include <fstream>
#include <array>
#include "Image.h"
using namespace std;

Image::Image(std::string filename): Shape(0,0), dimensions(173.,264.), start(0,0) {
    readBMP(filename, pixels);
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

void readPNG(string filename, vector<vector<Pixel>> &pixels) {

    std::ifstream file;
    size_t size = 0;

    std::cout << "Attempting to open " << filename << std::endl;

    file.open( filename, std::ios::in | std::ios::binary | std::ios::ate );

    unsigned int width, height;

    file.seekg(16);
    file.read((char *)&width, 4);
    file.read((char *)&height, 4);

    width = ntohl(width);
    height = ntohl(height);

    std::cout << "Picture is " << width << " pixels wide and " << height << " pixels high.\n";

    file.seekg( 0, std::ios::end );
    size = file.tellg();
    std::cout << "File size: " << size << std::endl;
    file.seekg( 0, std::ios::beg );

    char data[size - 8];
    file.seekg( 8 ); // skip the header
    file.read( data, size - 8);
    std::cout << "Data size: " << ((unsigned long long)file.tellg() - 8) << std::endl;

    if (file)
        std::cout << "all characters read successfully." << endl;
    else
        std::cout << "error: only " << file.gcount() << " could be read" << endl;

    vector<RGBColor> colors;
    for (int i = 0; i < size-8; i+=3){
       cout << int(data[i]) << endl;
    }


    int j = 0;
    for (int h = 0; h < height; h++) {
        vector<Pixel> p;
        for (int w = width-1; w >= 0; w--) {
            p.push_back(Pixel(Vector2D(w,h), colors[j]));
            j++;
        }
        j += 1;
        pixels.push_back(p);
    }

}

void readBMP(string filename, vector<vector<Pixel>> &pixels) {
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

    vector<RGBColor> colors;
    for (int i = dataSize - 4; i >= 0; i -= 3)
    {
        //cout << i << endl;
        temp = img[i];
        img[i] = img[i+2];
        img[i+2] = temp;

        int r = int(img[i] & 0xff), g = int(img[i+1] & 0xff), b = int(img[i+2] & 0xff);


        colors.push_back(RGBColor(b,r,g));
        std::cout << "R: " << int(img[i] & 0xff) << " G: " << int(img[i+1] & 0xff) << " B: " << int(img[i+2] & 0xff) << std::endl;
    }

    int j = 0;
    for (int h = 0; h < height; h++) {
        vector<Pixel> p;
        for (int w = width-1; w >= 0; w--) {
            p.push_back(Pixel(Vector2D(w,h), colors[j]));
            j++;
        }
        j += 1;
        pixels.push_back(p);
    }

}
