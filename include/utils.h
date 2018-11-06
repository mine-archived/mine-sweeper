//
// Created by Michael.Fan on 1/11/16.
//

#ifndef MINE_SWEEPER_UTILS_H
#define MINE_SWEEPER_UTILS_H

#include <string>
#include <iostream>
#include <memory>
#include <algorithm>
#include <lodepng.h>
#include <GL/glew.h>

using png_t = std::vector<unsigned char>;

class utils {
public:
		static void load_png_texture(std::string file_name);

private:
		static png_t flip_image_vertical(png_t data, unsigned int width, unsigned int height);
};


#endif //MINE_SWEEPER_UTILS_H
