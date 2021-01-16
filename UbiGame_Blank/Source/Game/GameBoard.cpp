#include "GameBoard.h"

#include "GameEngine\GameEngineMain.h"

#include "Game/Components/PlayerMovementComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/AnimationComponent.h"



using namespace Game;

GameBoard::GameBoard()
	: m_player(nullptr)
{	
	CreatePlayer();
}


GameBoard::~GameBoard()
{

}

void GameBoard::CreatePlayer() 
{
	m_player = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);

	m_player->SetPos(sf::Vector2f(50.f, 50.f));
	m_player->SetSize(sf::Vector2f(50.f, 50.f));


	//Render
	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
											(m_player->AddComponent<GameEngine::SpriteRenderComponent>());
	
	
	spriteRender->SetFillColor(sf::Color::Transparent); //Before it was red but it would cause an red outline around sprite therefore we change it to transparent
	
	spriteRender->SetTexture(GameEngine::eTexture::Player);

	//Movement
	m_player->AddComponent<PlayerMovementComponent>();
	m_player->AddComponent<GameEngine::AnimationComponent>();


}

void GameBoard::Update()
{	
	
}