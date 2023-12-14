#include <iostream>
#include <fstream>

int main(){
    std::ifstream in("Lenna.bmp", std::ios::binary);
    if (!in){
        std::cout << "failed to open file" << std::endl;
        return 1;
    }
    unsigned char buf[64];
    //READING BITMAPFILEHEADER
    in.read((char*)buf, 2);
    std::cout << "First two bytes: \n";
    std::cout << (char)buf[0] << (char)buf[1] << std::endl;

    int32_t file_sz;
    in.read((char*)&file_sz, 4);
    std::cout << "File size: " << file_sz << std::endl;
    in.seekg(4, std::ios::cur);

    int32_t offset;
    in.read((char*)&offset, 4);
    std::cout << "offset: " << offset << std::endl;

    //READING BITMAPINFOHEADER
    in.seekg(4, std::ios::cur);
    int32_t width;
    int32_t height;
    in.read((char*)&width, 4);
    in.read((char*)&height, 4);
    std::cout << "size: " << width << ' ' << height << std::endl;
    in.seekg(2, std::ios::cur);
    int16_t depth;
    in.read((char*)&depth, 2);
    std::cout << "depth: " << depth << std::endl;
    in.seekg(4, std::ios::cur);
    int32_t img_size;
    in.read((char*)&img_size, 4);
    std::cout << "img size: " << img_size << std::endl;
    // in.seekg(16, std::ios::cur);

    unsigned char b_min = 255;
    unsigned char b_max = 0;
    unsigned char g_min = 255;
    unsigned char g_max = 0;
    unsigned char r_min = 255;
    unsigned char r_max = 0;
    std::ofstream out("out.bmp", std::ios::binary);
    in.seekg(0, std::ios::beg);
    in.read((char*)buf, 54);
    out.write((char*)buf, 54);
    /*for (int row = 0; row < height; ++row)
        for (int col = 0; col < width; ++col)
        {
            in.read((char*) buf, 3);
            if ((row < 100) && (col < 100)) {
                buf[0] = buf[1] = buf[2] = 0;
            }
            out.write((char*) buf, 3);
            if (buf[0] > b_max) b_max = buf[0];
            if (buf[0] < b_min) b_min = buf[0];
            if (buf[1] > g_max) g_max = buf[1];
            if (buf[1] < g_min) g_min = buf[1];
            if (buf[2] > r_max) r_max = buf[2];
            if (buf[2] < r_min) r_min = buf[2];
        }
    in.seekg(54, std::ios::beg);*/
    for (int row = 0; row < height; ++row)
        for (int col = 0; col < width; ++col)
        {
            in.read((char*)buf, 3);
            buf[0] = (col / width * row / width) / (0.5 * row - 255);
            buf[1] = (col / width * row / width) / (0.5 * row - 255);
            buf[2] = (0.5 * row - 255);
            /*buf[0] = (0.5 * row - 255);
            buf[1] = (0.5 * row - 255);
            buf[2] = col * (0.5 * row - 255);*/
            //buf[2] = (2 * col * (height / row)) - 255;
            //buf[2] = (col * (height / (row + 1))) - 255;
            /*in.read((char*)buf, 3);
            if (4 * col <= width) {
                buf[0] = 255;
                buf[1] = 0;
                buf[2] = 0;
            } else if (4 * col > width && 2 * col <= width) {
                buf[1] = 255;
                buf[0] = 0;
                buf[2] = 0;
            } else if (2 * col > width && 4 * col <= 3 * width) {
                buf[2] = 255;
                buf[0] = 0;
                buf[1] = 0;
            } else {
                buf[0] = 204;
                buf[1] = 153;
                buf[2] = 255;
            }*/
            
            /*buf[0] = (buf[0] - b_min)*255/(b_max-b_min);
            buf[1] = (buf[1] - g_min)*255/(g_max-g_min);
            buf[2] = (buf[2] - r_min)*255/(r_max-r_min);*/
            out.write((char*)buf, 3);
        }
    in.close();
    out.close();
    return 0;
}