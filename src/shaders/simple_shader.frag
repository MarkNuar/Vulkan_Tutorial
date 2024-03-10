#version 450

// Output to location 0, there are multiple locations
// outColor is the output of the fragment shader
layout(location = 0) out vec4 outColor;

void main() {
    // Red, fully opaque.
    outColor = vec4(1.0, 0.0, 0.0, 1.0);
}