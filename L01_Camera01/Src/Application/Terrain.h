#pragma once
class Terrain : public KdGameObject
{
public:
	Terrain();
	~Terrain()override;

	void Init()override;
	void Update()override;
	void DrawLit()override;

private:
	void Release();
	//地形データ
	std::shared_ptr<KdModelData> m_spTerrain = nullptr;
};