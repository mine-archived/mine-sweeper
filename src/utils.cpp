//
// Created by Michael.Fan on 1/11/16.
//

#include "utils.h"

void utils::load_png_texture(std::string file_name) {
	png_t image;
	unsigned width, height;
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image.front());
	unsigned error = lodepng::decode(image, width, height, file_name);
	if (error) {
		std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
		return;
	}
	png_t fliped_image = flip_image_vertical(image, width, height);
	for (auto c : fliped_image) {
		std::cout << c << " ";
	}
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &fliped_image.front());
}


png_t utils::flip_image_vertical(png_t data, unsigned int width, unsigned int height) {
	unsigned int stride = width;
	png_t new_data(data.size());
	png_t::iterator it = new_data.begin();
	for (unsigned int i = 0; i < height; i++) {
		unsigned int j = height - i - 1;
//		std::cout << j << std::endl;
		new_data.insert(it + j * stride, data.at(i * stride), data.at((i +1) * stride));
	}
	return new_data;
}


