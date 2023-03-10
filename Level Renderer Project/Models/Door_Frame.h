// "Door_Frame.h" generated by "Obj2Header.exe" [Version 1.9d] Author: L.Norri Fullsail University.
// Data is converted to left-handed coordinate system and UV data is V flipped for Direct3D/Vulkan.
// The companion file "Door_Frame.h2b" is a binary dump of this format(-padding) for more flexibility.
// Loading *.h2b: read version, sizes, handle strings(max len 260) by reading until null-terminated.
/***********************/
/*  Generator version  */
/***********************/
#ifndef _Door_Frame_version_
const char Door_Frame_version[4] = { '0','1','9','d' };
#define _Door_Frame_version_
#endif
/************************************************/
/*  This section contains the model's size data */
/************************************************/
#ifndef _Door_Frame_vertexcount_
const unsigned Door_Frame_vertexcount = 194;
#define _Door_Frame_vertexcount_
#endif
#ifndef _Door_Frame_indexcount_
const unsigned Door_Frame_indexcount = 348;
#define _Door_Frame_indexcount_
#endif
#ifndef _Door_Frame_materialcount_
const unsigned Door_Frame_materialcount = 1; // can be used for batched draws
#define _Door_Frame_materialcount_
#endif
#ifndef _Door_Frame_meshcount_
const unsigned Door_Frame_meshcount = 1;
#define _Door_Frame_meshcount_
#endif
/************************************************/
/*  This section contains the raw data to load  */
/************************************************/
#ifndef __OBJ_VEC3__
typedef struct _OBJ_VEC3_
{
	float x,y,z; // 3D Coordinate.
}OBJ_VEC3;
#define __OBJ_VEC3__
#endif
#ifndef __OBJ_VERT__
typedef struct _OBJ_VERT_
{
	OBJ_VEC3 pos; // Left-handed +Z forward coordinate w not provided, assumed to be 1.
	OBJ_VEC3 uvw; // D3D/Vulkan style top left 0,0 coordinate.
	OBJ_VEC3 nrm; // Provided direct from obj file, may or may not be normalized.
}OBJ_VERT;
#define __OBJ_VERT__
#endif
#ifndef _Door_Frame_vertices_
// Raw Vertex Data follows: Positions, Texture Coordinates and Normals.
const OBJ_VERT Door_Frame_vertices[194] =
{
	{	{ -22.131023f, 8.144205f, 0.832501f },	{ 0.553589f, 0.750000f, 0.000000f },	{ 1.000000f, -0.005200f, -0.000000f }	},
	{	{ -22.126398f, 9.025464f, 0.832501f },	{ 0.625000f, 0.750000f, 0.000000f },	{ 1.000000f, -0.005200f, -0.000000f }	},
	{	{ -22.126398f, 9.025464f, 1.377696f },	{ 0.625000f, 1.000000f, 0.000000f },	{ 1.000000f, -0.005200f, -0.000000f }	},
	{	{ -22.131023f, 8.144205f, 1.321483f },	{ 0.553589f, 1.000000f, 0.000000f },	{ 1.000000f, -0.005200f, -0.000000f }	},
	{	{ -22.690472f, 8.144205f, 0.832501f },	{ 0.553589f, 0.500000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -22.690472f, 9.025464f, 0.832501f },	{ 0.625000f, 0.500000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -22.126398f, 9.025464f, 0.832501f },	{ 0.625000f, 0.750000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -22.131023f, 8.144205f, 0.832501f },	{ 0.553589f, 0.750000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -22.690472f, 8.144205f, 1.321483f },	{ 0.553589f, 0.250000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -22.690472f, 9.025464f, 1.377696f },	{ 0.625000f, 0.250000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -22.690472f, 9.025464f, 0.832501f },	{ 0.625000f, 0.500000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -22.690472f, 8.144205f, 0.832501f },	{ 0.553589f, 0.500000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -22.131023f, 8.144205f, 1.321483f },	{ 0.553589f, 0.000000f, 0.000000f },	{ 0.000000f, -0.063700f, 0.998000f }	},
	{	{ -22.126398f, 9.025464f, 1.377696f },	{ 0.625000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.063700f, 0.998000f }	},
	{	{ -22.690472f, 9.025464f, 1.377696f },	{ 0.625000f, 0.250000f, 0.000000f },	{ 0.000000f, -0.063700f, 0.998000f }	},
	{	{ -22.690472f, 8.144205f, 1.321483f },	{ 0.553589f, 0.250000f, 0.000000f },	{ 0.000000f, -0.063700f, 0.998000f }	},
	{	{ -22.112232f, 4.212643f, 1.377696f },	{ 0.125000f, 0.250000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -22.690472f, 4.212643f, 1.377696f },	{ 0.375000f, 0.250000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -22.690472f, 4.212643f, 0.832501f },	{ 0.375000f, 0.500000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -22.112232f, 4.212643f, 0.832501f },	{ 0.125000f, 0.500000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -22.690472f, 9.025464f, 1.377696f },	{ 0.625000f, 0.250000f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -22.126398f, 9.025464f, 1.377696f },	{ 0.875000f, 0.250000f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -22.126398f, 9.025464f, 0.832501f },	{ 0.875000f, 0.500000f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -22.690472f, 9.025464f, 0.832501f },	{ 0.625000f, 0.500000f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -22.158783f, 5.077826f, 1.377696f },	{ 0.429778f, 0.000000f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -22.245285f, 5.496462f, 1.377696f },	{ 0.456283f, 0.000000f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -22.690472f, 5.496462f, 1.377696f },	{ 0.456283f, 0.250000f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -22.690472f, 5.077826f, 1.377696f },	{ 0.429778f, 0.250000f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -22.690472f, 5.077826f, 1.377696f },	{ 0.429778f, 0.250000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -22.690472f, 5.496462f, 1.377696f },	{ 0.456283f, 0.250000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -22.690472f, 5.496462f, 0.832501f },	{ 0.456283f, 0.500000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -22.690472f, 5.077826f, 0.832501f },	{ 0.429778f, 0.500000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -22.690472f, 5.077826f, 0.832501f },	{ 0.429778f, 0.500000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -22.690472f, 5.496462f, 0.832501f },	{ 0.456283f, 0.500000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -22.245285f, 5.496462f, 0.832501f },	{ 0.456283f, 0.750000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -22.158783f, 4.789412f, 0.832501f },	{ 0.429778f, 0.750000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -22.158783f, 4.789412f, 0.832501f },	{ 0.429778f, 0.750000f, 0.000000f },	{ 0.987600f, 0.151800f, -0.040100f }	},
	{	{ -22.245285f, 5.496462f, 0.832501f },	{ 0.456283f, 0.750000f, 0.000000f },	{ 0.987600f, 0.151800f, -0.040100f }	},
	{	{ -22.245285f, 5.496462f, 1.377696f },	{ 0.456283f, 1.000000f, 0.000000f },	{ 0.987600f, 0.151800f, -0.040100f }	},
	{	{ -22.158783f, 5.077826f, 1.377696f },	{ 0.429778f, 1.000000f, 0.000000f },	{ 0.987600f, 0.151800f, -0.040100f }	},
	{	{ -22.112232f, 4.212643f, 0.832501f },	{ 0.375000f, 0.750000f, 0.000000f },	{ 0.997800f, 0.064400f, -0.017000f }	},
	{	{ -22.158783f, 4.789412f, 0.832501f },	{ 0.429778f, 0.750000f, 0.000000f },	{ 0.997800f, 0.064400f, -0.017000f }	},
	{	{ -22.158783f, 5.077826f, 1.377696f },	{ 0.429778f, 1.000000f, 0.000000f },	{ 0.997800f, 0.064400f, -0.017000f }	},
	{	{ -22.112232f, 4.212643f, 1.377696f },	{ 0.375000f, 1.000000f, 0.000000f },	{ 0.997800f, 0.064400f, -0.017000f }	},
	{	{ -22.690472f, 4.212643f, 0.832501f },	{ 0.375000f, 0.500000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -22.112232f, 4.212643f, 0.832501f },	{ 0.375000f, 0.750000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -22.690472f, 4.212643f, 1.377696f },	{ 0.375000f, 0.250000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -22.690472f, 4.212643f, 0.832501f },	{ 0.375000f, 0.500000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -22.112232f, 4.212643f, 1.377696f },	{ 0.375000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -22.690472f, 4.212643f, 1.377696f },	{ 0.375000f, 0.250000f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -22.245285f, 5.496462f, 1.377696f },	{ 0.456283f, 0.000000f, 0.000000f },	{ 0.000000f, 0.040700f, 0.999200f }	},
	{	{ -22.272814f, 6.876383f, 1.321483f },	{ 0.543650f, 0.000000f, 0.000000f },	{ 0.000000f, 0.040700f, 0.999200f }	},
	{	{ -22.728073f, 6.876383f, 1.321483f },	{ 0.543650f, 0.250000f, 0.000000f },	{ 0.000000f, 0.040700f, 0.999200f }	},
	{	{ -22.690472f, 5.496462f, 1.377696f },	{ 0.456283f, 0.250000f, 0.000000f },	{ 0.000000f, 0.040700f, 0.999200f }	},
	{	{ -22.690472f, 5.496462f, 1.377696f },	{ 0.456283f, 0.250000f, 0.000000f },	{ -0.999600f, -0.027200f, -0.000000f }	},
	{	{ -22.728073f, 6.876383f, 1.321483f },	{ 0.543650f, 0.250000f, 0.000000f },	{ -0.999600f, -0.027200f, -0.000000f }	},
	{	{ -22.728073f, 6.876383f, 0.832501f },	{ 0.543650f, 0.500000f, 0.000000f },	{ -0.999600f, -0.027200f, -0.000000f }	},
	{	{ -22.690472f, 5.496462f, 0.832501f },	{ 0.456283f, 0.500000f, 0.000000f },	{ -0.999600f, -0.027200f, -0.000000f }	},
	{	{ -22.728073f, 6.876383f, 0.832501f },	{ 0.543650f, 0.500000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -22.272814f, 6.876383f, 0.832501f },	{ 0.543650f, 0.750000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -22.245285f, 5.496462f, 0.832501f },	{ 0.456283f, 0.750000f, 0.000000f },	{ 0.999800f, 0.019900f, -0.000000f }	},
	{	{ -22.272814f, 6.876383f, 0.832501f },	{ 0.543650f, 0.750000f, 0.000000f },	{ 0.999800f, 0.019900f, -0.000000f }	},
	{	{ -22.272814f, 6.876383f, 1.321483f },	{ 0.543650f, 1.000000f, 0.000000f },	{ 0.999800f, 0.019900f, -0.000000f }	},
	{	{ -22.245285f, 5.496462f, 1.377696f },	{ 0.456283f, 1.000000f, 0.000000f },	{ 0.999800f, 0.019900f, -0.000000f }	},
	{	{ -22.272814f, 6.876383f, 1.321483f },	{ 0.543650f, 0.000000f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -22.131023f, 8.144205f, 1.321483f },	{ 0.553589f, 0.000000f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -22.690472f, 8.144205f, 1.321483f },	{ 0.553589f, 0.250000f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -22.728073f, 6.876383f, 1.321483f },	{ 0.543650f, 0.250000f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -22.728073f, 6.876383f, 1.321483f },	{ 0.543650f, 0.250000f, 0.000000f },	{ -0.999600f, 0.029600f, -0.000000f }	},
	{	{ -22.690472f, 8.144205f, 1.321483f },	{ 0.553589f, 0.250000f, 0.000000f },	{ -0.999600f, 0.029600f, -0.000000f }	},
	{	{ -22.690472f, 8.144205f, 0.832501f },	{ 0.553589f, 0.500000f, 0.000000f },	{ -0.999600f, 0.029600f, -0.000000f }	},
	{	{ -22.728073f, 6.876383f, 0.832501f },	{ 0.543650f, 0.500000f, 0.000000f },	{ -0.999600f, 0.029600f, -0.000000f }	},
	{	{ -22.272814f, 6.876383f, 0.832501f },	{ 0.543650f, 0.750000f, 0.000000f },	{ 0.993800f, -0.111100f, -0.000000f }	},
	{	{ -22.131023f, 8.144205f, 0.832501f },	{ 0.553589f, 0.750000f, 0.000000f },	{ 0.993800f, -0.111100f, -0.000000f }	},
	{	{ -22.131023f, 8.144205f, 1.321483f },	{ 0.553589f, 1.000000f, 0.000000f },	{ 0.993800f, -0.111100f, -0.000000f }	},
	{	{ -22.272814f, 6.876383f, 1.321483f },	{ 0.543650f, 1.000000f, 0.000000f },	{ 0.993800f, -0.111100f, -0.000000f }	},
	{	{ -25.847910f, 7.033361f, 1.377696f },	{ 0.553589f, 0.750000f, 0.000000f },	{ -1.000000f, -0.002300f, -0.000000f }	},
	{	{ -25.852535f, 9.025464f, 1.377696f },	{ 0.625000f, 0.750000f, 0.000000f },	{ -1.000000f, -0.002300f, -0.000000f }	},
	{	{ -25.852535f, 9.025464f, 0.832501f },	{ 0.625000f, 1.000000f, 0.000000f },	{ -1.000000f, -0.002300f, -0.000000f }	},
	{	{ -25.847910f, 7.033361f, 1.016670f },	{ 0.553589f, 1.000000f, 0.000000f },	{ -1.000000f, -0.002300f, -0.000000f }	},
	{	{ -25.288462f, 7.033361f, 1.377696f },	{ 0.553589f, 0.500000f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -25.288462f, 8.978127f, 1.377696f },	{ 0.625000f, 0.500000f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -25.852535f, 9.025464f, 1.377696f },	{ 0.625000f, 0.750000f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -25.847910f, 7.033361f, 1.377696f },	{ 0.553589f, 0.750000f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -25.288462f, 7.033361f, 1.016670f },	{ 0.553589f, 0.250000f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -25.288462f, 8.977856f, 0.832501f },	{ 0.625000f, 0.250000f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -25.288462f, 8.978127f, 1.377696f },	{ 0.625000f, 0.500000f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -25.288462f, 7.033361f, 1.377696f },	{ 0.553589f, 0.500000f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -25.847910f, 7.033361f, 1.016670f },	{ 0.553589f, 0.000000f, 0.000000f },	{ -0.003900f, -0.093200f, -0.995600f }	},
	{	{ -25.852535f, 9.025464f, 0.832501f },	{ 0.625000f, 0.000000f, 0.000000f },	{ -0.003900f, -0.093200f, -0.995600f }	},
	{	{ -25.288462f, 8.977856f, 0.832501f },	{ 0.625000f, 0.250000f, 0.000000f },	{ -0.003900f, -0.093200f, -0.995600f }	},
	{	{ -25.288462f, 7.033361f, 1.016670f },	{ 0.553589f, 0.250000f, 0.000000f },	{ -0.003900f, -0.093200f, -0.995600f }	},
	{	{ -26.017035f, 4.212643f, 0.832501f },	{ 0.125000f, 0.250000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -25.288462f, 4.212643f, 0.832501f },	{ 0.375000f, 0.250000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -25.288462f, 4.212643f, 1.377696f },	{ 0.375000f, 0.500000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -26.017035f, 4.212643f, 1.377696f },	{ 0.125000f, 0.500000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -25.288462f, 8.977856f, 0.832501f },	{ 0.625000f, 0.250000f, 0.000000f },	{ 0.083900f, 0.996500f, -0.000200f }	},
	{	{ -25.852535f, 9.025464f, 0.832501f },	{ 0.875000f, 0.250000f, 0.000000f },	{ 0.083900f, 0.996500f, -0.000200f }	},
	{	{ -25.852535f, 9.025464f, 1.377696f },	{ 0.875000f, 0.500000f, 0.000000f },	{ 0.083900f, 0.996500f, -0.000200f }	},
	{	{ -25.288462f, 8.978127f, 1.377696f },	{ 0.625000f, 0.500000f, 0.000000f },	{ 0.083900f, 0.996500f, -0.000200f }	},
	{	{ -26.017035f, 5.077826f, 0.832501f },	{ 0.429778f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -25.852535f, 5.496462f, 0.832501f },	{ 0.456283f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -25.288462f, 5.496462f, 0.832501f },	{ 0.456283f, 0.250000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -25.288462f, 5.077826f, 0.832501f },	{ 0.429778f, 0.250000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -25.288462f, 5.077826f, 0.832501f },	{ 0.429778f, 0.250000f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -25.288462f, 5.496462f, 0.832501f },	{ 0.456283f, 0.250000f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -25.288462f, 5.496462f, 1.377696f },	{ 0.456283f, 0.500000f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -25.288462f, 5.077826f, 1.377696f },	{ 0.429778f, 0.500000f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -25.288462f, 5.077826f, 1.377696f },	{ 0.429778f, 0.500000f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -25.288462f, 5.496462f, 1.377696f },	{ 0.456283f, 0.500000f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -25.852535f, 5.496462f, 1.377696f },	{ 0.456283f, 0.750000f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -26.017035f, 4.789412f, 1.377696f },	{ 0.429778f, 0.750000f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -26.017035f, 4.789412f, 1.377696f },	{ 0.429778f, 0.750000f, 0.000000f },	{ -0.957200f, 0.279800f, 0.074000f }	},
	{	{ -25.852535f, 5.496462f, 1.377696f },	{ 0.456283f, 0.750000f, 0.000000f },	{ -0.957200f, 0.279800f, 0.074000f }	},
	{	{ -25.852535f, 5.496462f, 0.832501f },	{ 0.456283f, 1.000000f, 0.000000f },	{ -0.957200f, 0.279800f, 0.074000f }	},
	{	{ -26.017035f, 5.077826f, 0.832501f },	{ 0.429778f, 1.000000f, 0.000000f },	{ -0.957200f, 0.279800f, 0.074000f }	},
	{	{ -26.017035f, 4.212643f, 1.377696f },	{ 0.375000f, 0.750000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -26.017035f, 4.789412f, 1.377696f },	{ 0.429778f, 0.750000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -26.017035f, 5.077826f, 0.832501f },	{ 0.429778f, 1.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -26.017035f, 4.212643f, 0.832501f },	{ 0.375000f, 1.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -25.288462f, 4.212643f, 1.377696f },	{ 0.375000f, 0.500000f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -26.017035f, 4.212643f, 1.377696f },	{ 0.375000f, 0.750000f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -25.288462f, 4.212643f, 0.832501f },	{ 0.375000f, 0.250000f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -25.288462f, 4.212643f, 1.377696f },	{ 0.375000f, 0.500000f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -26.017035f, 4.212643f, 0.832501f },	{ 0.375000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -25.288462f, 4.212643f, 0.832501f },	{ 0.375000f, 0.250000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -25.852535f, 5.496462f, 0.832501f },	{ 0.456283f, 0.000000f, 0.000000f },	{ -0.000000f, 0.040700f, -0.999200f }	},
	{	{ -25.847910f, 6.876383f, 0.888714f },	{ 0.543650f, 0.000000f, 0.000000f },	{ -0.000000f, 0.040700f, -0.999200f }	},
	{	{ -25.288462f, 6.876383f, 0.888714f },	{ 0.543650f, 0.250000f, 0.000000f },	{ -0.000000f, 0.040700f, -0.999200f }	},
	{	{ -25.288462f, 5.496462f, 0.832501f },	{ 0.456283f, 0.250000f, 0.000000f },	{ -0.000000f, 0.040700f, -0.999200f }	},
	{	{ -25.288462f, 6.876383f, 0.888714f },	{ 0.543650f, 0.250000f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -25.288462f, 6.876383f, 1.377696f },	{ 0.543650f, 0.500000f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -25.288462f, 6.876383f, 1.377696f },	{ 0.543650f, 0.500000f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -25.847910f, 6.876383f, 1.377696f },	{ 0.543650f, 0.750000f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -25.852535f, 5.496462f, 1.377696f },	{ 0.456283f, 0.750000f, 0.000000f },	{ -1.000000f, 0.003400f, -0.000000f }	},
	{	{ -25.847910f, 6.876383f, 1.377696f },	{ 0.543650f, 0.750000f, 0.000000f },	{ -1.000000f, 0.003400f, -0.000000f }	},
	{	{ -25.847910f, 6.876383f, 0.888714f },	{ 0.543650f, 1.000000f, 0.000000f },	{ -1.000000f, 0.003400f, -0.000000f }	},
	{	{ -25.852535f, 5.496462f, 0.832501f },	{ 0.456283f, 1.000000f, 0.000000f },	{ -1.000000f, 0.003400f, -0.000000f }	},
	{	{ -25.847910f, 6.876383f, 0.888714f },	{ 0.543650f, 0.000000f, 0.000000f },	{ 0.000000f, 0.631800f, -0.775100f }	},
	{	{ -25.847910f, 7.033361f, 1.016670f },	{ 0.553589f, 0.000000f, 0.000000f },	{ 0.000000f, 0.631800f, -0.775100f }	},
	{	{ -25.288462f, 7.033361f, 1.016670f },	{ 0.553589f, 0.250000f, 0.000000f },	{ 0.000000f, 0.631800f, -0.775100f }	},
	{	{ -25.288462f, 6.876383f, 0.888714f },	{ 0.543650f, 0.250000f, 0.000000f },	{ 0.000000f, 0.631800f, -0.775100f }	},
	{	{ -25.847910f, 6.876383f, 1.377696f },	{ 0.543650f, 0.750000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -25.847910f, 7.033361f, 1.377696f },	{ 0.553589f, 0.750000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -25.847910f, 7.033361f, 1.016670f },	{ 0.553589f, 1.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -25.847910f, 6.876383f, 0.888714f },	{ 0.543650f, 1.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -25.305107f, 8.633421f, 1.352409f },	{ 0.375000f, 0.750000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -25.305107f, 8.986868f, 1.352409f },	{ 0.625000f, 0.750000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -25.305107f, 8.986868f, 0.817361f },	{ 0.625000f, 1.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -25.305107f, 8.633421f, 0.817361f },	{ 0.375000f, 1.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -22.685816f, 8.633421f, 1.352409f },	{ 0.375000f, 0.500000f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -22.685816f, 9.027704f, 1.352409f },	{ 0.625000f, 0.500000f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -24.627171f, 8.992962f, 1.352409f },	{ 0.625000f, 0.694736f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -24.726101f, 8.626686f, 1.352409f },	{ 0.375000f, 0.694736f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -22.685816f, 8.633421f, 0.817361f },	{ 0.375000f, 0.250000f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -22.685816f, 9.027704f, 0.817361f },	{ 0.625000f, 0.250000f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -22.685816f, 9.027704f, 1.352409f },	{ 0.625000f, 0.500000f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -22.685816f, 8.633421f, 1.352409f },	{ 0.375000f, 0.500000f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -25.305107f, 8.633421f, 0.817361f },	{ 0.375000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -25.305107f, 8.986868f, 0.817361f },	{ 0.625000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -24.973459f, 8.848845f, 0.817361f },	{ 0.625000f, 0.041097f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -24.874527f, 8.598522f, 0.817361f },	{ 0.375000f, 0.041097f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -24.726101f, 8.626686f, 0.817361f },	{ 0.180264f, 0.250000f, 0.000000f },	{ 0.003300f, -1.000000f, -0.000000f }	},
	{	{ -22.685816f, 8.633421f, 0.817361f },	{ 0.375000f, 0.250000f, 0.000000f },	{ 0.003300f, -1.000000f, -0.000000f }	},
	{	{ -22.685816f, 8.633421f, 1.352409f },	{ 0.375000f, 0.500000f, 0.000000f },	{ 0.003300f, -1.000000f, -0.000000f }	},
	{	{ -24.726101f, 8.626686f, 1.352409f },	{ 0.180264f, 0.500000f, 0.000000f },	{ 0.003300f, -1.000000f, -0.000000f }	},
	{	{ -24.973459f, 8.848845f, 0.817361f },	{ 0.833903f, 0.250000f, 0.000000f },	{ 0.384200f, 0.923200f, -0.000000f }	},
	{	{ -25.305107f, 8.986868f, 0.817361f },	{ 0.875000f, 0.250000f, 0.000000f },	{ 0.384200f, 0.923200f, -0.000000f }	},
	{	{ -25.305107f, 8.986868f, 1.352409f },	{ 0.875000f, 0.500000f, 0.000000f },	{ 0.384200f, 0.923200f, -0.000000f }	},
	{	{ -24.973459f, 8.848845f, 1.352409f },	{ 0.833903f, 0.500000f, 0.000000f },	{ 0.384200f, 0.923200f, -0.000000f }	},
	{	{ -24.627171f, 8.992962f, 0.817361f },	{ 0.819736f, 0.250000f, 0.000000f },	{ -0.384200f, 0.923200f, -0.000000f }	},
	{	{ -24.973459f, 8.848845f, 0.817361f },	{ 0.833903f, 0.250000f, 0.000000f },	{ -0.384200f, 0.923200f, -0.000000f }	},
	{	{ -24.973459f, 8.848845f, 1.352409f },	{ 0.833903f, 0.500000f, 0.000000f },	{ -0.384200f, 0.923200f, -0.000000f }	},
	{	{ -24.627171f, 8.992962f, 1.352409f },	{ 0.819736f, 0.500000f, 0.000000f },	{ -0.384200f, 0.923200f, -0.000000f }	},
	{	{ -25.305107f, 8.633421f, 0.817361f },	{ 0.125000f, 0.250000f, 0.000000f },	{ -0.080800f, -0.996700f, -0.000000f }	},
	{	{ -24.874527f, 8.598522f, 0.817361f },	{ 0.166097f, 0.250000f, 0.000000f },	{ -0.080800f, -0.996700f, -0.000000f }	},
	{	{ -24.874527f, 8.598522f, 1.352409f },	{ 0.166097f, 0.500000f, 0.000000f },	{ -0.080800f, -0.996700f, -0.000000f }	},
	{	{ -25.305107f, 8.633421f, 1.352409f },	{ 0.125000f, 0.500000f, 0.000000f },	{ -0.080800f, -0.996700f, -0.000000f }	},
	{	{ -24.627171f, 8.992962f, 0.817361f },	{ 0.625000f, 0.055264f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -24.726101f, 8.626686f, 0.817361f },	{ 0.375000f, 0.055264f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -24.874527f, 8.598522f, 1.352409f },	{ 0.375000f, 0.708903f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -24.973459f, 8.848845f, 1.352409f },	{ 0.625000f, 0.708903f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -25.305107f, 8.986868f, 1.352409f },	{ 0.625000f, 0.750000f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -25.305107f, 8.633421f, 1.352409f },	{ 0.375000f, 0.750000f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -22.685816f, 9.027704f, 0.817361f },	{ 0.625000f, 0.250000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -22.685816f, 8.633421f, 0.817361f },	{ 0.375000f, 0.250000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -22.685816f, 9.027704f, 0.817361f },	{ 0.625000f, 0.250000f, 0.000000f },	{ -0.017900f, 0.999800f, -0.000000f }	},
	{	{ -24.627171f, 8.992962f, 0.817361f },	{ 0.819736f, 0.250000f, 0.000000f },	{ -0.017900f, 0.999800f, -0.000000f }	},
	{	{ -24.627171f, 8.992962f, 1.352409f },	{ 0.819736f, 0.500000f, 0.000000f },	{ -0.017900f, 0.999800f, -0.000000f }	},
	{	{ -22.685816f, 9.027704f, 1.352409f },	{ 0.625000f, 0.500000f, 0.000000f },	{ -0.017900f, 0.999800f, -0.000000f }	},
	{	{ -24.874527f, 8.598522f, 0.817361f },	{ 0.166097f, 0.250000f, 0.000000f },	{ 0.186400f, -0.982500f, -0.000000f }	},
	{	{ -24.726101f, 8.626686f, 0.817361f },	{ 0.180264f, 0.250000f, 0.000000f },	{ 0.186400f, -0.982500f, -0.000000f }	},
	{	{ -24.726101f, 8.626686f, 1.352409f },	{ 0.180264f, 0.500000f, 0.000000f },	{ 0.186400f, -0.982500f, -0.000000f }	},
	{	{ -24.874527f, 8.598522f, 1.352409f },	{ 0.166097f, 0.500000f, 0.000000f },	{ 0.186400f, -0.982500f, -0.000000f }	},
};
#define _Door_Frame_vertices_
#endif
#ifndef _Door_Frame_indices_
// Index Data follows: Sequential by mesh, Every Three Indices == One Triangle.
const unsigned int Door_Frame_indices[348] =
{
	 0, 1, 2,
	 3, 0, 2,
	 4, 5, 6,
	 7, 4, 6,
	 8, 9, 10,
	 11, 8, 10,
	 12, 13, 14,
	 15, 12, 14,
	 16, 17, 18,
	 19, 16, 18,
	 20, 21, 22,
	 23, 20, 22,
	 24, 25, 26,
	 27, 24, 26,
	 28, 29, 30,
	 31, 28, 30,
	 32, 33, 34,
	 35, 32, 34,
	 36, 37, 38,
	 39, 36, 38,
	 40, 41, 42,
	 43, 40, 42,
	 44, 32, 35,
	 45, 44, 35,
	 46, 28, 31,
	 47, 46, 31,
	 48, 24, 27,
	 49, 48, 27,
	 50, 51, 52,
	 53, 50, 52,
	 54, 55, 56,
	 57, 54, 56,
	 33, 58, 59,
	 34, 33, 59,
	 60, 61, 62,
	 63, 60, 62,
	 64, 65, 66,
	 67, 64, 66,
	 68, 69, 70,
	 71, 68, 70,
	 58, 4, 7,
	 59, 58, 7,
	 72, 73, 74,
	 75, 72, 74,
	 76, 77, 78,
	 79, 76, 78,
	 80, 81, 82,
	 83, 80, 82,
	 84, 85, 86,
	 87, 84, 86,
	 88, 89, 90,
	 91, 88, 90,
	 92, 93, 94,
	 95, 92, 94,
	 96, 97, 98,
	 99, 96, 98,
	 100, 101, 102,
	 103, 100, 102,
	 104, 105, 106,
	 107, 104, 106,
	 108, 109, 110,
	 111, 108, 110,
	 112, 113, 114,
	 115, 112, 114,
	 116, 117, 118,
	 119, 116, 118,
	 120, 108, 111,
	 121, 120, 111,
	 122, 104, 107,
	 123, 122, 107,
	 124, 100, 103,
	 125, 124, 103,
	 126, 127, 128,
	 129, 126, 128,
	 105, 130, 131,
	 106, 105, 131,
	 109, 132, 133,
	 110, 109, 133,
	 134, 135, 136,
	 137, 134, 136,
	 138, 139, 140,
	 141, 138, 140,
	 130, 84, 87,
	 131, 130, 87,
	 132, 80, 83,
	 133, 132, 83,
	 142, 143, 144,
	 145, 142, 144,
	 146, 147, 148,
	 149, 146, 148,
	 150, 151, 152,
	 153, 150, 152,
	 154, 155, 156,
	 157, 154, 156,
	 158, 159, 160,
	 161, 158, 160,
	 162, 163, 164,
	 165, 162, 164,
	 166, 167, 168,
	 169, 166, 168,
	 170, 171, 172,
	 173, 170, 172,
	 174, 175, 176,
	 177, 174, 176,
	 161, 160, 178,
	 179, 161, 178,
	 180, 181, 182,
	 183, 180, 182,
	 179, 178, 184,
	 185, 179, 184,
	 186, 187, 188,
	 189, 186, 188,
	 190, 191, 192,
	 193, 190, 192,
	 153, 152, 181,
	 180, 153, 181,
};
#define _Door_Frame_indices_
#endif
// Part of an OBJ_MATERIAL, the struct is 16 byte aligned so it is GPU register friendly.
#ifndef __OBJ_ATTRIBUTES__
typedef struct _OBJ_ATTRIBUTES_
{
	OBJ_VEC3    Kd; // diffuse reflectivity
	float	    d; // dissolve (transparency) 
	OBJ_VEC3    Ks; // specular reflectivity
	float       Ns; // specular exponent
	OBJ_VEC3    Ka; // ambient reflectivity
	float       sharpness; // local reflection map sharpness
	OBJ_VEC3    Tf; // transmission filter
	float       Ni; // optical density (index of refraction)
	OBJ_VEC3    Ke; // emissive reflectivity
	unsigned    illum; // illumination model
}OBJ_ATTRIBUTES;
#define __OBJ_ATTRIBUTES__
#endif
// This structure also has been made GPU register friendly so it can be transfered directly if desired.
// Note: Total struct size will vary depenedening on CPU processor architecture (string pointers).
#ifndef __OBJ_MATERIAL__
typedef struct _OBJ_MATERIAL_
{
	// The following items are typically used in a pixel/fragment shader, they are packed for GPU registers.
	OBJ_ATTRIBUTES attrib; // Surface shading characteristics & illumination model
	// All items below this line are not needed on the GPU and are generally only used during load time.
	const char* name; // the name of this material
	// If the model's materials contain any specific texture data it will be located below.
	const char* map_Kd; // diffuse texture
	const char* map_Ks; // specular texture
	const char* map_Ka; // ambient texture
	const char* map_Ke; // emissive texture
	const char* map_Ns; // specular exponent texture
	const char* map_d; // transparency texture
	const char* disp; // roughness map (displacement)
	const char* decal; // decal texture (lerps texture & material colors)
	const char* bump; // normal/bumpmap texture
	void* padding[2]; // 16 byte alignment on 32bit or 64bit
}OBJ_MATERIAL;
#define __OBJ_MATERIAL__
#endif
#ifndef _Door_Frame_materials_
// Material Data follows: pulled from a .mtl file of the same name if present.
const OBJ_MATERIAL Door_Frame_materials[1] =
{
	{
		{{ 0.137584f, 0.053289f, 0.012575f },
		1.000000f,
		{ 0.500000f, 0.500000f, 0.500000f },
		250.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		60.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		1.450000f,
		{ 0.000000f, 0.000000f, 0.000000f },
		2},
		"Material",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
	},
};
#define _Door_Frame_materials_
#endif
/************************************************/
/*  This section contains the model's structure */
/************************************************/
#ifndef _Door_Frame_batches_
// Use this conveinence array to batch render all geometry by like material.
// Each entry corresponds to the same entry in the materials array above.
// The two numbers provided are the IndexCount and the IndexOffset into the indices array.
// If you need more fine grained control(ex: for transformations) use the OBJ_MESH data below.
const unsigned int Door_Frame_batches[1][2] =
{
	{ 348, 0 },
};
#define _Door_Frame_batches_
#endif
#ifndef __OBJ_MESH__
typedef struct _OBJ_MESH_
{
	const char* name;
	unsigned    indexCount;
	unsigned    indexOffset;
	unsigned    materialIndex;
}OBJ_MESH;
#define __OBJ_MESH__
#endif
#ifndef _Door_Frame_meshes_
// Mesh Data follows: Meshes are .obj groups sorted & split by material.
// Meshes are provided in sequential order, sorted by material first and name second.
const OBJ_MESH Door_Frame_meshes[1] =
{
	{
		"default",
		348,
		0,
		0,
	},
};
#define _Door_Frame_meshes_
#endif
