#pragma once
class Sun : public KdGameObject
{
public:
	Sun();
	~Sun()override;

	void Init()override;
	void Update()override;
	void DrawLit()override;

private:
	void Release();
	//地形データ
	std::shared_ptr<KdModelData> m_spSun = nullptr;
};