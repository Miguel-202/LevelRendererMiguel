#version 330 // GLSL 3.30
in vec3 world_nrm;
in vec3 worldPos;
in vec3 world_uvw;
in vec3 textCords;
out vec4 Pixel;
// an ultra simple glsl fragment shader
// TODO: Part 3a
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
uniform samplerCube skybox;

//vec3 calculateDiffuse(vec3 lightDirection, vec3 normal, vec3 diffuseColor) {
//    float diffuseIntensity = max(dot(lightDirection, normal), 0.0);
//    return diffuseIntensity * diffuseColor;
//}
//
//vec3 calculateSpecular(vec3 lightDirection, vec3 normal, vec3 viewDirection, vec3 specularColor, float specularExponent) {
//    vec3 reflectionDirection = reflect(-lightDirection, normal);
//    float specularIntensity = pow(max(dot(reflectionDirection, viewDirection), 0.0), specularExponent);
//    return specularIntensity * specularColor;
//}

void main() 
{	//SKYBOX HARDCODED
	if(material.illum == 1000u)
	{
	 // Calculate the diffuse color for the current pixel using a texture sample
		 // Assuming the texture coordinates are stored in the world_uvw variable
		vec4 diffuseColor = texture(skybox, textCords);
		Pixel = diffuseColor;
		return;
	}


	// Calculate the ambient color
	vec3 ambientColor = material.Ka * sunColor.rgb * 0.5;
	
	// Calculate the diffuse reflection
	vec3 sunDirectionWorld = normalize(vec3(worldMatrix * sunDirection));
	float diffuseReflection = max(0.0, dot(world_nrm, sunDirectionWorld));
	
	// Calculate the specular reflection
	vec3 viewDirection = normalize(cameraPos.xyz - worldPos);
	vec3 reflectDirection = reflect(-sunDirectionWorld, world_nrm);
	float specularReflection = pow(max(0.0, dot(viewDirection, reflectDirection)), material.Ns);
	
	vec3 totalDirect = vec3(0);
	for (int i = 0; i < 2; i++) 
	{
	    vec3 lightDir = normalize(lightsPos[i].xyz - worldPos);
	    float diffuse = max(0.0, dot(world_nrm, lightDir));
	    float distance = length(lightsPos[i].xyz - worldPos);
	    float attenuation = 1.0 / (1.0 + 0.1 * distance + 0.01 * distance * distance);
	    totalDirect += lightCol[i].xyz * diffuse * attenuation;
	}
	
	vec3 lightDir = normalize(sunDirection.xyz - worldPos);
	float diffuse = max(0.0, dot(world_nrm, lightDir));
	
	// Combine the colors and reflections to get the final pixel color
	vec3 finalColor = clamp(totalDirect + ambientColor, 0.0, 1.0) * material.Kd + specularReflection + diffuseReflection + material.Ke;
	Pixel = vec4(finalColor, material.d);

//
//	// Bloom effect
//	float blurSize = 0.05;
//	vec3 blurredColor = vec3(0.0);
//	for (float x = -4.0; x <= 4.0; x += 1.0) 
//	{
//		for (float y = -4.0; y <= 4.0; y += 1.0) 
//		{
//			vec2 offset = vec2(x, y) * blurSize;
//			vec3 sampleColor = material.Kd; // No texture, so use a constant color
//			blurredColor += sampleColor;
//		}
//	}
//	blurredColor /= 81.0; // 9x9 kernel size
//	finalColor += blurredColor * 0.5; // Add blurred image with weight
//
//	Pixel = vec4(finalColor, material.d);



//		
//    // Calculate the ambient color
//    vec3 ambientColor = material.Ka * sunColor.rgb * 0.5;
//
//    // Calculate the diffuse reflection
//    vec3 sunDirectionWorld = normalize(vec3(worldMatrix * sunDirection));
//    float diffuseReflection = max(0.0, dot(world_nrm, sunDirectionWorld));
//
//    // Calculate the specular reflection
//    vec3 viewDirection = normalize(cameraPos.xyz - worldPos);
//    vec3 reflectDirection = reflect(-sunDirectionWorld, world_nrm);
//    float specularReflection = pow(max(0.0, dot(viewDirection, reflectDirection)), material.Ns);
//	vec3 totalDirect = vec3(0);
//	for (int i = 0; i < 2; i++) 
//	{
//		vec3 lightDir = normalize(lightsPos[i].xyz - worldPos);
//		float diffuse = max(0.0, dot(world_nrm, lightDir));
//		float distance = length(lightsPos[i].xyz - worldPos);
//		float attenuation = 1.0 / (1.0 + 0.1 * distance + 0.01 * distance * distance);
//		totalDirect += lightCol[i].xyz * diffuse * attenuation;
//	}
//
//	vec3 lightDir = normalize(sunDirection.xyz - worldPos);
//	float diffuse = max(0.0, dot(world_nrm, lightDir));
//
//    // Combine the colors and reflections to get the final pixel color
//	vec3 finalColor = clamp(totalDirect + ambientColor,0, 1) * material.Kd + specularReflection + diffuseReflection + material.Ke ;
//	Pixel = vec4(finalColor,material.d);
//    
}