#ifdef GL_ARB_bindless_texture
layout(bindless_sampler) uniform sampler2D Albedo;
layout(bindless_sampler) uniform sampler2D SpecMap;
#else
uniform sampler2D Albedo;
uniform sampler2D SpecMap;
#endif

in vec2 uv;
in vec4 color;
out vec4 FragColor;

vec3 getLightFactor(vec3 diffuseMatColor, vec3 specularMatColor, float specMapValue);

void main(void)
{
#ifdef GL_ARB_bindless_texture
    vec4 col = texture(Albedo, uv);
#ifdef SRGBBindlessFix
    col.xyz = pow(col.xyz, vec3(2.2));
#endif
#else
    vec4 col = texture(Albedo, uv);
#endif
    col.xyz *= pow(color.xyz, vec3(2.2));
    float specmap = texture(SpecMap, uv).g;
    FragColor = vec4(getLightFactor(col.xyz, vec3(1.), specmap), 1.);
}
