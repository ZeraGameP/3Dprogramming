#include "Sun.h"

Sun::Sun()
{

}

Sun::~Sun()
{

}

void Sun::Init()
{
	//地形初期化
	m_spSun = std::make_shared<KdModelData>();
	m_spSun->Load("Asset/Data/LessonData/Planets/sun.gltf");
}

void Sun::Update()
{
}

void Sun::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_spSun);
}

void Sun::Release()
{
	m_spSun = nullptr;
}
