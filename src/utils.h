//
// Created by Michael.Fan on 1/11/16.
//

#ifndef MINE_SWEEPER_UTILS_H
#define MINE_SWEEPER_UTILS_H

#include <string>
#include <iostream>
#include <memory>
#include <lodepng.h>
#include <GL/glew.h>

class utils {
public:
		static void load_png_texture(std::string file_name);

private:
		static void flip_image_vertical(std::vector<unsigned char> *data, unsigned int width, unsigned int height);
};


#endif //MINE_SWEEPER_UTILS_H
