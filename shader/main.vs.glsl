#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout (location = 2) in vec2 texCoord;

out vec2 TexCoord;

uniform mat4 MVP;

void main(){

	// Output position of the vertex, in clip space : MVP * position
	gl_Position =  MVP * vec4(vertexPosition_modelspace,1);

  TexCoord = texCoord;

}

