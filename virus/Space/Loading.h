#pragma once
class Loading : public Object
{
private:
	Animation* m_Loding;
public:
	Loading(int type);
	~Loading();
	int frame;
	void Update(float deltaTIme, float Time);
	void Render();
};

