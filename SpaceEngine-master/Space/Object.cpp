#include "stdafx.h"
#include "Object.h"


Object::Object() :
	m_Position(0.f, 0.f)
	, m_Rotation(0.f)
	, m_Scale(1.f, 1.f)
	, m_Destroy(0)
	, m_Visible(true)
	, m_Layer(0)
	, m_Tag("UnNamed")
	, m_RotationCenter(0.f, 0.f)
	, m_ScaleCenter(0.f, 0.f)
	, m_Parent(nullptr)
	, m_Radius(0.f)
	, m_isCollision(false)
{
	D3DXMatrixIdentity(&m_wMat);
}


Object::~Object()
{
}

Matrix Object::GetMatrix()
{
	Vec2 RotCenter = Vec2(0, 0);
	Vec2 ScaleCenter = Vec2(0, 0);

	if (m_Tag != "UI")
	{
		RotCenter.x = -Camera::GetInst()->m_Position.x + m_RotationCenter.x;
		RotCenter.y = -Camera::GetInst()->m_Position.y + m_RotationCenter.y;

		ScaleCenter.x = -Camera::GetInst()->m_Position.x + m_ScaleCenter.x;
		ScaleCenter.y = -Camera::GetInst()->m_Position.y + m_ScaleCenter.y;
	}
	D3DXMatrixTransformation2D(&m_wMat, &ScaleCenter, 0, &m_Scale, &RotCenter, m_Rotation, &m_Position);

	if (m_Parent)
		m_wMat *= m_Parent->GetMatrix();

	return m_wMat;
}

void Object::Translate(float x, float y)
{
	m_Position.x += x;
	m_Position.y += y;
}

void Object::SetScale(float x, float y)
{
	m_Scale.x = x;
	m_Scale.y = y;
}

void Object::SetPosition(float x, float y)
{
	m_Position.x = x;
	m_Position.y = y;
}

void Object::SetPosition(Vec2 Pos)
{
	m_Position = Pos;
}

void Object::Rotate(float r)
{
	m_Rotation += r;
}

void Object::SetTag(const std::string tag)
{
	m_Tag = tag;
}

void Object::SetParent(Object* obj)
{
	m_Parent = obj;
}

void Object::SetVertex()
{
	m_Vertex[0].x = cos(m_Rotation) * ((m_Size.x * m_Scale.x) / 2) + sin(m_Rotation) * (m_Size.y * m_Scale.y / 2) + m_Position.x - Camera::GetInst()->m_Position.x;
	m_Vertex[0].y = -(-sin(m_Rotation) * ((m_Size.x * m_Scale.x) / 2) + cos(m_Rotation) * (m_Size.y * m_Scale.y / 2)) + m_Position.y - Camera::GetInst()->m_Position.y;

	m_Vertex[1].x = cos(m_Rotation) * -((m_Size.x * m_Scale.x) / 2) + sin(m_Rotation) * (m_Size.y * m_Scale.y / 2) + m_Position.x - Camera::GetInst()->m_Position.x;
	m_Vertex[1].y = -(-sin(m_Rotation) * -((m_Size.x * m_Scale.x) / 2) + cos(m_Rotation) * (m_Size.y * m_Scale.y / 2)) + m_Position.y - Camera::GetInst()->m_Position.y;

	m_Vertex[2].x = cos(m_Rotation) * -((m_Size.x * m_Scale.x) / 2) + sin(m_Rotation) * -(m_Size.y * m_Scale.y / 2) + m_Position.x - Camera::GetInst()->m_Position.x;
	m_Vertex[2].y = -(-sin(m_Rotation) * -((m_Size.x * m_Scale.x) / 2) + cos(m_Rotation) * -(m_Size.y * m_Scale.y / 2)) + m_Position.y - Camera::GetInst()->m_Position.y;

	m_Vertex[3].x = cos(m_Rotation) * ((m_Size.x * m_Scale.x) / 2) + sin(m_Rotation) * -(m_Size.y * m_Scale.y / 2) + m_Position.x - Camera::GetInst()->m_Position.x;
	m_Vertex[3].y = -(-sin(m_Rotation) * ((m_Size.x * m_Scale.x) / 2) + cos(m_Rotation) * -(m_Size.y * m_Scale.y / 2)) + m_Position.y - Camera::GetInst()->m_Position.y;

	m_Vertex[4].x = cos(m_Rotation) * ((m_Size.x * m_Scale.x) / 2) + sin(m_Rotation) * (m_Size.y * m_Scale.y / 2) + m_Position.x - Camera::GetInst()->m_Position.x;
	m_Vertex[4].y = -(-sin(m_Rotation) * ((m_Size.x * m_Scale.x) / 2) + cos(m_Rotation) * (m_Size.y * m_Scale.y / 2)) + m_Position.y - Camera::GetInst()->m_Position.y;
}

void Object::Update(float deltaTime, float time)
{
}

void Object::Render()
{
}

void Object::OnCollision(Object* other)
{
}