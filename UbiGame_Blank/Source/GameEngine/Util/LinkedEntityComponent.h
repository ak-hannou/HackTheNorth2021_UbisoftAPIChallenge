#pragma once
#include "GameEngine/EntitySystem/Component.h"
#include "SFML/System/Vector2.hpp"
// #include "GameEngine/GameEngineMain.h"
// #include "GameEngine/EntitySystem/Entity.h" // not sure

class GameEngine::Entity;

namespace Game
{
	class LinkedEntityComponent : public GameEngine::Component 
	{
	public:
		LinkedEntityComponent();
		~LinkedEntityComponent();

		// Set the entity that this component (background) will follow
		void SetFollowedEntity(GameEngine::Entity* entity) { m_followedEntity = entity; }

		// Set offset that will be applied to follow position
		void SetFollowOffset(sf::Vector2f offset) { m_offset = offset; }

		// Called automatically every frame from GameEngine
		virtual void Update() override;

	private:
		GameEngine::Entity* m_followedEntity;
		sf::Vector2f m_offset;
	};
}