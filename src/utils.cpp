//
// Created by Michael.Fan on 1/11/16.
//

#include "utils.h"

void utils::load_png_texture(std::string file_name) {
	std::vector<unsigned char> image;
	unsigned width, height;
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image.front());
	unsigned error = lodepng::decode(image, width, height, file_name);
	if (error) {
		std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
		return;
	}
	flip_image_vertical(&image, width, height);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image.front());
}


void utils::flip_image_vertical(std::vector<unsigned char> *data, unsigned int width, unsigned int height) {
	unsigned int size = width * height * 4;
	unsigned int stride = sizeof(char) * width * 4;
	auto new_data = std::make_shared<std::vector<unsigned char>>();
	for (unsigned int i = 0; i < height; i++) {
		unsigned int j = height - i - 1;
		memcpy(new_data.get() + j * stride, data + i * stride, stride);
	}
	memcpy(data, &new_data, size);
}


