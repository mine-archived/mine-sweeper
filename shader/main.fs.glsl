#version 330 core

in vec2 TexCoord;

out vec4 color;

uniform vec3 ourColor;
uniform sampler2D ourTexture;

void main()
{
  color = texture(ourTexture, TexCoord);
}