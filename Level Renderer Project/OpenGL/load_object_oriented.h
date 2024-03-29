// This is a sample of how to load a level in a object oriented fashion.
// Feel free to use this code as a base and tweak it for your needs.

// This reads .h2b files which are optimized binary .obj+.mtl files
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

GLuint texture_object[6] = { 0 };


GW::SYSTEM::GWindow win;
std::string ShaderAsString(const char* shaderFilePath)
{
	std::string output;
	unsigned int stringLength = 0;
	GW::SYSTEM::GFile file; file.Create();
	file.GetFileSize(shaderFilePath, stringLength);
	if (stringLength && +file.OpenBinaryRead(shaderFilePath)) {
		output.resize(stringLength);
		file.Read(&output[0], stringLength);
	}
	else
		std::cout << "ERROR: Shader Source File \"" << shaderFilePath << "\" Not Found!" << std::endl;
	return output;
}
// Simple Vertex Shader
std::string vertShaderStr = ShaderAsString("../VertShader.glsl");
const char* vertexShaderSource = vertShaderStr.c_str();

// Simple Fragment Shader
std::string fragmentShaderStr = ShaderAsString("../PxlShader.glsl");
const char* fragmentShaderSource = fragmentShaderStr.c_str();

// Used to print debug infomation from OpenGL, pulled straight from the official OpenGL wiki.
#ifndef NDEBUG
void MessageCallback(GLenum source, GLenum type, GLuint id,
	GLenum severity, GLsizei length,
	const GLchar* message, const void* userParam) {
	fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
		(type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""), type, severity, message);
}
#endif


#include "../Gateware/Gateware.h"
#include "../OpenGL/h2bParser.h"
#include "../../Level Renderer Project/OpenGL/Globals.h"

struct UBO_DATA
{
	GW::MATH::GVECTORF sunDirection, sunColor;
	GW::MATH::GVECTORF lightsPos[2];
	GW::MATH::GVECTORF lightCol[2];
	GW::MATH::GMATRIXF view_perspective;
	GW::MATH::GMATRIXF worldMatrix = GW::MATH::GIdentityMatrixF; //Position for the objects in the world
	H2B::ATTRIBUTES material; //LINE TODO
	GW::MATH::GVECTORF cameraPos;
};

GLuint uniformBlockIndex;

GLuint vao = 0;
GLuint vertexHandle = 0;
GLuint ebo = 0;
GLuint UBO = 0;
//SHADERS
GLuint vertexShader = 0;
GLuint fragmentShader = 0;
GLuint shaderExecutable = 0;

unsigned int textureID;
unsigned int skybox;

GW::MATH::GMatrix mProxy;
GW::MATH::GMATRIXF view[2];
GW::MATH::GMATRIXF perspective;
GW::MATH::GMATRIXF viewPerspective;
GW::MATH::GMATRIXF worldPositions[2];

GW::MATH::GVECTORF sunColorG = { 25.0f / 100.0f, 25.0f / 100.0f, 35.0f / 100.0f };
GW::MATH::GVECTORF sunPositionG = { -1,-1,1 };

//Movement Proxy
GW::INPUT::GInput inputProxy;
//Camera Movement globals
float cameraSpeed = 1.3f;
float verSens = 5.3f;
float horSens = 6.5f;
GW::MATH::GVECTORF movement ;
GW::MATH::GVECTORF movementSide = { 0, };
//CameraRotation
float rotationXY[2];
//DELTA TIME GLOBAL
float deltaTime;

//GLOBAL CAMERA AND LIGHTS ARRAY
unsigned int cameraCount = 0;
unsigned int lightCount = 0;
const unsigned int cameraCountLimit = 3;
const unsigned int lightCountLimit = 2;
GW::MATH::GMATRIXF cameras[cameraCountLimit];
GW::MATH::GVECTORF lightsPos[lightCountLimit];
GW::MATH::GVECTORF lightCol[lightCountLimit];

//SKYBOX CUBE
const float cubeSize = 50.0f;
// Define the 8 vertex positions of the cube
H2B::VECTOR positions[8] = {
	{-cubeSize, -cubeSize,  cubeSize},
	{ cubeSize, -cubeSize,  cubeSize},
	{ cubeSize,  cubeSize,  cubeSize},
	{-cubeSize,  cubeSize,  cubeSize},
	{-cubeSize, -cubeSize, -cubeSize},
	{ cubeSize, -cubeSize, -cubeSize},
	{ cubeSize,  cubeSize, -cubeSize},
	{-cubeSize,  cubeSize, -cubeSize}
};

// Define the 6 faces of the cube as sets of indices
int cubeIndexes[36] = {
	0, 1, 2, 2, 3, 0, // front face
	1, 5, 6, 6, 2, 1, // right face
	5, 4, 7, 7, 6, 5, // back face
	4, 0, 3, 3, 7, 4, // left face
	3, 2, 6, 6, 7, 3, // top face
	4, 5, 1, 1, 0, 4  // bottom face
};

// Define the 8 vertex positions, texture coordinates, and normals of the cube
H2B::VERTEX cubeVerts[8] = {
	{{positions[0]}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}}, // front bottom left
	{{positions[1]}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}}, // front bottom right
	{{positions[2]}, {1.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}}, // front top right
	{{positions[3]}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}}, // front top left
	{{positions[4]}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, -1.0f}}, // back bottom left
	{{positions[5]}, {1.0f, 0.0f, 1.0f}, {0.0f, 0.0f, -1.0f}}, // back bottom right
	{{positions[6]}, {1.0f, 1.0f, 1.0f}, {0.0f, 0.0f, -1.0f}}, // back top right
	{{positions[7]}, {0.0f, 1.0f, 1.0f}, {0.0f, 0.0f, -1.0f}}  // back top left
};
void UpdateCamera(GW::MATH::GMATRIXF view)
{
	static auto previousTime = std::chrono::high_resolution_clock::now();
	auto currentTime = std::chrono::high_resolution_clock::now();
	deltaTime = std::chrono::duration<float>(currentTime - previousTime).count();
	previousTime = currentTime;

	float upInput, upKeyboard, upController = 0;
	inputProxy.GetState(G_KEY_SPACE, upKeyboard);
	//up controller
	upInput = upKeyboard + upController;

	float downInput, downKeyboard, downController = 0;
	inputProxy.GetState(G_KEY_LEFTSHIFT, downKeyboard);
	//down controller
	downInput = downKeyboard + downController;

	float leftInput, leftKeyboard, leftController = 0;
	inputProxy.GetState(G_KEY_A, leftKeyboard);
	//left controller
	leftInput = leftKeyboard + leftController;

	float rightInput, rightKeyboard, rightController = 0;
	inputProxy.GetState(G_KEY_D, rightKeyboard);
	//right controller
	rightInput = rightKeyboard + rightController;

	float forwardInput, forwardKeyboard, forwardController = 0;
	inputProxy.GetState(G_KEY_W, forwardKeyboard);
	//forward controller
	forwardInput = forwardKeyboard + forwardController;

	float backwardInput, backwardKeyboard, backwardController = 0;
	inputProxy.GetState(G_KEY_S, backwardKeyboard);
	//backward controller
	backwardInput = backwardKeyboard + backwardController;


	float verticalChange = upInput - downInput;
	float horizontalChange = rightInput - leftInput;
	float forwardChange = forwardInput - backwardInput;

	movement.y -= verticalChange * cameraSpeed * deltaTime;
	movementSide.x -= horizontalChange * cameraSpeed * deltaTime;
	movementSide.z -= forwardChange * cameraSpeed * deltaTime;


	float mouseXDelta, mouseYDelta;
	mouseXDelta = 0;
	mouseYDelta = 0;
	GW::GReturn redundant = inputProxy.GetMouseDelta(mouseXDelta, mouseYDelta); // Get mouse Y delta
	float rightStickYState = 0; // ...; // Get right stick Y state   BUTONN ID 19

	float thumbSpeed = 3.1415f * deltaTime;
	unsigned int winHeight; unsigned int winWidth;
	win.GetClientHeight(winHeight); win.GetClientWidth(winWidth);
	if (redundant != GW::GReturn::REDUNDANT)
	{
		float totalPitchX = G_DEGREE_TO_RADIAN(65) * mouseYDelta / winHeight + rightStickYState * -thumbSpeed;
		rotationXY[1] += totalPitchX * horSens;
		float totalPitchY = G_DEGREE_TO_RADIAN(65) * mouseXDelta / winWidth + rightStickYState * -thumbSpeed;
		//std::cout << mouseXDelta << "    " << mouseYDelta << "\n";
		rotationXY[0] += totalPitchY * verSens;
	}

	float keyP, keyO, KeyK;
	inputProxy.GetState(G_KEY_P, keyP);
	inputProxy.GetState(G_KEY_O, keyO);
	inputProxy.GetState(G_KEY_K, KeyK);
	if (keyP == 1)
		cameraSpeed += 0.02f;
	if (keyO == 1 && cameraSpeed > 0.04f)
		cameraSpeed -= 0.02f;
	if (KeyK == 1)
		sunPositionG = view.row4;
}
float cameraRadius = 0.05;
struct BoundingBox {
	H2B::VECTOR minPoint, maxPoint;
};
float Clamp(float value, float min, float max) {
	if (value < min) {
		return min;
	}
	else if (value > max) {
		return max;
	}
	else {
		return value;
	}
}
float Distance(H2B::VECTOR a, H2B::VECTOR b) {
	float dx = b.x - a.x;
	float dy = b.y - a.y;
	float dz = b.z - a.z;
	return sqrt(dx * dx + dy * dy + dz * dz);
}
float Length(H2B::VECTOR v) {
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}
H2B::VECTOR SubtractVectors(H2B::VECTOR a, H2B::VECTOR b) {
	H2B::VECTOR result;
	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	return result;
}
H2B::VECTOR Normalize(H2B::VECTOR v) {
	float length = Length(v);
	H2B::VECTOR result;
	result.x = v.x / length;
	result.y = v.y / length;
	result.z = v.z / length;
	return result;
}
H2B::VECTOR MultiplyVectorByScalar(H2B::VECTOR v, float s) {
	return { v.x * s, v.y * s, v.z * s };
}
H2B::VECTOR AddVectors(H2B::VECTOR v1, H2B::VECTOR v2) {
	return { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z };
}




class Model {
	// Loads and stores CPU model data from .h2b file
	H2B::Parser cpuModel; // reads the .h2b format
	// Shader variables needed by this model. 
	GW::MATH::GMATRIXF world;// TODO: Add matrix/light/etc vars..
	BoundingBox* collisions;
	// TODO: API Rendering vars here (unique to this model)
	// Vertex Buffer
	// Index Buffer
	// Pipeline/State Objects
	// Uniform/ShaderVariable Buffer
	UBO_DATA shaderInformation;
	// Vertex/Pixel Shaders
	
public:
	bool isCamera = false;
	bool isLight = false;
	inline void SetWorldMatrix(GW::MATH::GMATRIXF worldMatrix) {
		world = worldMatrix;
	}

	bool LoadModelDataFromDisk(const char* h2bPath) {
		// if this succeeds "cpuModel" should now contain all the model's info
		return cpuModel.Parse(h2bPath);
	}
	bool UploadModelData2GPU(/*specific API device for loading*/) {

		//UBO Binding
		glGenBuffers(1, &UBO);
		glBindBuffer(GL_UNIFORM_BUFFER, UBO);
		glBufferData(GL_UNIFORM_BUFFER, sizeof(UBO_DATA), &shaderInformation, GL_DYNAMIC_DRAW);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);
		//LIGHTS
		for (size_t i = 0; i < lightCount; i++)
		{
			shaderInformation.lightCol[i] = lightCol[i];
			shaderInformation.lightsPos[i] = lightsPos[i];
		}
		//COLLISIONS
		collisions = new BoundingBox[cpuModel.materialCount];
		H2B::VECTOR minPoint = cpuModel.vertices[0].pos;
		H2B::VECTOR maxPoint = cpuModel.vertices[0].pos;
		for (size_t i = 0; i < cpuModel.meshCount; i++)
		{
			for (int j = 0; j < cpuModel.batches[i].indexCount; j++) {
				H2B::VERTEX vertex = cpuModel.vertices[cpuModel.indices[j]];
				if (vertex.pos.x < minPoint.x) minPoint.x = vertex.pos.x;
				if (vertex.pos.y < minPoint.y) minPoint.y = vertex.pos.y;
				if (vertex.pos.z < minPoint.z) minPoint.z = vertex.pos.z;
				if (vertex.pos.x > maxPoint.x) maxPoint.x = vertex.pos.x;
				if (vertex.pos.y > maxPoint.y) maxPoint.y = vertex.pos.y;
				if (vertex.pos.z > maxPoint.z) maxPoint.z = vertex.pos.z;
			}

			collisions[i] = {minPoint, maxPoint};
		}


		shaderInformation.view_perspective = viewPerspective;

		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
		glGenBuffers(1, &vertexHandle);
		glBindBuffer(GL_ARRAY_BUFFER, vertexHandle);////////

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(H2B::VERTEX), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(H2B::VERTEX), (void*)12);
		glEnableVertexAttribArray(1);

		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(H2B::VERTEX), (void*)24);
		glEnableVertexAttribArray(2);

		glGenBuffers(1, &ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

		// Enable the attribute
		glEnableVertexAttribArray(0);
		// Bind the VBO to the VAO
		glBindBuffer(GL_ARRAY_BUFFER, vertexHandle);

		//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * cpuModel.indexCount, cpuModel.indices.data(), GL_STATIC_DRAW);//LINE
		
		// TODO: Use chosen API to upload this model's graphics data to GPU
		return true;
	}
	bool DrawModel(GW::MATH::GMATRIXF& view, bool canMove/*specific API command list or context*/) {
		if (GetAsyncKeyState(0x31) & 0x8000)//key 1
		{
		}
		else if (GetAsyncKeyState(0x32) & 0x8000)//key 2
		{
		}
		else if (GetAsyncKeyState(0x33) & 0x8000)//key 3
		{

		}
		GW::MATH::GMATRIXF camPos;
		mProxy.InverseF(view, camPos);
		shaderInformation.cameraPos = camPos.row4;

		uniformBlockIndex = glGetUniformBlockIndex(shaderExecutable, "UBO_DATA");
		glBindBufferBase(GL_UNIFORM_BUFFER, uniformBlockIndex, UBO);

		shaderInformation.sunColor = sunColorG;
		shaderInformation.sunDirection = sunPositionG;

		glUseProgram(shaderExecutable);
		glBindVertexArray(vao);
		glUniformBlockBinding(shaderExecutable, uniformBlockIndex, 0);

		// TODO: Use chosen API to setup the pipeline for this model and draw it

		

		// Check if the camera is colliding with the object's bounding box
		//Using 0.1 because is the camera near plane

		//CameraMovement
		if (canMove)
		{

			UpdateCamera(view);
			mProxy.TranslateLocalF(view, movement, view);
			mProxy.TranslateGlobalF(view, movementSide, view);
			mProxy.InverseF(view, view);
			mProxy.RotateXLocalF(view, rotationXY[1], view);
			mProxy.RotateYGlobalF(view, rotationXY[0], view);
			mProxy.InverseF(view, view);
			mProxy.MultiplyMatrixF(view, perspective, shaderInformation.view_perspective);
			movement = { 0,0,0 }; movementSide = { 0,0,0 };
			rotationXY[0] = 0; rotationXY[1] = 0;
		}
		else
		{
			mProxy.InverseF(view, view);
			view.row4.z += 0.005f;
			mProxy.InverseF(view, view);
		}
		


		GLvoid* p;


		//SKYBOX

		shaderInformation.material.illum = 1000;
		glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVerts), cubeVerts, GL_STATIC_DRAW);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cubeIndexes), cubeIndexes, GL_STATIC_DRAW);
		mProxy.IdentityF(shaderInformation.worldMatrix);
		shaderInformation.worldMatrix.row4 = camPos.row4;
		//glBindTexture(GL_TEXTURE_CUBE_MAP, skybox);
		p = glMapBuffer(GL_UNIFORM_BUFFER, GL_WRITE_ONLY);
		memcpy(p, &shaderInformation, sizeof(shaderInformation));
		glUnmapBuffer(GL_UNIFORM_BUFFER);

		glDepthMask(GL_FALSE);
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, (void*)0);
		glDepthMask(GL_TRUE);

		glBufferData(GL_ARRAY_BUFFER, sizeof(H2B::VERTEX) * cpuModel.vertices.size(), cpuModel.vertices.data(), GL_STATIC_DRAW);//LINE
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * cpuModel.indexCount, cpuModel.indices.data(), GL_STATIC_DRAW);

		H2B::VECTOR prevCameraPos = { camPos.row4.x, camPos.row4.y, camPos.row4.z };
		for (size_t i = 0; i < cpuModel.meshCount; i++)
		{
			if (camPos.row4.x + cameraRadius >= collisions[i].minPoint.x && camPos.row4.x - cameraRadius <= collisions[i].maxPoint.x &&
				camPos.row4.y + cameraRadius >= collisions[i].minPoint.y && camPos.row4.y - cameraRadius <= collisions[i].maxPoint.y &&
				camPos.row4.z + cameraRadius >= collisions[i].minPoint.z && camPos.row4.z - cameraRadius <= collisions[i].maxPoint.z) {
				// Camera is inside the object, move it to the nearest point on the surface
				H2B::VECTOR closestPoint = {
				Clamp(camPos.row4.x, collisions[i].minPoint.x, collisions[i].maxPoint.x),
				Clamp(camPos.row4.y, collisions[i].minPoint.y, collisions[i].maxPoint.y),
				Clamp(camPos.row4.z, collisions[i].minPoint.z, collisions[i].maxPoint.z)
				};
				float distance = Distance({ camPos.row4.x, camPos.row4.y, camPos.row4.z }, closestPoint);
				if (distance < cameraRadius) {
					H2B::VECTOR displacement = SubtractVectors({ camPos.row4.x, camPos.row4.y, camPos.row4.z }, closestPoint);
					if (displacement.x != 0 || displacement.y != 0 || displacement.z != 0)
					{
						H2B::VECTOR normal = Normalize(displacement);
						float distance = Distance({ camPos.row4.x, camPos.row4.y, camPos.row4.z }, closestPoint);
						float cameraRadius = 2.0f;
					
						H2B::VECTOR newPos = MultiplyVectorByScalar(normal, -0.1); //0.4 is the backup distance the camera will move back
						//mProxy.InverseF(view, view);
						mProxy.TranslateGlobalF(view, GW::MATH::GVECTORF{ newPos.x, newPos.y, newPos.z }, view);
						//mProxy.InverseF(view, view);
					}
				}
			}
			shaderInformation.material = cpuModel.materials[cpuModel.meshes[i].materialIndex].attrib;
			shaderInformation.worldMatrix = world;
			p = glMapBuffer(GL_UNIFORM_BUFFER, GL_WRITE_ONLY);
			memcpy(p, &shaderInformation, sizeof(shaderInformation));
			glUnmapBuffer(GL_UNIFORM_BUFFER);
			int offset = cpuModel.batches[i].indexOffset * sizeof(float);
			glDrawElements(GL_TRIANGLES, cpuModel.batches[i].indexCount, GL_UNSIGNED_INT, (void*)offset);
		}


		
		return true;
	}
	bool FreeResources(/*specific API device for unloading*/) {
		// TODO: Use chosen API to free all GPU resources used by this model

		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glBindTexture(GL_TEXTURE_2D, 0);
		glDeleteBuffers(1, &vertexHandle);
		glDeleteVertexArrays(1, &vao);
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
		glDeleteProgram(shaderExecutable);
		glDeleteBuffers(1, &UBO);
		return true;
	}
};


class Level_Objects {
	// store all our models
	std::list<Model> allObjectsInLevel;
	// TODO: This could be a good spot for any global data like cameras or lights

public:
	std::vector<std::string> faces
	{
			"../../Textures/right.jpg",
			"../../Textures/left.jpg",
			"../../Textures/top.jpg",
			"../../Textures/bottom.jpg",
			"../../Textures/front.jpg",
			"../../Textures/back.jpg"
	};
	unsigned int loadCubemap(std::vector<std::string> faces)
	{
		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

		int width, height, nrChannels;
		for (unsigned int i = 0; i < faces.size(); i++)
		{
			unsigned char* data = stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);
			if (data)
			{
				glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
					0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data
				);
				stbi_image_free(data);
			}
			else
			{
				std::cout << "Cubemap tex failed to load at path: " << faces[i] << std::endl;
				stbi_image_free(data);
			}
		}
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

		return textureID;
	}
	// Imports the default level txt format and creates a Model from each .h2b
	bool LoadLevel(	const char* gameLevelPath,
					const char* h2bFolderPath,
					GW::SYSTEM::GLog log,
					GW::SYSTEM::GWindow _win) {
		win = _win;
		inputProxy.Create(win);
		mProxy.Create();
		mProxy.IdentityF(worldPositions[0]);
		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_TEXTURE_2D);
#ifndef NDEBUG
		glDebugMessageCallback(MessageCallback, nullptr);
#endif
		view[0] = GW::MATH::GIdentityMatrixF; view[1] = GW::MATH::GIdentityMatrixF; perspective = GW::MATH::GIdentityMatrixF;
		view[1].row4.z = -4;

		//mProxy.LookAtLHF(GW::MATH::GVECTORF({ -25.75f, 4.25f, 1.5f }), GW::MATH::GVECTORF({ 0.15f, 0.75f, 0 }), GW::MATH::GVECTORF({ 0.0f, 1.0f, 0.0f }), view[0]);
		//mProxy.LookAtLHF(GW::MATH::GVECTORF({ -25.75f, 4.25f, 1.5f }), GW::MATH::GVECTORF({ 0.15f, 0.75f, 0 }), GW::MATH::GVECTORF({ 0.0f, 1.0f, 0.0f }), view[1]);

		//glMatrixMode(GL_PROJECTION);
		//glLoadIdentity();
		//glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0); // set up an orthographic projection matrix
		//glMatrixMode(GL_MODELVIEW);
		float left = -1.0f;
		float right = 1.0f;
		float bottom = -1.0f;
		float top = 1.0f;
		float znear = 0.1f;
		float zfar = 100.0f;
		GW::MATH::GMATRIXF orthographicProjection
		({  2 / (right - left),		   		      0,				   0, 0 - (right + left) / (right - left),
			0				  ,	 2 / (top - bottom),				   0, 0 - (top + bottom) / (top - bottom),
			0				  ,					  0, -2 / (zfar - znear), 0 - (zfar + znear) / (zfar - znear),
			0				  ,					  0,				   0,					1 });



		unsigned int winHeight; unsigned int winWidth;
		if (!win)
			return false;
		win.GetClientHeight(winHeight); win.GetClientWidth(winWidth);
		float aspectRatio;
		aspectRatio = ((float)winWidth/2) / (float)winHeight;

		//mProxy.ProjectionOpenGLLHF(G_DEGREE_TO_RADIAN(65), aspectRatio, 0.1f, 100, perspective);
		perspective = orthographicProjection;
		
		mProxy.MultiplyMatrixF(view[1], perspective, viewPerspective);

		skybox = loadCubemap(faces);

		//LoadTexture("../../Textures/right.jpg",0);
		//LoadTexture("../../Textures/StoneTexture.jpg",1);


		//SHADERS
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);
		char errors[1024]; GLint result;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &result);
		if (result == false)
		{
			glGetShaderInfoLog(vertexShader, 1024, NULL, errors);
			std::cout << errors << std::endl;
		}
		// Create Fragment Shader
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);


		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &result);
		if (result == false)
		{
			glGetShaderInfoLog(fragmentShader, 1024, NULL, errors);
			std::cout << errors << std::endl;
		}
		// Create Executable Shader Program
		shaderExecutable = glCreateProgram();
		glAttachShader(shaderExecutable, vertexShader);
		glAttachShader(shaderExecutable, fragmentShader);
		glLinkProgram(shaderExecutable);
		glGetProgramiv(shaderExecutable, GL_LINK_STATUS, &result);
		if (result == false)
		{
			glGetProgramInfoLog(shaderExecutable, 1024, NULL, errors);
			std::cout << errors << std::endl;
		}

		// What this does:
		// Parse GameLevel.txt 
		// For each model found in the file...
			// Create a new Model class on the stack.
				// Read matrix transform and add to this model.
				// Load all CPU rendering data for this model from .h2b
			// Add the newly found Model to our list of total models for the level 

		log.LogCategorized("EVENT", "LOADING GAME LEVEL [OBJECT ORIENTED]");
		log.LogCategorized("MESSAGE", "Begin Reading Game Level Text File.");



		UnloadLevel();// clear previous level data if there is any
		GW::SYSTEM::GFile file;
		file.Create();
		if (-file.OpenTextRead(gameLevelPath)) {
			log.LogCategorized(
				"ERROR", (std::string("Game level not found: ") + gameLevelPath).c_str());
			return false;
		}
		char linebuffer[1024];
		while (+file.ReadLine(linebuffer, 1024, '\n'))
		{
			// having to have this is a bug, need to have Read/ReadLine return failure at EOF
			if (linebuffer[0] == '\0')
				break;
			if (std::strcmp(linebuffer, "MESH") == 0)
			{
				file.ReadLine(linebuffer, 1024, '\n');
				log.LogCategorized("INFO", (std::string("Model Detected: ") + linebuffer).c_str());
				// create the model file name from this (strip the .001)
				std::string modelFile = linebuffer;
				modelFile = modelFile.substr(0, modelFile.find_last_of("."));
				modelFile += ".h2b";

				// now read the transform data as we will need that regardless
				GW::MATH::GMATRIXF transform;
				for (int i = 0; i < 4; ++i) {
					file.ReadLine(linebuffer, 1024, '\n');
					// read floats
					std::sscanf(linebuffer + 13, "%f, %f, %f, %f",
						&transform.data[0 + i * 4], &transform.data[1 + i * 4],
						&transform.data[2 + i * 4], &transform.data[3 + i * 4]);
				}
				std::string loc = "Location: X ";
				loc += std::to_string(transform.row4.x) + " Y " +
					std::to_string(transform.row4.y) + " Z " + std::to_string(transform.row4.z);
				log.LogCategorized("INFO", loc.c_str());

				// Add new model to list of all Models
				log.LogCategorized("MESSAGE", "Begin Importing .H2B File Data.");
				Model newModel;
				modelFile = std::string(h2bFolderPath) + "/" + modelFile;
				newModel.SetWorldMatrix(transform);
				// If we find and load it add it to the level
				if (newModel.LoadModelDataFromDisk(modelFile.c_str())) {
					// add to our level objects
					newModel.UploadModelData2GPU();
					
					allObjectsInLevel.push_back(newModel);
					log.LogCategorized("INFO", (std::string("H2B Imported: ") + modelFile).c_str());
				}
				else {
					// notify user that a model file is missing but continue loading
					log.LogCategorized("ERROR",
						(std::string("H2B Not Found: ") + modelFile).c_str());
					log.LogCategorized("WARNING", "Loading will continue but model(s) are missing.");
				}
				log.LogCategorized("MESSAGE", "Importing of .H2B File Data Complete.");
			}
			else if (std::strcmp(linebuffer, "LIGHT") == 0 && lightCount < lightCountLimit)
			{
				file.ReadLine(linebuffer, 1024, '\n');
				log.LogCategorized("INFO", (std::string("Model Detected: ") + linebuffer).c_str());
				// create the model file name from this (strip the .001)
				std::string modelFile = linebuffer;
				modelFile = modelFile.substr(0, modelFile.find_last_of("."));
				modelFile += ".h2b";

				// now read the transform data as we will need that regardless
				GW::MATH::GMATRIXF transform;
				for (int i = 0; i < 4; ++i) {
					file.ReadLine(linebuffer, 1024, '\n');
					// read floats
					std::sscanf(linebuffer + 13, "%f, %f, %f, %f",
						&transform.data[0 + i * 4], &transform.data[1 + i * 4],
						&transform.data[2 + i * 4], &transform.data[3 + i * 4]);
				}
				std::string loc = "Location: X ";
				loc += std::to_string(transform.row4.x) + " Y " +
					std::to_string(transform.row4.y) + " Z " + std::to_string(transform.row4.z);
				log.LogCategorized("INFO", loc.c_str());

				// Add new model to list of all Models
				log.LogCategorized("MESSAGE", "Begin Importing .H2B File Data.");

				lightCol[lightCount] = { 0.1,0.8,0.1 };
				lightsPos[lightCount] = transform.row4;
				lightCount++;
				// If we find and load it add it to the level
				log.LogCategorized("MESSAGE", "Importing of .H2B File Data Complete. Light created");
			}
			else if (std::strcmp(linebuffer, "CAMERA") == 0 && cameraCount < cameraCountLimit)
			{
				file.ReadLine(linebuffer, 1024, '\n');
				log.LogCategorized("INFO", (std::string("Model Detected: ") + linebuffer).c_str());
				// create the model file name from this (strip the .001)
				std::string modelFile = linebuffer;
				modelFile = modelFile.substr(0, modelFile.find_last_of("."));
				modelFile += ".h2b";

				// now read the transform data as we will need that regardless
				GW::MATH::GMATRIXF transform;
				for (int i = 0; i < 4; ++i) {
					file.ReadLine(linebuffer, 1024, '\n');
					// read floats
					std::sscanf(linebuffer + 13, "%f, %f, %f, %f",
						&transform.data[0 + i * 4], &transform.data[1 + i * 4],
						&transform.data[2 + i * 4], &transform.data[3 + i * 4]);
				}
				std::string loc = "Location: X ";
				loc += std::to_string(transform.row4.x) + " Y " +
					std::to_string(transform.row4.y) + " Z " + std::to_string(transform.row4.z);
				log.LogCategorized("INFO", loc.c_str());

				// Add new model to list of all Models
				log.LogCategorized("MESSAGE", "Begin Importing .H2B File Data.");
				cameras[cameraCount] = transform;
				cameraCount++;
				// If we find and load it add it to the level
				log.LogCategorized("MESSAGE", "Importing of .H2B File Data Complete.");
			}
		}
		log.LogCategorized("MESSAGE", "Game Level File Reading Complete.");
		// level loaded into CPU ram
		log.LogCategorized("EVENT", "GAME LEVEL WAS LOADED TO CPU [OBJECT ORIENTED]");

		mProxy.InverseF(cameras[1], cameras[1]);
		return true;
	}
	// Draws all objects in the level
	void RenderLevel() {
		// iterate over each model and tell it to draw itself
		glViewport(0, 0, 600, 600);
		for (auto e : allObjectsInLevel) 
		{
			//e.UploadModelData2GPU();
			e.DrawModel(cameras[1], true/*pass any needed global info.(ex:camera)*/);
		}
		glViewport(600,0, 600, 600);
		for (auto e : allObjectsInLevel)
		{
			//e.UploadModelData2GPU();
			e.DrawModel(cameras[0], false/*pass any needed global info.(ex:camera)*/);
		}
		//renderer.Render();
	}
	// used to wipe CPU & GPU level data between levels
	void UnloadLevel() {
		lightCount = 0;
		cameraCount = 0;
		allObjectsInLevel.clear(); 
		for (auto e : allObjectsInLevel) 
		{
			e.FreeResources();
		}
	}
	// *THIS APPROACH COMBINES DATA & LOGIC* 
	// *WITH THIS APPROACH THE CURRENT RENDERER SHOULD BE JUST AN API MANAGER CLASS*
	// *ALL ACTUAL GPU LOADING AND RENDERING SHOULD BE HANDLED BY THE MODEL CLASS* 
	// For example: anything that is not a global API object should be encapsulated.
};

