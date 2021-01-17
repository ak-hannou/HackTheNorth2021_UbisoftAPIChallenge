#include "LinkedEntityComponent.h"

#include "GameEngine/GameEngineMain.h"


using namespace Game;

LinkedEntityComponent::LinkedEntityComponent() : m_followedEntity(nullptr), m_offset(sf::Vector2f(0.f, 0.f))
{

}

LinkedEntityComponent::~LinkedEntityComponent()
{

}

void LinkedEntityComponent::Update()
{
	__super::Update();

	if (m_followedEntity)
	{
		GetEntity()->SetPos(m_followedEntity->GetPos() + m_offset);
	}
}