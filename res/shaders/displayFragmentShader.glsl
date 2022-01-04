#version 450 core

in vec2 textureCoords;

uniform vec2 resolution;
uniform sampler2D renderedTexture;

layout(location = 0) out vec4 color;

void main(void) {
    //    color = vec4(1, 0, 0, 1);
    color = texture(renderedTexture, gl_FragCoord.xy / resolution);
}