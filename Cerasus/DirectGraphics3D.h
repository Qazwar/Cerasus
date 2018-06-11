/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		DirectGraphics3D.h
* @brief	This File is DirectGraphics3D DLL Project.
* @author	Alopex/Helium
* @version	v1.26a
* @date		2017-11-29	v1.00a	alopex	Create Project.
* @date		2017-12-3	v1.01a	alopex	Modify Bug.
* @date		2017-12-8	v1.10a	alopex	Code Do Not Rely On MSVCR Library.
* @date		2018-1-10	v1.20a	alopex	Code Add dxerr & d3dcompiler Library and Modify Verify.
* @date		2018-1-10	v1.24a	alopex	Add Thread Safe File & Variable(DirectThreadSafe).
* @date		2018-2-12	v1.25a	alopex	Add Get & Set & Reset Function.
* @date		2018-4-12	v1.26a	alopex	Add Macro Call Mode.
*/
#pragma once

#ifndef __DIRECTGRAPHICS3D_H_
#define __DIRECTGRAPHICS3D_H_

//Include Windows Header File
#include "DirectCommon.h"

//Macro Definition
#ifdef	CERASUS_EXPORTS
#define DIRECTGRAPHICS3D_API	__declspec(dllexport)
#else
#define DIRECTGRAPHICS3D_API	__declspec(dllimport)
#endif

#define DIRECTGRAPHICS3D_CALLMODE	__stdcall

//Struct Definition
//Vertex 3D Base(3D���������ʽ)
struct Vertex3DBase
{
	float X, Y, Z;
	DWORD COLOR;
	Vertex3DBase(float x, float y, float z, DWORD Color) :X(x), Y(y), Z(z), COLOR(Color) {}
};

#define D3DFVF_VERTEX3D_BASE	(D3DFVF_XYZ | D3DFVF_DIFFUSE)				//���������ʽģʽ(3D����/���������)

//Vertex 3D Texture(3D���������ʽ)
struct Vertex3DTexture
{
	float X, Y, Z;
	DWORD COLOR;
	float U, V;
	Vertex3DTexture(float x, float y, float z, DWORD Color, float u, float v) :X(x), Y(y), Z(z), COLOR(Color), U(u), V(v) {}
};

#define D3DFVF_VERTEX3D_TEXTURE	(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1)	//���������ʽģʽ(3D����/���������/����ͼ��)

//Vertex 3D Normal(3D���߶����ʽ)
struct Vertex3DNormal
{
	float X, Y, Z;
	float nX, nY, nZ;
	DWORD COLOR;
	Vertex3DNormal(float x, float y, float z, float nx, float ny, float nz, DWORD Color) :X(x), Y(y), Z(z), nX(nx), nY(ny), nZ(nz), COLOR(Color) {}
};

#define D3DFVF_VERTEX3D_NORMAL	(D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE)	//���߶����ʽģʽ(3D����/��������/���������)

//Vertex 3D Normal Texture(3D�������������ʽ)(����դ��)
struct Vertex3DNormalTexture
{
	float X, Y, Z;
	float nX, nY, nZ;
	DWORD COLOR;
	float U, V;
	Vertex3DNormalTexture(float x, float y, float z, float nx, float ny, float nz, DWORD Color, float u, float v) :X(x), Y(y), Z(z), nX(nx), nY(ny), nZ(nz), COLOR(Color), U(u), V(v) {}
};

#define D3DFVF_VERTEX3D_NORMAL_TEXTURE	(D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1)	//�������������ʽģʽ(3D����/��������/���������/����ͼ��)

//Vertex 3D Normal Specular Texture(3D���߾��淴�����������ʽ)(���淴��⡢����դ��)
struct Vertex3DNormalSpecularTexture
{
	float X, Y, Z;
	float nX, nY, nZ;
	DWORD DIFFUSE;
	DWORD SPECULAR;
	float U, V;
	Vertex3DNormalSpecularTexture(float x, float y, float z, float nx, float ny, float nz, DWORD Diffuse, DWORD Specular, float u, float v) :X(x), Y(y), Z(z), nX(nx), nY(ny), nZ(nz), DIFFUSE(Diffuse), SPECULAR(Specular), U(u), V(v) {}
};

#define D3DFVF_VERTEX3D_NORMAL_SPECULAR_TEXTURE	(D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1)	//���߾��淴�����������ʽģʽ(3D����/��������/���������/����ͼ��)

//World Space Scale Transform
typedef struct
{
	float fScaleX;
	float fScaleY;
	float fScaleZ;
} DG3D_ScalePara;

//World Space Rotate Transform
typedef struct
{
	float fRotateX;
	float fRotateY;
	float fRotateZ;
} DG3D_RotatePara;

//World Space Translate Transform
typedef struct
{
	float fTranslateX;
	float fTranslateY;
	float fTranslateZ;
} DG3D_TranslatePara;

//World Space Transform
typedef struct
{
	DG3D_ScalePara sScalePara;
	DG3D_RotatePara sRotatePara;
	DG3D_TranslatePara sTranslatePara;
} DG3D_WorldTransformPara;

//View Space Transform
typedef struct
{
	D3DXVECTOR3 vEye;
	D3DXVECTOR3 vAt;
	D3DXVECTOR3 vUp;
} DG3D_ViewTransformPara;

//Perspective Transform
typedef struct
{
	float fovy;										//Y������Ƕ�(����) eg:D3DX_PI * 0.5f
	float fAspect;									//�ӿ���Ļ����(����/�߶�)
	float fZn;										//�ӽ�����ü������
	float fZf;										//�ӽ���Զ�ü������
} DG3D_PrespectiveTransformPara;

//ViewPort Transform
typedef struct
{
	int nUserWidth;									//�����ӿڿ���
	int nUserHeight;								//�����ӿڸ߶�
} DG3D_ViewPortTransformPara;

//Enum Definition(Vertex��������)
enum Vertex3DType
{
	Vertex3D_Type_Base = 0,							//Base����
	Vertex3D_Type_Texture = 1,						//Texture����
	Vertex3D_Type_Normal = 2,						//Normal����
	Vertex3D_Type_Normal_Texture = 3,				//NormalTexture����
	Vertex3D_Type_Normal_Specular_Texture = 4,		//NormalSpecularTexture����
};

//Enum Definition(Light��Դ����)
enum LightType
{
	LightType_Point = 0,							//Point���Դ
	LightType_Direction = 1,						//Directionƽ�й�Դ
	LightType_Spot = 2,								//Spot�۹�ƹ�Դ
};

//Class Definition
class DIRECTGRAPHICS3D_API DirectGraphics3D
{
protected:
	LPDIRECT3DDEVICE9 m_pD3D9Device;						//The Direct3D 9 Render Device 
	LPDIRECT3DVERTEXBUFFER9 m_pD3D9VertexBuffer;			//The Direct3D 9 Vertex Buffer
	LPDIRECT3DINDEXBUFFER9 m_pD3D9IndexBuffer;				//The Direct3D 9 Index  Buffer

private:
	LPDIRECT3DTEXTURE9 m_pD3D9Texture;						//The Direct3D 9 Texture

	CRITICAL_SECTION m_cs;									//Thread Safe(CriticalSection)
	bool m_bThreadSafe;										//Thread Safe Status

public:
	DirectGraphics3D();				//DirectGraphics3D Constructor Function
	virtual ~DirectGraphics3D();	//DirectGraphics3D Destructor  Function

	//����
	DirectGraphics3D(IDirect3DDevice9* pD3D9Device);	//DirectGraphics3D Constructor Function

	//����
	virtual IDirect3DDevice9* DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DGetDevice(void) const;					//DirectGraphics3D Get D3D9 Device ��ȡD3D9�豸
	virtual IDirect3DVertexBuffer9* DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DGetVertexBuffer(void) const;		//DirectGraphics3D Get D3D9 Vertex Buffer ��ȡD3D9���㻺��
	virtual IDirect3DIndexBuffer9* DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DGetIndexBuffer(void) const;		//DirectGraphics3D Get D3D9 Index Buffer ��ȡD3D9��������
	virtual IDirect3DTexture9* DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DGetTexture(void) const;				//DirectGraphics3D Get D3D9 Texture ��ȡD3D9����

	//����
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DSetDevice(IDirect3DDevice9* pD3D9Device);						//DirectGraphics3D Set D3D9 Device ����D3D9�豸
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DSetVertexBuffer(IDirect3DVertexBuffer9* pD3D9VertexBuffer);		//DirectGraphics3D Set D3D9 Vertex Buffer ����D3D9���㻺��
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DSetIndexBuffer(IDirect3DIndexBuffer9* pD3D9IndexBuffer);			//DirectGraphics3D Set D3D9 Index Buffer ����D3D9��������
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DSetTexture(IDirect3DTexture9* pD3D9Texture);						//DirectGraphics3D Set D3D9 Texture ����D3D9����

	//����(��ʧ�豸)
	virtual HRESULT DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DReset(void);										//DirectGraphics3D Reset D3D9����(Reset֮����Ҫ����Init�������³�ʼ��)

	//��ʼ��
	virtual HRESULT DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DInit(int nPlane);									//DirectGraphics3D Initialization(��ʼ��)
	virtual HRESULT DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DInit(int nPlane, LPCWSTR lpszStrTexture);			//DirectGraphics3D Initialization(��ʼ��)
	virtual HRESULT DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DInit(Vertex3DType eVertex3DType, int nPlane);		//DirectGraphics3D Initialization(��ʼ��)
	virtual HRESULT DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DInit(Vertex3DType eVertex3DType, int nPlane, LPCWSTR lpszStrTexture);		//DirectGraphics3D Initialization(��ʼ��)
	virtual HRESULT DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DInit(D3DPOOL ePool, DWORD Usage, Vertex3DType eVertex3DType, int nPlane);	//DirectGraphics3D Initialization(��ʼ��)
	virtual HRESULT DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DInit(D3DPOOL ePool, DWORD Usage, Vertex3DType eVertex3DType, int nPlane, LPCWSTR lpszStrTexture);	//DirectGraphics3D Initialization(��ʼ��)
	
	//����(T)(����任)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DWorldSpaceTransform(DG3D_ScalePara sScalePara);			//DirectGraphics3D WorldSpaceTransform(Scale)(����任)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DWorldSpaceTransform(DG3D_RotatePara sRotatePara);		//DirectGraphics3D WorldSpaceTransform(Rotate)(����任)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DWorldSpaceTransform(DG3D_TranslatePara sTranslatePara);	//DirectGraphics3D WorldSpaceTransform(Translate)(����任)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DWorldSpaceTransform(DG3D_ScalePara sScalePara, DG3D_RotatePara sRotatePara);										//DirectGraphics3D WorldSpaceTransform(����任)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DWorldSpaceTransform(DG3D_ScalePara sScalePara, DG3D_TranslatePara sTranslatePara);								//DirectGraphics3D WorldSpaceTransform(����任)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DWorldSpaceTransform(DG3D_RotatePara sRotatePara, DG3D_TranslatePara sTranslatePara);								//DirectGraphics3D WorldSpaceTransform(����任)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DWorldSpaceTransform(DG3D_ScalePara sScalePara, DG3D_RotatePara sRotatePara, DG3D_TranslatePara sTranslatePara);	//DirectGraphics3D WorldSpaceTransform(����任)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DWorldSpaceTransform(DG3D_WorldTransformPara sWorldTransformPara);												//DirectGraphics3D WorldSpaceTransform(����任)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DViewSpaceTransform(D3DXVECTOR3* pvEye);																			//DirectGraphics3D ViewSpaceTransform(ȡ���任)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DViewSpaceTransform(D3DXVECTOR3* pvEye, D3DXVECTOR3* pvAt);														//DirectGraphics3D ViewSpaceTransform(ȡ���任)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DViewSpaceTransform(D3DXVECTOR3* pvEye, D3DXVECTOR3* pvAt, D3DXVECTOR3* pvUp);									//DirectGraphics3D ViewSpaceTransform(ȡ���任)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DViewSpaceTransform(DG3D_ViewTransformPara sViewTransformPara);													//DirectGraphics3D ViewSpaceTransform(ȡ���任)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DPerspectiveTransform(DG3D_PrespectiveTransformPara sPrespectiveTransformPara);									//DirectGraphics3D PerspectiveTransform(͸��/ͶӰ�任)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DPerspectiveTransform(float fovy, float fAspect, float fZn, float fZf);											//DirectGraphics3D PerspectiveTransform(͸��/ͶӰ�任)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DViewPortTransform(DG3D_ViewPortTransformPara sViewPortTransformPara);											//DirectGraphics3D ViewPortTransform(�ӿڱ任)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DViewPortTransform(int nUserWidth, int nUserHeight);																//DirectGraphics3D ViewPortTransform(�ӿڱ任)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DMatrixTransform(DG3D_WorldTransformPara sWorldTransformPara, DG3D_ViewTransformPara sViewTransformPara, DG3D_PrespectiveTransformPara sPrespectiveTransformPara, DG3D_ViewPortTransformPara sViewPortTransformPara);					//DirectGraphics3D MatrixTransform

	//����(L)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DLightSettingPoint(D3DXCOLOR cAmbient, D3DXCOLOR cDiffuse, D3DXCOLOR cSpecular, D3DXVECTOR3 vPosition, float fRange, D3DCOLOR dwAmbientLight);																							//DirectGraphics3D Light Setting(��Դ����)(���Դ)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DLightSettingDirectional(D3DXCOLOR cAmbient, D3DXCOLOR cDiffuse, D3DXCOLOR cSpecular, D3DXVECTOR3 vDirectional, D3DCOLOR dwAmbientLight);																								//DirectGraphics3D Light Setting(��Դ����)(ƽ�й�Դ)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DLightSettingSpot(D3DXCOLOR cAmbient, D3DXCOLOR cDiffuse, D3DXCOLOR cSpecular, D3DXVECTOR3 vPosition, D3DXVECTOR3 vDirectional, float fRange, float fFallOff, float fPhi, float fTheta, D3DCOLOR dwAmbientLight);						//DirectGraphics3D Light Setting(��Դ����)(�۹�ƹ�Դ)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DLightSetting(D3DLIGHT9* pD3D9Light, D3DCOLOR dwAmbientLight);																																											//DirectGraphics3D Light Setting(��Դ����)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DLightSetting(LightType eLightType, D3DXCOLOR cAmbient, D3DXCOLOR cDiffuse, D3DXCOLOR cSpecular, D3DXVECTOR3 vPosition, D3DXVECTOR3 vDirectional, float fRange, float fFallOff, float fPhi, float fTheta, D3DCOLOR dwAmbientLight);		//DirectGraphics3D Light Setting(��Դ����)

	//����(M)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DMaterialSetting(D3DMATERIAL9* pD3D9Material);																					//DirectGraphics3D Material Setting(��������)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DMaterialSetting(D3DXCOLOR cAmbient, D3DXCOLOR cDiffuse, D3DXCOLOR cSpecular, D3DXCOLOR cEmissive);								//DirectGraphics3D Material Setting(��������)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DMaterialSetting(D3DXCOLOR cAmbient, D3DXCOLOR cDiffuse, D3DXCOLOR cSpecular, D3DXCOLOR cEmissive, float fPower);				//DirectGraphics3D Material Setting(��������)

	//���
	//����
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DPaddingVertex(Vertex3DBase* VertexArray, int nSize);						//DirectGraphics3D Padding Vertex(��䶥������)(3D���������ʽ)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DPaddingVertex(Vertex3DTexture* VertexArray, int nSize);						//DirectGraphics3D Padding Vertex(��䶥������)(3D���������ʽ)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DPaddingVertex(Vertex3DNormal* VertexArray, int nSize);						//DirectGraphics3D Padding Vertex(��䶥������)(3D���߶����ʽ)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DPaddingVertex(Vertex3DNormalTexture* VertexArray, int nSize);				//DirectGraphics3D Padding Vertex(��䶥������)(3D�������������ʽ)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DPaddingVertex(Vertex3DNormalSpecularTexture* VertexArray, int nSize);		//DirectGraphics3D Padding Vertex(��䶥������)(3D���߾��淴�����������ʽ)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DPaddingVertex(Vertex3DType eVertex3DType, LPVOID VertexArray, int nSize);	//DirectGraphics3D Padding Vertex(��䶥������)

	//����
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DPaddingIndex(int nPlane);													//DirectGraphics3D Padding Index(�����������)

	//All
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DPaddingVertexAndIndex(Vertex3DBase* VertexArray, int nPlane);							//DirectGraphics3D Padding Vertex and Index(��䶥�����������)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DPaddingVertexAndIndex(Vertex3DTexture* VertexArray, int nPlane);						//DirectGraphics3D Padding Vertex and Index(��䶥�����������)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DPaddingVertexAndIndex(Vertex3DNormal* VertexArray, int nPlane);							//DirectGraphics3D Padding Vertex and Index(��䶥�����������)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DPaddingVertexAndIndex(Vertex3DNormalTexture* VertexArray, int nPlane);					//DirectGraphics3D Padding Vertex and Index(��䶥�����������)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DPaddingVertexAndIndex(Vertex3DNormalSpecularTexture* VertexArray, int nPlane);			//DirectGraphics3D Padding Vertex and Index(��䶥�����������)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DPaddingVertexAndIndex(Vertex3DType eVertex3DType, LPVOID VertexArray, int nPlane);		//DirectGraphics3D Padding Vertex and Index(��䶥�����������)

	//��Ⱦ
	//��Ⱦģʽ
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DRenderStateAlphaEnable();																//DirectGraphics3D Render State Setting(����Alpha���)//��Ⱦ��Ϲر�Alpha���
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DRenderStateAlphaDisable();																//DirectGraphics3D Render State Setting(�ر�Alpha���)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DRenderStateLightEnable();																//DirectGraphics3D Render State Setting(����Light����)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DRenderStateLightDisable();																//DirectGraphics3D Render State Setting(�ر�Light����)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DRenderStateSetting();																	//DirectGraphics3D Render State Setting(������Ⱦģʽ)

	//��Ⱦ
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DRender(Vertex3DType eVertex3DType, int nPlane, bool bIsTexture = false);											//DirectGraphics3D Render(��Ⱦ)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DRender(Vertex3DType eVertex3DType, int nStartIndex, int nPlane, bool bIsTexture = false);							//DirectGraphics3D Render(��Ⱦ)
	virtual void DIRECTGRAPHICS3D_CALLMODE DirectGraphics3DRender(Vertex3DType eVertex3DType, int nStartIndex, int nPlane, LPDIRECT3DTEXTURE9 pRenderTexture);					//DirectGraphics3D Render(��Ⱦ)
};


#endif