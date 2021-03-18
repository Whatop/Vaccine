#pragma once
struct Vertex {
	float x, y, z, w; // D3DFVF_XYZRHW À§Ä¡Á¤º¸
	D3DCOLOR color; // D3DFVF_DIFFUSE »ö±ò
};

#define COLORKEY_GREEN D3DCOLOR_ARGB(255,0,133,0)
class GroundMgr : public Singleton<GroundMgr>
{
	LPDIRECT3DDEVICE9 m_pD3DD;
	int arr;
	int width;//Æø
public:
	Vec2 m_LinePos[256] = {};


	GroundMgr();
	~GroundMgr();

	void PlayerPos(Vec2 PlayerPos);
	void LinePos(Vec2 LinePos);
	void Fill();
	void ResetArr();
	void SetLine();

	void Update(float deltaTime, float time);
	void Render();
};

