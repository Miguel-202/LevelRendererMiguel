#version 330 // GLSL 3.30
// an ultra simple glsl vertex shader

//uniform mat4 worldMatrix;
//uniform mat4 viewProjection;

//in vec3 local_pos;
layout(location = 0) in vec3 local_pos;
layout(location = 1) in vec3 local_uvw;
layout(location = 2) in vec3 local_nrm;

out vec3 world_nrm;
out vec3 worldPos;
out vec3 world_uvw;
out vec3 textCords;


struct OBJ_ATTRIBUTES
{
	vec3    Kd; // diffuse reflectivity
	float	d; // dissolve (transparency) 
	vec3    Ks; // specular reflectivity
	float   Ns; // specular exponent
	vec3    Ka; // ambient reflectivity
	float   sharpness; // local reflection map sharpness
	vec3    Tf; // transmission filter
	float   Ni; // optical density (index of refraction)
	vec3    Ke; // emissive reflectivity
	uint    illum; // illumination model
};
layout(row_major) uniform UBO_DATA
{
	vec4 sunDirection, sunColor;
	vec4 lightsPos[2];
	vec4 lightCol[2];
	mat4 viewProjection;
	mat4 worldMatrix;
	OBJ_ATTRIBUTES material;
	vec4 cameraPos;
};
void main()
{
	// Transform the vertex position from local space to world space
	textCords = local_pos;
    vec4 world_pos = vec4(local_pos, 1.0) *  worldMatrix;
    worldPos = world_pos.xyz;

    // Transform the vertex normal from local space to world space
    world_nrm = normalize((vec4(local_nrm, 0.0) * worldMatrix).xyz );
    // Calculate the final position in clip space
    gl_Position = world_pos * viewProjection;
}