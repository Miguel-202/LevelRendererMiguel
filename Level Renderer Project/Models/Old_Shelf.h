// "Old_Shelf.h" generated by "Obj2Header.exe" [Version 1.9d] Author: L.Norri Fullsail University.
// Data is converted to left-handed coordinate system and UV data is V flipped for Direct3D/Vulkan.
// The companion file "Old_Shelf.h2b" is a binary dump of this format(-padding) for more flexibility.
// Loading *.h2b: read version, sizes, handle strings(max len 260) by reading until null-terminated.
/***********************/
/*  Generator version  */
/***********************/
#ifndef _Old_Shelf_version_
const char Old_Shelf_version[4] = { '0','1','9','d' };
#define _Old_Shelf_version_
#endif
/************************************************/
/*  This section contains the model's size data */
/************************************************/
#ifndef _Old_Shelf_vertexcount_
const unsigned Old_Shelf_vertexcount = 162;
#define _Old_Shelf_vertexcount_
#endif
#ifndef _Old_Shelf_indexcount_
const unsigned Old_Shelf_indexcount = 252;
#define _Old_Shelf_indexcount_
#endif
#ifndef _Old_Shelf_materialcount_
const unsigned Old_Shelf_materialcount = 1; // can be used for batched draws
#define _Old_Shelf_materialcount_
#endif
#ifndef _Old_Shelf_meshcount_
const unsigned Old_Shelf_meshcount = 1;
#define _Old_Shelf_meshcount_
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
#ifndef _Old_Shelf_vertices_
// Raw Vertex Data follows: Positions, Texture Coordinates and Normals.
const OBJ_VERT Old_Shelf_vertices[162] =
{
	{	{ -31.778154f, 9.192507f, -15.182461f },	{ 0.375000f, 0.750000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -31.778154f, 9.282383f, -15.182461f },	{ 0.625000f, 0.750000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -31.778154f, 9.282383f, -17.720663f },	{ 0.625000f, 1.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -31.778154f, 9.192507f, -17.720663f },	{ 0.375000f, 1.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -31.241722f, 9.332305f, -17.641146f },	{ 0.684553f, 0.250000f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -31.395678f, 9.332305f, -17.641146f },	{ 0.723771f, 0.250000f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -31.395678f, 9.332305f, -15.182461f },	{ 0.723770f, 0.500000f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -31.241722f, 9.332305f, -15.182461f },	{ 0.684553f, 0.500000f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -31.007936f, 9.192507f, -17.720663f },	{ 0.375000f, 0.250000f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -31.007936f, 9.313119f, -17.720663f },	{ 0.625000f, 0.250000f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -31.007936f, 9.313119f, -15.182461f },	{ 0.625000f, 0.500000f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -31.007936f, 9.192507f, -15.182461f },	{ 0.375000f, 0.500000f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -31.494770f, 9.192507f, -17.697515f },	{ 0.237049f, 0.250000f, 0.000000f },	{ 0.000000f, -1.000000f, 0.009200f }	},
	{	{ -31.424574f, 9.192507f, -17.697515f },	{ 0.264804f, 0.250000f, 0.000000f },	{ 0.000000f, -1.000000f, 0.009200f }	},
	{	{ -31.424574f, 9.215555f, -15.182461f },	{ 0.264804f, 0.500000f, 0.000000f },	{ 0.000000f, -1.000000f, 0.009200f }	},
	{	{ -31.494770f, 9.215555f, -15.182461f },	{ 0.237049f, 0.500000f, 0.000000f },	{ 0.000000f, -1.000000f, 0.009200f }	},
	{	{ -31.395678f, 9.192507f, -17.641146f },	{ 0.375000f, 0.151230f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -31.395678f, 9.332305f, -17.641146f },	{ 0.625000f, 0.151230f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -31.241722f, 9.332305f, -17.641146f },	{ 0.625000f, 0.190447f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -31.241722f, 9.192507f, -17.641146f },	{ 0.375000f, 0.190447f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -31.494770f, 9.313119f, -17.697515f },	{ 0.762951f, 0.250000f, 0.000000f },	{ -0.147300f, 0.989100f, -0.004500f }	},
	{	{ -31.778154f, 9.282383f, -17.720663f },	{ 0.875000f, 0.250000f, 0.000000f },	{ -0.147300f, 0.989100f, -0.004500f }	},
	{	{ -31.778154f, 9.282383f, -15.182461f },	{ 0.875000f, 0.500000f, 0.000000f },	{ -0.147300f, 0.989100f, -0.004500f }	},
	{	{ -31.494770f, 9.336167f, -15.182461f },	{ 0.762951f, 0.500000f, 0.000000f },	{ -0.147300f, 0.989100f, -0.004500f }	},
	{	{ -31.007936f, 9.192507f, -15.182461f },	{ 0.375000f, 0.500000f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -31.007936f, 9.313119f, -15.182461f },	{ 0.625000f, 0.500000f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -31.241722f, 9.332305f, -15.182461f },	{ 0.625000f, 0.559553f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -31.241722f, 9.192507f, -15.182461f },	{ 0.375000f, 0.559553f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -31.778154f, 9.192507f, -17.720663f },	{ 0.375000f, 0.000000f, 0.000000f },	{ 0.081400f, 0.000000f, -0.996700f }	},
	{	{ -31.778154f, 9.282383f, -17.720663f },	{ 0.625000f, 0.000000f, 0.000000f },	{ 0.081400f, 0.000000f, -0.996700f }	},
	{	{ -31.494770f, 9.313119f, -17.697515f },	{ 0.625000f, 0.112049f, 0.000000f },	{ 0.081400f, 0.000000f, -0.996700f }	},
	{	{ -31.494770f, 9.192507f, -17.697515f },	{ 0.375000f, 0.112049f, 0.000000f },	{ 0.081400f, 0.000000f, -0.996700f }	},
	{	{ -31.241722f, 9.192507f, -17.641146f },	{ 0.315447f, 0.250000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -31.007936f, 9.192507f, -17.720663f },	{ 0.375000f, 0.250000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -31.007936f, 9.192507f, -15.182461f },	{ 0.375000f, 0.500000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -31.241722f, 9.192507f, -15.182461f },	{ 0.315447f, 0.500000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -31.395678f, 9.202278f, -15.197133f },	{ 0.276230f, 0.500000f, 0.000000f },	{ -1.000000f, -0.000300f, -0.000000f }	},
	{	{ -31.395678f, 9.202278f, -17.682842f },	{ 0.276230f, 0.250000f, 0.000000f },	{ -1.000000f, -0.000300f, -0.000000f }	},
	{	{ -31.395678f, 9.192507f, -17.641146f },	{ 0.276230f, 0.250000f, 0.000000f },	{ -1.000000f, -0.000300f, -0.000000f }	},
	{	{ -31.395678f, 9.192507f, -15.182461f },	{ 0.276230f, 0.500000f, 0.000000f },	{ -1.000000f, -0.000300f, -0.000000f }	},
	{	{ -31.424574f, 9.215555f, -15.182461f },	{ 0.264804f, 0.500000f, 0.000000f },	{ -1.000000f, -0.001700f, -0.000000f }	},
	{	{ -31.424574f, 9.202278f, -17.682842f },	{ 0.264804f, 0.250000f, 0.000000f },	{ -1.000000f, -0.001700f, -0.000000f }	},
	{	{ -31.424574f, 9.202278f, -15.197133f },	{ 0.264804f, 0.500000f, 0.000000f },	{ -1.000000f, -0.001700f, -0.000000f }	},
	{	{ -31.424574f, 9.192507f, -17.697515f },	{ 0.264804f, 0.250000f, 0.000000f },	{ -1.000000f, -0.001700f, -0.000000f }	},
	{	{ -31.395678f, 9.202278f, -17.682842f },	{ 0.375000f, 0.151230f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -31.395678f, 9.303348f, -17.682842f },	{ 0.625000f, 0.151230f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -31.395678f, 9.332305f, -17.641146f },	{ 0.625000f, 0.151230f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -31.395678f, 9.192507f, -17.641146f },	{ 0.375000f, 0.151230f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -31.424574f, 9.202278f, -15.197133f },	{ 0.375000f, 0.610196f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -31.424574f, 9.303348f, -15.197133f },	{ 0.625000f, 0.610196f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -31.424574f, 9.336167f, -15.182461f },	{ 0.625000f, 0.610196f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -31.424574f, 9.215555f, -15.182461f },	{ 0.375000f, 0.610196f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -31.424574f, 9.215555f, -15.182461f },	{ 0.375000f, 0.610196f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -31.424574f, 9.336167f, -15.182461f },	{ 0.625000f, 0.610196f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -31.494770f, 9.336167f, -15.182461f },	{ 0.625000f, 0.637951f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -31.494770f, 9.215555f, -15.182461f },	{ 0.375000f, 0.637951f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -31.395678f, 9.303348f, -15.197133f },	{ 0.723770f, 0.500000f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -31.395678f, 9.303348f, -17.682842f },	{ 0.723771f, 0.250000f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -31.424574f, 9.303348f, -17.682842f },	{ 0.735196f, 0.250000f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -31.424574f, 9.303348f, -15.197133f },	{ 0.735196f, 0.500000f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -31.424574f, 9.202278f, -15.197133f },	{ 0.264804f, 0.500000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -31.424574f, 9.202278f, -17.682842f },	{ 0.264804f, 0.250000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -31.395678f, 9.202278f, -17.682842f },	{ 0.276230f, 0.250000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -31.395678f, 9.202278f, -15.197133f },	{ 0.276230f, 0.500000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -31.395678f, 9.303348f, -17.682842f },	{ 0.625000f, 0.151230f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -31.395678f, 9.202278f, -17.682842f },	{ 0.375000f, 0.151230f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -31.424574f, 9.202278f, -17.682842f },	{ 0.375000f, 0.139804f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -31.424574f, 9.303348f, -17.682842f },	{ 0.625000f, 0.139804f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -31.424574f, 9.303348f, -15.197133f },	{ 0.625000f, 0.610196f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -31.424574f, 9.202278f, -15.197133f },	{ 0.375000f, 0.610196f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -31.395678f, 9.202278f, -15.197133f },	{ 0.375000f, 0.598770f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -31.395678f, 9.303348f, -15.197133f },	{ 0.625000f, 0.598770f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -31.395678f, 9.303348f, -17.682842f },	{ 0.723771f, 0.250000f, 0.000000f },	{ -1.000000f, 0.000100f, -0.000000f }	},
	{	{ -31.395678f, 9.303348f, -15.197133f },	{ 0.723770f, 0.500000f, 0.000000f },	{ -1.000000f, 0.000100f, -0.000000f }	},
	{	{ -31.395678f, 9.332305f, -15.182461f },	{ 0.723770f, 0.500000f, 0.000000f },	{ -1.000000f, 0.000100f, -0.000000f }	},
	{	{ -31.395678f, 9.332305f, -17.641146f },	{ 0.723771f, 0.250000f, 0.000000f },	{ -1.000000f, 0.000100f, -0.000000f }	},
	{	{ -31.424574f, 9.303348f, -15.197133f },	{ 0.735196f, 0.500000f, 0.000000f },	{ 1.000000f, 0.000100f, -0.000000f }	},
	{	{ -31.424574f, 9.303348f, -17.682842f },	{ 0.735196f, 0.250000f, 0.000000f },	{ 1.000000f, 0.000100f, -0.000000f }	},
	{	{ -31.424574f, 9.313119f, -17.697515f },	{ 0.735196f, 0.250000f, 0.000000f },	{ 1.000000f, 0.000100f, -0.000000f }	},
	{	{ -31.424574f, 9.336167f, -15.182461f },	{ 0.735196f, 0.500000f, 0.000000f },	{ 1.000000f, 0.000100f, -0.000000f }	},
	{	{ -31.395678f, 9.303348f, -15.197133f },	{ 0.625000f, 0.598770f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -31.395678f, 9.202278f, -15.197133f },	{ 0.375000f, 0.598770f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -31.395678f, 9.192507f, -15.182461f },	{ 0.375000f, 0.598770f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -31.395678f, 9.332305f, -15.182461f },	{ 0.625000f, 0.598770f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -31.424574f, 9.303348f, -17.682842f },	{ 0.625000f, 0.139804f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -31.424574f, 9.202278f, -17.682842f },	{ 0.375000f, 0.139804f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -31.424574f, 9.192507f, -17.697515f },	{ 0.375000f, 0.139804f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -31.424574f, 9.313119f, -17.697515f },	{ 0.625000f, 0.139804f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -31.395678f, 9.192507f, -17.641146f },	{ 0.276230f, 0.250000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -31.395678f, 9.192507f, -15.182461f },	{ 0.276230f, 0.500000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -31.395678f, 9.332305f, -15.182461f },	{ 0.625000f, 0.598770f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -31.395678f, 9.192507f, -15.182461f },	{ 0.375000f, 0.598770f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -31.241722f, 9.192507f, -17.641146f },	{ 0.375000f, 0.190447f, 0.000000f },	{ -0.322000f, 0.000000f, -0.946700f }	},
	{	{ -31.241722f, 9.332305f, -17.641146f },	{ 0.625000f, 0.190447f, 0.000000f },	{ -0.322000f, 0.000000f, -0.946700f }	},
	{	{ -31.007936f, 9.313119f, -17.720663f },	{ 0.625000f, 0.250000f, 0.000000f },	{ -0.322000f, 0.000000f, -0.946700f }	},
	{	{ -31.007936f, 9.192507f, -17.720663f },	{ 0.375000f, 0.250000f, 0.000000f },	{ -0.322000f, 0.000000f, -0.946700f }	},
	{	{ -31.007936f, 9.313119f, -17.720663f },	{ 0.625000f, 0.250000f, 0.000000f },	{ 0.081800f, 0.996600f, -0.000000f }	},
	{	{ -31.241722f, 9.332305f, -17.641146f },	{ 0.684553f, 0.250000f, 0.000000f },	{ 0.081800f, 0.996600f, -0.000000f }	},
	{	{ -31.241722f, 9.332305f, -15.182461f },	{ 0.684553f, 0.500000f, 0.000000f },	{ 0.081800f, 0.996600f, -0.000000f }	},
	{	{ -31.007936f, 9.313119f, -15.182461f },	{ 0.625000f, 0.500000f, 0.000000f },	{ 0.081800f, 0.996600f, -0.000000f }	},
	{	{ -31.778154f, 9.282383f, -15.182461f },	{ 0.625000f, 0.750000f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -31.778154f, 9.192507f, -15.182461f },	{ 0.375000f, 0.750000f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -31.494770f, 9.192507f, -17.697515f },	{ 0.375000f, 0.112049f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -31.494770f, 9.313119f, -17.697515f },	{ 0.625000f, 0.112049f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -31.424574f, 9.313119f, -17.697515f },	{ 0.625000f, 0.139804f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -31.424574f, 9.192507f, -17.697515f },	{ 0.375000f, 0.139804f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -31.424574f, 9.313119f, -17.697515f },	{ 0.735196f, 0.250000f, 0.000000f },	{ 0.000000f, 1.000000f, -0.009200f }	},
	{	{ -31.494770f, 9.313119f, -17.697515f },	{ 0.762951f, 0.250000f, 0.000000f },	{ 0.000000f, 1.000000f, -0.009200f }	},
	{	{ -31.494770f, 9.336167f, -15.182461f },	{ 0.762951f, 0.500000f, 0.000000f },	{ 0.000000f, 1.000000f, -0.009200f }	},
	{	{ -31.424574f, 9.336167f, -15.182461f },	{ 0.735196f, 0.500000f, 0.000000f },	{ 0.000000f, 1.000000f, -0.009200f }	},
	{	{ -31.778154f, 9.192507f, -17.720663f },	{ 0.125000f, 0.250000f, 0.000000f },	{ 0.040400f, -0.999200f, 0.004600f }	},
	{	{ -31.494770f, 9.192507f, -17.697515f },	{ 0.237049f, 0.250000f, 0.000000f },	{ 0.040400f, -0.999200f, 0.004600f }	},
	{	{ -31.494770f, 9.215555f, -15.182461f },	{ 0.237049f, 0.500000f, 0.000000f },	{ 0.040400f, -0.999200f, 0.004600f }	},
	{	{ -31.778154f, 9.192507f, -15.182461f },	{ 0.125000f, 0.500000f, 0.000000f },	{ 0.040400f, -0.999200f, 0.004600f }	},
	{	{ -31.782639f, 8.435839f, -16.859379f },	{ 0.375000f, 0.750000f, 0.000000f },	{ -0.854900f, 0.518800f, -0.000000f }	},
	{	{ -31.323133f, 9.192963f, -16.859379f },	{ 0.625000f, 0.750000f, 0.000000f },	{ -0.854900f, 0.518800f, -0.000000f }	},
	{	{ -31.323133f, 9.192963f, -17.099564f },	{ 0.625000f, 1.000000f, 0.000000f },	{ -0.854900f, 0.518800f, -0.000000f }	},
	{	{ -31.782639f, 8.435839f, -17.099564f },	{ 0.375000f, 1.000000f, 0.000000f },	{ -0.854900f, 0.518800f, -0.000000f }	},
	{	{ -31.778156f, 8.392656f, -16.859379f },	{ 0.375000f, 0.500000f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -31.251982f, 9.192507f, -16.859379f },	{ 0.625000f, 0.500000f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -31.323133f, 9.192963f, -16.859379f },	{ 0.625000f, 0.750000f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -31.782639f, 8.435839f, -16.859379f },	{ 0.375000f, 0.750000f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -31.778156f, 8.392656f, -17.099564f },	{ 0.375000f, 0.250000f, 0.000000f },	{ 0.835400f, -0.549600f, -0.000000f }	},
	{	{ -31.251982f, 9.192507f, -17.099564f },	{ 0.625000f, 0.250000f, 0.000000f },	{ 0.835400f, -0.549600f, -0.000000f }	},
	{	{ -31.251982f, 9.192507f, -16.859379f },	{ 0.625000f, 0.500000f, 0.000000f },	{ 0.835400f, -0.549600f, -0.000000f }	},
	{	{ -31.778156f, 8.392656f, -16.859379f },	{ 0.375000f, 0.500000f, 0.000000f },	{ 0.835400f, -0.549600f, -0.000000f }	},
	{	{ -31.782639f, 8.435839f, -17.099564f },	{ 0.375000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -31.323133f, 9.192963f, -17.099564f },	{ 0.625000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -31.251982f, 9.192507f, -17.099564f },	{ 0.625000f, 0.250000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -31.778156f, 8.392656f, -17.099564f },	{ 0.375000f, 0.250000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -31.782639f, 8.435839f, -17.099564f },	{ 0.125000f, 0.250000f, 0.000000f },	{ -0.994700f, -0.103300f, -0.000000f }	},
	{	{ -31.778156f, 8.392656f, -17.099564f },	{ 0.375000f, 0.250000f, 0.000000f },	{ -0.994700f, -0.103300f, -0.000000f }	},
	{	{ -31.778156f, 8.392656f, -16.859379f },	{ 0.375000f, 0.500000f, 0.000000f },	{ -0.994700f, -0.103300f, -0.000000f }	},
	{	{ -31.782639f, 8.435839f, -16.859379f },	{ 0.125000f, 0.500000f, 0.000000f },	{ -0.994700f, -0.103300f, -0.000000f }	},
	{	{ -31.251982f, 9.192507f, -17.099564f },	{ 0.625000f, 0.250000f, 0.000000f },	{ 0.006400f, 1.000000f, -0.000000f }	},
	{	{ -31.323133f, 9.192963f, -17.099564f },	{ 0.875000f, 0.250000f, 0.000000f },	{ 0.006400f, 1.000000f, -0.000000f }	},
	{	{ -31.323133f, 9.192963f, -16.859379f },	{ 0.875000f, 0.500000f, 0.000000f },	{ 0.006400f, 1.000000f, -0.000000f }	},
	{	{ -31.251982f, 9.192507f, -16.859379f },	{ 0.625000f, 0.500000f, 0.000000f },	{ 0.006400f, 1.000000f, -0.000000f }	},
	{	{ -31.782639f, 8.435839f, -15.614956f },	{ 0.375000f, 0.750000f, 0.000000f },	{ -0.854900f, 0.518800f, -0.000000f }	},
	{	{ -31.323133f, 9.192963f, -15.614956f },	{ 0.625000f, 0.750000f, 0.000000f },	{ -0.854900f, 0.518800f, -0.000000f }	},
	{	{ -31.323133f, 9.192963f, -15.855140f },	{ 0.625000f, 1.000000f, 0.000000f },	{ -0.854900f, 0.518800f, -0.000000f }	},
	{	{ -31.782639f, 8.435839f, -15.855140f },	{ 0.375000f, 1.000000f, 0.000000f },	{ -0.854900f, 0.518800f, -0.000000f }	},
	{	{ -31.778156f, 8.392656f, -15.614956f },	{ 0.375000f, 0.500000f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -31.251982f, 9.192507f, -15.614956f },	{ 0.625000f, 0.500000f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -31.323133f, 9.192963f, -15.614956f },	{ 0.625000f, 0.750000f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -31.782639f, 8.435839f, -15.614956f },	{ 0.375000f, 0.750000f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -31.778156f, 8.392656f, -15.855140f },	{ 0.375000f, 0.250000f, 0.000000f },	{ 0.835400f, -0.549600f, -0.000000f }	},
	{	{ -31.251982f, 9.192507f, -15.855140f },	{ 0.625000f, 0.250000f, 0.000000f },	{ 0.835400f, -0.549600f, -0.000000f }	},
	{	{ -31.251982f, 9.192507f, -15.614956f },	{ 0.625000f, 0.500000f, 0.000000f },	{ 0.835400f, -0.549600f, -0.000000f }	},
	{	{ -31.778156f, 8.392656f, -15.614956f },	{ 0.375000f, 0.500000f, 0.000000f },	{ 0.835400f, -0.549600f, -0.000000f }	},
	{	{ -31.782639f, 8.435839f, -15.855140f },	{ 0.375000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -31.323133f, 9.192963f, -15.855140f },	{ 0.625000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -31.251982f, 9.192507f, -15.855140f },	{ 0.625000f, 0.250000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -31.778156f, 8.392656f, -15.855140f },	{ 0.375000f, 0.250000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -31.782639f, 8.435839f, -15.855140f },	{ 0.125000f, 0.250000f, 0.000000f },	{ -0.994700f, -0.103300f, -0.000000f }	},
	{	{ -31.778156f, 8.392656f, -15.855140f },	{ 0.375000f, 0.250000f, 0.000000f },	{ -0.994700f, -0.103300f, -0.000000f }	},
	{	{ -31.778156f, 8.392656f, -15.614956f },	{ 0.375000f, 0.500000f, 0.000000f },	{ -0.994700f, -0.103300f, -0.000000f }	},
	{	{ -31.782639f, 8.435839f, -15.614956f },	{ 0.125000f, 0.500000f, 0.000000f },	{ -0.994700f, -0.103300f, -0.000000f }	},
	{	{ -31.251982f, 9.192507f, -15.855140f },	{ 0.625000f, 0.250000f, 0.000000f },	{ 0.006400f, 1.000000f, -0.000000f }	},
	{	{ -31.323133f, 9.192963f, -15.855140f },	{ 0.875000f, 0.250000f, 0.000000f },	{ 0.006400f, 1.000000f, -0.000000f }	},
	{	{ -31.323133f, 9.192963f, -15.614956f },	{ 0.875000f, 0.500000f, 0.000000f },	{ 0.006400f, 1.000000f, -0.000000f }	},
	{	{ -31.251982f, 9.192507f, -15.614956f },	{ 0.625000f, 0.500000f, 0.000000f },	{ 0.006400f, 1.000000f, -0.000000f }	},
};
#define _Old_Shelf_vertices_
#endif
#ifndef _Old_Shelf_indices_
// Index Data follows: Sequential by mesh, Every Three Indices == One Triangle.
const unsigned int Old_Shelf_indices[252] =
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
	 43, 41, 40,
	 44, 45, 46,
	 47, 44, 46,
	 48, 49, 50,
	 51, 48, 50,
	 52, 53, 54,
	 55, 52, 54,
	 56, 57, 58,
	 59, 56, 58,
	 60, 61, 62,
	 63, 60, 62,
	 64, 65, 66,
	 67, 64, 66,
	 68, 69, 70,
	 71, 68, 70,
	 72, 73, 74,
	 75, 72, 74,
	 76, 77, 78,
	 79, 76, 78,
	 80, 81, 82,
	 83, 80, 82,
	 84, 85, 86,
	 87, 84, 86,
	 88, 32, 35,
	 89, 88, 35,
	 27, 26, 90,
	 91, 27, 90,
	 92, 93, 94,
	 95, 92, 94,
	 96, 97, 98,
	 99, 96, 98,
	 55, 54, 100,
	 101, 55, 100,
	 102, 103, 104,
	 105, 102, 104,
	 106, 107, 108,
	 109, 106, 108,
	 110, 111, 112,
	 113, 110, 112,
	 114, 115, 116,
	 117, 114, 116,
	 118, 119, 120,
	 121, 118, 120,
	 122, 123, 124,
	 125, 122, 124,
	 126, 127, 128,
	 129, 126, 128,
	 130, 131, 132,
	 133, 130, 132,
	 134, 135, 136,
	 137, 134, 136,
	 138, 139, 140,
	 141, 138, 140,
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
};
#define _Old_Shelf_indices_
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
#ifndef _Old_Shelf_materials_
// Material Data follows: pulled from a .mtl file of the same name if present.
const OBJ_MATERIAL Old_Shelf_materials[1] =
{
	{
		{{ 0.281004f, 0.096242f, 0.019049f },
		1.000000f,
		{ 0.500000f, 0.500000f, 0.500000f },
		250.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		60.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		1.450000f,
		{ 0.000000f, 0.000000f, 0.000000f },
		2},
		"Material.001",
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
#define _Old_Shelf_materials_
#endif
/************************************************/
/*  This section contains the model's structure */
/************************************************/
#ifndef _Old_Shelf_batches_
// Use this conveinence array to batch render all geometry by like material.
// Each entry corresponds to the same entry in the materials array above.
// The two numbers provided are the IndexCount and the IndexOffset into the indices array.
// If you need more fine grained control(ex: for transformations) use the OBJ_MESH data below.
const unsigned int Old_Shelf_batches[1][2] =
{
	{ 252, 0 },
};
#define _Old_Shelf_batches_
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
#ifndef _Old_Shelf_meshes_
// Mesh Data follows: Meshes are .obj groups sorted & split by material.
// Meshes are provided in sequential order, sorted by material first and name second.
const OBJ_MESH Old_Shelf_meshes[1] =
{
	{
		"default",
		252,
		0,
		0,
	},
};
#define _Old_Shelf_meshes_
#endif
