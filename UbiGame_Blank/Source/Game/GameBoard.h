#pragma once
#include "GameEngine/EntitySystem/Entity.h"

#include <SFML/System/Vector2.hpp>
#include <vector>

namespace Game
{
	//Used for storing and controlling all game related entities, as well as providing an entry point for the "game" side of application	
	class PlayerEntity;	

	class GameBoard
	{
	public:
		GameBoard();
		virtual ~GameBoard();

		void Update();		
		bool IsGameOver() { return false; }

	private:
		void CreatePlayer();
		GameEngine::Entity* m_player;
		GameEngine::Entity* m_text;
		GameEngine::Entity* m_floor;
		GameEngine::Entity* m_bridge;
		GameEngine::Entity* m_penguin;
		GameEngine::Entity* m_black;
		void CreateBackground();
		GameEngine::Entity* background;

	};

}

