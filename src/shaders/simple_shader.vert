#version 450

vec2 positions[3] = vec2[](
    vec2(0.0, -0.5),
    vec2(0.5, 0.5),
    vec2(-0.5,   0.5)
);

void main() {
    // Normalized device coordinates, w = 1
    // Z defined the depth, used for determining order to draw
    gl_Position = vec4(positions[gl_VertexIndex], 0.0, 1.0);
}