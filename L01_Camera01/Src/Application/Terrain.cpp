#include "Terrain.h"

Terrain::Terrain()
{

}

Terrain::~Terrain()
{

}

void Terrain::Init()
{
	//地形初期化
	m_spTerrain = std::make_shared<KdModelData>();
	m_spTerrain->Load("Asset/Data/LessonData/Terrain/Terrain.gltf");
}

void Terrain::Update()
{
}

void Terrain::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_spTerrain);
}

void Terrain::Release()
{
	m_spTerrain = nullptr;
}
