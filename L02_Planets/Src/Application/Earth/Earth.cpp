#include "Earth.h"

Earth::Earth()
{

}

Earth::~Earth()
{

}

void Earth::Init()
{
	//地形初期化
	m_spEarth = std::make_shared<KdModelData>();
	m_spEarth->Load("Asset/Data/LessonData/Planets/earth.gltf");
}

void Earth::Update()
{
	//カメラ行列の更新
	{
		//回転行列
		Math::Matrix _mRotate =
			Math::Matrix::CreateRotationY(DirectX::XMConvertToRadians(10));


		//カメラのワールド行列を作成し、
		Math::Matrix _mEarth = (_mRotate);
		//m_spEarth->(_mEarth);
	}

}

void Earth::DrawLit()
{
	//カメラ行列の更新
	
	//回転行列
	Math::Matrix m_mRotate =
	Math::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(10));


	//カメラのワールド行列を作成し、
	Math::Matrix m_mEarth = (m_mRotate);
	//m_spEarth->(_mEarth);
	

	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_spEarth, m_mEarth);
}

void Earth::Release()
{
	m_spEarth = nullptr;
}
