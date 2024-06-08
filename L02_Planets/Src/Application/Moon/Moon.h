#pragma once
class Moon : public KdGameObject
{
public:
	Moon();
	~Moon()override;

	void Init()override;
	void Update()override;
	void DrawLit()override;

private:
	void Release();
	//地形データ
	std::shared_ptr<KdModelData> m_spMoon = nullptr;
};