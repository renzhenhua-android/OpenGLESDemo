#version 300 es

// Set the default precision to medium. We don't need as high of a precision in the fragment shader.
precision mediump float;

// The position of the light in eye space.
uniform vec3 u_LightPos;

// Interpolated position for this fragment.
in vec3 v_Position;
// This is the color from the vertex shader interpolated across the  triangle per fragment.
in vec4 v_Color;
// Interpolated normal for this fragment.
in vec3 v_Normal;

out vec4 o_fragColor;

// The entry point for our fragment shader.
void main()
{
    // Will be used for attenuation.
    float distance = length(u_LightPos - v_Position);
    // Get a lighting direction vector from the light to the vertex.
    vec3 lightVector = normalize(u_LightPos - v_Position);
    // Calculate the dot product of the light vector and vertex normal. If the normal and light vector are
    // pointing in the same direction then it will get max illumination.
    float diffuse = max(dot(v_Normal, lightVector), 0.1);
    // Add attenuation.
    diffuse = diffuse * (1.0 / (1.0 + (0.25 * distance * distance)));
    // Multiply the color by the diffuse illumination level to get final output color.
    o_fragColor = v_Color * diffuse;
}