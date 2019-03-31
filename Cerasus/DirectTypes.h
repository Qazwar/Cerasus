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
// Vertex 3D Type(3D��������)
enum E_DX_VERTEX3D_TYPE
{
	Vertex3D_Type_Base = 0,							// Base����
	Vertex3D_Type_Texture = 1,						// Texture����
	Vertex3D_Type_Normal = 2,						// Normal����
	Vertex3D_Type_Normal_Texture = 3,				// NormalTexture����
	Vertex3D_Type_Normal_Specular_Texture = 4,		// NormalSpecularTexture����
};

// Light Type(Light��Դ����)
enum E_DX_LIGHT_TYPE
{
	Light_Type_Point = 0,							// Point���Դ
	Light_Type_Direction = 1,						// Directionƽ�й�Դ
	Light_Type_Spot = 2,							// Spot�۹�ƹ�Դ
};

// Struct Definition
// Vertex 3D Base(3D���������ʽ)
struct S_DX_VERTEX3D_BASE
{
	float X, Y, Z;
	DWORD COLOR;
	S_DX_VERTEX3D_BASE(float x, float y, float z, DWORD Color) :X(x), Y(y), Z(z), COLOR(Color) {}
};

#define D3DFVF_VERTEX3D_BASE	(D3DFVF_XYZ | D3DFVF_DIFFUSE)						// ���������ʽģʽ(3D����/���������)

// Vertex 3D Texture(3D���������ʽ)
struct S_DX_VERTEX3D_TEXTURE
{
	float X, Y, Z;
	DWORD COLOR;
	float U, V;
	S_DX_VERTEX3D_TEXTURE(float x, float y, float z, DWORD Color, float u, float v) :X(x), Y(y), Z(z), COLOR(Color), U(u), V(v) {}
};

#define D3DFVF_VERTEX3D_TEXTURE	(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1)			// ���������ʽģʽ(3D����/���������/����ͼ��)

// Vertex 3D Normal(3D���߶����ʽ)
struct S_DX_VERTEX3D_NORMAL
{
	float X, Y, Z;
	float nX, nY, nZ;
	DWORD COLOR;
	S_DX_VERTEX3D_NORMAL(float x, float y, float z, float nx, float ny, float nz, DWORD Color) :X(x), Y(y), Z(z), nX(nx), nY(ny), nZ(nz), COLOR(Color) {}
};

#define D3DFVF_VERTEX3D_NORMAL	(D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE)		// ���߶����ʽģʽ(3D����/��������/���������)

// Vertex 3D Normal Texture(3D�������������ʽ)(����դ��)
struct S_DX_VERTEX3D_NORMAL_TEXTURE
{
	float X, Y, Z;
	float nX, nY, nZ;
	DWORD COLOR;
	float U, V;
	S_DX_VERTEX3D_NORMAL_TEXTURE(float x, float y, float z, float nx, float ny, float nz, DWORD Color, float u, float v) :X(x), Y(y), Z(z), nX(nx), nY(ny), nZ(nz), COLOR(Color), U(u), V(v) {}
};

#define D3DFVF_VERTEX3D_NORMAL_TEXTURE	(D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1)										// �������������ʽģʽ(3D����/��������/���������/����ͼ��)

// Vertex 3D Normal Specular Texture(3D���߾��淴�����������ʽ)(���淴��⡢����դ��)
struct S_DX_VERTEX3D_NORMAL_SPECULAR_TEXTURE
{
	float X, Y, Z;
	float nX, nY, nZ;
	DWORD DIFFUSE;
	DWORD SPECULAR;
	float U, V;
	S_DX_VERTEX3D_NORMAL_SPECULAR_TEXTURE(float x, float y, float z, float nx, float ny, float nz, DWORD Diffuse, DWORD Specular, float u, float v) :X(x), Y(y), Z(z), nX(nx), nY(ny), nZ(nz), DIFFUSE(Diffuse), SPECULAR(Specular), U(u), V(v) {}
};

#define D3DFVF_VERTEX3D_NORMAL_SPECULAR_TEXTURE	(D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1)			// ���߾��淴�����������ʽģʽ(3D����/��������/���������/����ͼ��)

// World Space Scale Transform(~����任����任)
typedef struct
{
	float fScaleX;		// X�����
	float fScaleY;		// Y�����
	float fScaleZ;		// Z�����
} S_DX_SCALE_PARA, *LPS_DX_SCALE_PARA;

// World Space Rotate Transform(~����任��ת�任)
typedef struct
{
	float fRotateX;		// X����ת
	float fRotateY;		// Y����ת
	float fRotateZ;		// Z����ת
} S_DX_ROTATE_PARA, *LPS_DX_ROTATE_PARA;

// World Space Translate Transform(~����任λ�Ʊ任)
typedef struct
{
	float fTranslateX;	// X��ƽ��
	float fTranslateY;	// Y��ƽ��
	float fTranslateZ;	// Z��ƽ��
} S_DX_TRANSLATE_PARA, *LPS_DX_TRANSLATE_PARA;

// World Space Transform(~����任)
typedef struct
{
	S_DX_SCALE_PARA		sScalePara;			// ����ϵ��
	S_DX_ROTATE_PARA	sRotatePara;		// ��תϵ��
	S_DX_TRANSLATE_PARA sTranslatePara;		// ƽ��ϵ��
} S_DX_WORLD_TRANSFORM_PARA, *LPS_DX_WORLD_TRANSFORM_PARA;

// View Space Transform(~ȡ���任)
typedef struct
{
	D3DXVECTOR3 vEye;	// �����λ��
	D3DXVECTOR3 vAt;	// ����λ��
	D3DXVECTOR3 vUp;	// ��������
} S_DX_VIEW_TRANSFORM_PARA, *LPS_DX_VIEW_TRANSFORM_PARA;

// Perspective Transform(~ͶӰ�任)
typedef struct
{
	float fovy;			// Y������Ƕ�(����) eg:D3DX_PI * 0.5f
	float fAspect;		// �ӿ���Ļ����(����/�߶�)
	float fZn;			// �ӽ�����ü������
	float fZf;			// �ӽ���Զ�ü������
} S_DX_PRESPECTIVE_TRANSFORM_PARA, *LPS_DX_PRESPECTIVE_TRANSFORM_PARA;

// ViewPort Transform(~�ӿڱ任)
typedef struct
{
	int nUserWidth;		// �����ӿڿ���
	int nUserHeight;	// �����ӿڸ߶�
} S_DX_VIEWPORT_TRANSFORM_PARA, *LPS_DX_VIEWPORT_TRANSFORM_PARA;

// Coords Transform(~����任)
typedef struct
{
	S_DX_WORLD_TRANSFORM_PARA		sWorldTransformPara;				// ����任ϵ��
	S_DX_VIEW_TRANSFORM_PARA		sViewTransformPara;					// ȡ���任ϵ��
	S_DX_PRESPECTIVE_TRANSFORM_PARA	sPrespectiveTransformPara;			// ͶӰ�任ϵ��
	S_DX_VIEWPORT_TRANSFORM_PARA	sViewPortTransformPara;				// �ӿڱ任ϵ��
} S_DX_COORDS_TRANSFORM_PARA, *LPS_DX_COORDS_TRANSFORM_PARA;

#endif // !__DIRECTTYPES_H_
