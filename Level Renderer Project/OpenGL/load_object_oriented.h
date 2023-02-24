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

GLuint vertexArray = 0;
GLuint vertexBufferObject = 0;
GLuint indexBufferObject = 0;
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


class Model {
	// Loads and stores CPU model data from .h2b file
	H2B::Parser cpuModel; // reads the .h2b format
	// Shader variables needed by this model. 
	GW::MATH::GMATRIXF world;// TODO: Add matrix/light/etc vars..
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
		for (size_t i = 0; i < lightCount; i++)
		{
			shaderInformation.lightCol[i] = lightCol[i];
			shaderInformation.lightsPos[i] = lightsPos[i];
		}
		shaderInformation.view_perspective = viewPerspective;
		glGenVertexArrays(1, &vertexArray);
		glBindVertexArray(vertexArray);
		glGenBuffers(1, &vertexBufferObject);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);////////

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(H2B::VERTEX), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(H2B::VERTEX), (void*)12);
		glEnableVertexAttribArray(1);

		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(H2B::VERTEX), (void*)24);
		glEnableVertexAttribArray(2);

		glGenBuffers(1, &indexBufferObject);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject);
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

		//UBO Binding
		glGenBuffers(1, &UBO);
		glBindBuffer(GL_UNIFORM_BUFFER, UBO);
		glBufferData(GL_UNIFORM_BUFFER, sizeof(UBO_DATA), &shaderInformation, GL_DYNAMIC_DRAW);

		uniformBlockIndex = glGetUniformBlockIndex(shaderExecutable, "UBO_DATA");
		glBindBufferBase(GL_UNIFORM_BUFFER, uniformBlockIndex, UBO);

		shaderInformation.sunColor = sunColorG;
		shaderInformation.sunDirection = sunPositionG;

		glUseProgram(shaderExecutable);
		glBindVertexArray(vertexArray);
		glUniformBlockBinding(shaderExecutable, uniformBlockIndex, 0);

		// TODO: Use chosen API to setup the pipeline for this model and draw it


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


		GLvoid* p;


		//SKYBOX

		shaderInformation.material.illum = 1000;
		glBufferData(GL_ARRAY_BUFFER, sizeof(H2B::VERTEX) * 8, cubeVerts, GL_STATIC_DRAW);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 36, cubeIndexes, GL_STATIC_DRAW);
		mProxy.IdentityF(shaderInformation.worldMatrix);
		shaderInformation.worldMatrix.row4 = camPos.row4;
		glBindTexture(GL_TEXTURE_CUBE_MAP, skybox);
		p = glMapBuffer(GL_UNIFORM_BUFFER, GL_WRITE_ONLY);
		memcpy(p, &shaderInformation, sizeof(shaderInformation));
		glUnmapBuffer(GL_UNIFORM_BUFFER);

		glDepthMask(GL_FALSE);
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, (void*)0);
		glDepthMask(GL_TRUE);

		glBufferData(GL_ARRAY_BUFFER, sizeof(H2B::VERTEX) * cpuModel.vertices.size(), cpuModel.vertices.data(), GL_STATIC_DRAW);//LINE
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * cpuModel.indexCount, cpuModel.indices.data(), GL_STATIC_DRAW);

		for (size_t i = 0; i < cpuModel.meshCount; i++)
		{
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
		glDeleteBuffers(1, &vertexBufferObject);
		glDeleteVertexArrays(1, &vertexArray);
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
#ifndef NDEBUG
		glDebugMessageCallback(MessageCallback, nullptr);
#endif
		view[0] = GW::MATH::GIdentityMatrixF; view[1] = GW::MATH::GIdentityMatrixF; perspective = GW::MATH::GIdentityMatrixF;

		mProxy.LookAtLHF(GW::MATH::GVECTORF({ -25.75f, 4.25f, 1.5f }), GW::MATH::GVECTORF({ 0.15f, 0.75f, 0 }), GW::MATH::GVECTORF({ 0.0f, 1.0f, 0.0f }), view[0]);
		mProxy.LookAtLHF(GW::MATH::GVECTORF({ -25.75f, 4.25f, 1.5f }), GW::MATH::GVECTORF({ 0.15f, 0.75f, 0 }), GW::MATH::GVECTORF({ 0.0f, 1.0f, 0.0f }), view[1]);

		unsigned int winHeight; unsigned int winWidth;
		if (!win)
			return false;
		win.GetClientHeight(winHeight); win.GetClientWidth(winWidth);
		float aspectRatio;
		aspectRatio = (float)winWidth / (float)winHeight;

		mProxy.ProjectionOpenGLLHF(G_DEGREE_TO_RADIAN(65), aspectRatio, 0.1f, 100, perspective);
		mProxy.MultiplyMatrixF(view[0], perspective, viewPerspective);
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

