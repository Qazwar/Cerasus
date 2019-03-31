/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2019, Sakura&Fantasy
*     All rights reserved.
*
* @file		DirectTypes.h
* @brief	This File is DirectX Library Template Header.
* @author	Alopex/Alice
* @version	v1.00a
* @date		2019-03-31	v1.00a	alopex	Create File.
*/
#pragma once

#ifndef __DIRECTTYPES_H_
#define	__DIRECTTYPES_H_

// Include DirectX Common Header File
#include "DirectCommon.h"

// Enum Definition
// Vertex 3D Type(3D顶点类型)
enum E_DX_VERTEX3D_TYPE
{
	Vertex3D_Type_Base = 0,							// Base类型
	Vertex3D_Type_Texture = 1,						// Texture类型
	Vertex3D_Type_Normal = 2,						// Normal类型
	Vertex3D_Type_Normal_Texture = 3,				// NormalTexture类型
	Vertex3D_Type_Normal_Specular_Texture = 4,		// NormalSpecularTexture类型
};

// Light Type(Light光源类型)
enum E_DX_LIGHT_TYPE
{
	Light_Type_Point = 0,							// Point点光源
	Light_Type_Direction = 1,						// Direction平行光源
	Light_Type_Spot = 2,							// Spot聚光灯光源
};

// Struct Definition
// Vertex 3D Base(3D基本顶点格式)
struct S_DX_VERTEX3D_BASE
{
	float X, Y, Z;
	DWORD COLOR;
	S_DX_VERTEX3D_BASE(float x, float y, float z, DWORD Color) :X(x), Y(y), Z(z), COLOR(Color) {}
};

#define D3DFVF_VERTEX3D_BASE	(D3DFVF_XYZ | D3DFVF_DIFFUSE)						// 基本顶点格式模式(3D坐标/漫反射光线)

// Vertex 3D Texture(3D纹理顶点格式)
struct S_DX_VERTEX3D_TEXTURE
{
	float X, Y, Z;
	DWORD COLOR;
	float U, V;
	S_DX_VERTEX3D_TEXTURE(float x, float y, float z, DWORD Color, float u, float v) :X(x), Y(y), Z(z), COLOR(Color), U(u), V(v) {}
};

#define D3DFVF_VERTEX3D_TEXTURE	(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1)			// 纹理顶点格式模式(3D坐标/漫反射光线/纹理图样)

// Vertex 3D Normal(3D法线顶点格式)
struct S_DX_VERTEX3D_NORMAL
{
	float X, Y, Z;
	float nX, nY, nZ;
	DWORD COLOR;
	S_DX_VERTEX3D_NORMAL(float x, float y, float z, float nx, float ny, float nz, DWORD Color) :X(x), Y(y), Z(z), nX(nx), nY(ny), nZ(nz), COLOR(Color) {}
};

#define D3DFVF_VERTEX3D_NORMAL	(D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE)		// 法线顶点格式模式(3D坐标/法线坐标/漫反射光线)

// Vertex 3D Normal Texture(3D法线纹理顶点格式)(光照栅格)
struct S_DX_VERTEX3D_NORMAL_TEXTURE
{
	float X, Y, Z;
	float nX, nY, nZ;
	DWORD COLOR;
	float U, V;
	S_DX_VERTEX3D_NORMAL_TEXTURE(float x, float y, float z, float nx, float ny, float nz, DWORD Color, float u, float v) :X(x), Y(y), Z(z), nX(nx), nY(ny), nZ(nz), COLOR(Color), U(u), V(v) {}
};

#define D3DFVF_VERTEX3D_NORMAL_TEXTURE	(D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1)										// 法线纹理顶点格式模式(3D坐标/法线坐标/漫反射光线/纹理图样)

// Vertex 3D Normal Specular Texture(3D法线镜面反射纹理顶点格式)(镜面反射光、光照栅格)
struct S_DX_VERTEX3D_NORMAL_SPECULAR_TEXTURE
{
	float X, Y, Z;
	float nX, nY, nZ;
	DWORD DIFFUSE;
	DWORD SPECULAR;
	float U, V;
	S_DX_VERTEX3D_NORMAL_SPECULAR_TEXTURE(float x, float y, float z, float nx, float ny, float nz, DWORD Diffuse, DWORD Specular, float u, float v) :X(x), Y(y), Z(z), nX(nx), nY(ny), nZ(nz), DIFFUSE(Diffuse), SPECULAR(Specular), U(u), V(v) {}
};

#define D3DFVF_VERTEX3D_NORMAL_SPECULAR_TEXTURE	(D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1)			// 法线镜面反射纹理顶点格式模式(3D坐标/法线坐标/漫反射光线/纹理图样)

// World Space Scale Transform(~世界变换拉伸变换)
typedef struct
{
	float fScaleX;		// X轴比例
	float fScaleY;		// Y轴比例
	float fScaleZ;		// Z轴比例
} S_DX_SCALE_PARA, *LPS_DX_SCALE_PARA;

// World Space Rotate Transform(~世界变换旋转变换)
typedef struct
{
	float fRotateX;		// X轴旋转
	float fRotateY;		// Y轴旋转
	float fRotateZ;		// Z轴旋转
} S_DX_ROTATE_PARA, *LPS_DX_ROTATE_PARA;

// World Space Translate Transform(~世界变换位移变换)
typedef struct
{
	float fTranslateX;	// X轴平移
	float fTranslateY;	// Y轴平移
	float fTranslateZ;	// Z轴平移
} S_DX_TRANSLATE_PARA, *LPS_DX_TRANSLATE_PARA;

// World Space Transform(~世界变换)
typedef struct
{
	S_DX_SCALE_PARA		sScalePara;			// 比例系数
	S_DX_ROTATE_PARA	sRotatePara;		// 旋转系数
	S_DX_TRANSLATE_PARA sTranslatePara;		// 平移系数
} S_DX_WORLD_TRANSFORM_PARA, *LPS_DX_WORLD_TRANSFORM_PARA;

// View Space Transform(~取景变换)
typedef struct
{
	D3DXVECTOR3 vEye;	// 摄像机位置
	D3DXVECTOR3 vAt;	// 物体位置
	D3DXVECTOR3 vUp;	// 向上向量
} S_DX_VIEW_TRANSFORM_PARA, *LPS_DX_VIEW_TRANSFORM_PARA;

// Perspective Transform(~投影变换)
typedef struct
{
	float fovy;			// Y轴视域角度(弧度) eg:D3DX_PI * 0.5f
	float fAspect;		// 视口屏幕比例(宽度/高度)
	float fZn;			// 视截体近裁剪面距离
	float fZf;			// 视截体远裁剪面距离
} S_DX_PRESPECTIVE_TRANSFORM_PARA, *LPS_DX_PRESPECTIVE_TRANSFORM_PARA;

// ViewPort Transform(~视口变换)
typedef struct
{
	int nUserWidth;		// 窗口视口宽度
	int nUserHeight;	// 窗口视口高度
} S_DX_VIEWPORT_TRANSFORM_PARA, *LPS_DX_VIEWPORT_TRANSFORM_PARA;

// Coords Transform(~坐标变换)
typedef struct
{
	S_DX_WORLD_TRANSFORM_PARA		sWorldTransformPara;				// 世界变换系数
	S_DX_VIEW_TRANSFORM_PARA		sViewTransformPara;					// 取景变换系数
	S_DX_PRESPECTIVE_TRANSFORM_PARA	sPrespectiveTransformPara;			// 投影变换系数
	S_DX_VIEWPORT_TRANSFORM_PARA	sViewPortTransformPara;				// 视口变换系数
} S_DX_COORDS_TRANSFORM_PARA, *LPS_DX_COORDS_TRANSFORM_PARA;

#endif // !__DIRECTTYPES_H_

