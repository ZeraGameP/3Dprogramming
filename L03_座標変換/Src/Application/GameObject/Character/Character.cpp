#include "Character.h"

void Character::Init()
{
	if (!m_spPoly)
	{
		m_spPoly = std::make_shared<KdSquarePolygon>();
		m_spPoly->SetMaterial("Asset/Data/LessonData/Character/Hamu.png");
		m_spPoly->SetPivot(KdSquarePolygon::PivotType::Center_Bottom);
	}
}

void Character::Update()
{
	//	右クリックしたら
	if (GetAsyncKeyState(VK_RBUTTON))
	{
		//①マウス位置の取得
		POINT _mousePos;
		GetCursorPos(&_mousePos);
		std::shared_ptr<KdCamera> _spCam = m_wpCamera.lock();
		if (_spCam)
		{
			//②レイの発射方向を求める(_rayDir)
			Math::Vector3 _camPos = _spCam->GetCameraMatrix().Translation();
			Math::Vector3 _rayDir = Math::Vector3::Zero;
			float _rayRange = 1000.0f;
			_spCam->GenerateRayInfoFromClientPos(_mousePos, _camPos, _rayDir, _rayRange);

			//③レイの衝突位置を求める
			const std::shared_ptr<KdGameObject> _spTerrain = m_wpTerrain.lock();
			if (_spTerrain)
			{
				Math::Vector3 _endRayPos = _camPos+(_rayDir*_rayRange);
				KdCollider::RayInfo _rayInfo(KdCollider::TypeGround,_camPos,_endRayPos);

				//実際の当たり判定処理
				std::list<KdCollider::CollisionResult>_results;
				_spTerrain->Intersects(_rayInfo,&_results);

				//結果が１つでも返って来ていたら
				if (_results.size())
				{
					for (KdCollider::CollisionResult result : _results)
					{
						m_TargetPos = result.m_hitPos;
					}
				}
			}
		}
	}

	// キャラクターの移動速度(真似しちゃダメですよ)
	float moveSpd = 0.05f;
	Math::Vector3 nowPos = m_TargetPos;//m_mWorld.Translation();

	Math::Vector3 moveVec = Math::Vector3::Zero;
	if (GetAsyncKeyState('D')) { moveVec.x = 1.0f; }
	if (GetAsyncKeyState('A')) { moveVec.x = -1.0f; }
	if (GetAsyncKeyState('W')) { moveVec.z = 1.0f; }
	if (GetAsyncKeyState('S')) { moveVec.z = -1.0f; }
	moveVec.Normalize();
	moveVec *= moveSpd;
	nowPos += moveVec;

	// キャラクターのワールド行列を創る処理
	m_mWorld = Math::Matrix::CreateTranslation(nowPos);
}

void Character::DrawLit()
{
	if (!m_spPoly) return;

	KdShaderManager::Instance().m_StandardShader.DrawPolygon(*m_spPoly, m_mWorld);
}

void Character::DrawSprite()
{
	//座標変換(3D座標->2D座標)
	Math::Vector3 _pos = GetPos();
	_pos.y += 1.5f;
	Math::Vector3 _res = Math::Vector3::Zero;
	std::shared_ptr<KdCamera> _spCam = m_wpCamera.lock();
	if (_spCam)
	{
		_spCam->ConvertWorldToScreenDetail(_pos, _res);

		KdShaderManager::Instance().m_spriteShader.DrawCircle(_res.x, _res.y, 10, &kRedColor);
	}
	//座標変換(2D座標->3D座標)

}
