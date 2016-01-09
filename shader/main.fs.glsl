#version 330 core

// Ouput data
out vec3 color;

uniform vec3 ourColor; //在程序代码中设置

void main()
{

	// Output color = red
	// color = vec3(1,0,0);
  color = ourColor;

}