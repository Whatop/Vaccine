#pragma once
struct Vertex {
	float x, y, z, w; // D3DFVF_XYZRHW ??ġ????
	D3DCOLOR color; // D3DFVF_DIFFUSE ????
};

#define COLORKEY_GREEN D3DCOLOR_ARGB(255,0,133,0)
class GroundMgr : public Singleton<GroundMgr>
{
	int arr;
	int width;//??
public:


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

