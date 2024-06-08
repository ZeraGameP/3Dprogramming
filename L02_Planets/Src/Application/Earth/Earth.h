#pragma once
class Earth : public KdGameObject
{
public:
	Earth();
	~Earth()override;

	void Init()override;
	void Update()override;
	void DrawLit()override;

private:
	void Release();
	//地形データ
	std::shared_ptr<KdModelData> m_spEarth = nullptr;
};