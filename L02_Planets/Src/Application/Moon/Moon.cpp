#include "Moon.h"

Moon::Moon()
{

}

Moon::~Moon()
{

}

void Moon::Init()
{
	//地形初期化
	m_spMoon = std::make_shared<KdModelData>();
	m_spMoon->Load("Asset/Data/LessonData/Planets/moon.gltf");
}

void Moon::Update()
{
}

void Moon::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_spMoon);
}

void Moon::Release()
{
	m_spMoon = nullptr;
}
