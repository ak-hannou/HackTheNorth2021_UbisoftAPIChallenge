#include "GameBoard.h"

#include "GameEngine\GameEngineMain.h"

#include "Game/Components/PlayerMovementComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/AnimationComponent.h"
//#include "GameEngine/Util/LinkedEntityComponent.h"
#include "GameEngine/Util/PlayerCameraComponent.h"



using namespace Game;

GameBoard::GameBoard()
	: m_player(nullptr)
{	
	CreatePlayer();
	CreateBackground();
}


GameBoard::~GameBoard()
{

}

void GameBoard::CreatePlayer() 
{
	m_player = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);

	m_player->SetPos(sf::Vector2f(50.f, 300.f));
	m_player->SetSize(sf::Vector2f(50.f, 50.f));


	//Render
	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
											(m_player->AddComponent<GameEngine::SpriteRenderComponent>());
	
	
	spriteRender->SetFillColor(sf::Color::Transparent); //Before it was red but it would cause an red outline around sprite therefore we change it to transparent
	
	spriteRender->SetTexture(GameEngine::eTexture::Player);

	//Movement
	m_player->AddComponent<PlayerMovementComponent>();
	m_player->AddComponent<GameEngine::AnimationComponent>();

	m_player->AddComponent<PlayerCameraComponent>();
}

void GameBoard::CreateBackground() 
{
	GameEngine::Entity* background = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(background);
	background->SetPos(sf::Vector2f(250.f, 250.f));
	background->SetSize(sf::Vector2f(1000.f, 500.f));
	GameEngine::SpriteRenderComponent* render = static_cast<GameEngine::SpriteRenderComponent*>(background->AddComponent<GameEngine::SpriteRenderComponent>());
	render->SetTexture(GameEngine::eTexture::forestBackground); 
	render->SetFillColor(sf::Color::Transparent);
	render->SetZLevel(-1);

	GameEngine::Entity* background2 = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(background2);
	background2->SetPos(sf::Vector2f(1250.f, 250.f));
	background2->SetSize(sf::Vector2f(1000.f, 500.f));
	GameEngine::SpriteRenderComponent* render2 = static_cast<GameEngine::SpriteRenderComponent*>(background2->AddComponent<GameEngine::SpriteRenderComponent>());
	render2->SetTexture(GameEngine::eTexture::forestBackground);
	render2->SetFillColor(sf::Color::Transparent);
	render2->SetZLevel(-1);

	GameEngine::Entity* background3 = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(background3);
	background3->SetPos(sf::Vector2f(2250.f, 250.f));
	background3->SetSize(sf::Vector2f(1000.f, 500.f));
	GameEngine::SpriteRenderComponent* render3 = static_cast<GameEngine::SpriteRenderComponent*>(background3->AddComponent<GameEngine::SpriteRenderComponent>());
	render3->SetTexture(GameEngine::eTexture::forestBackground);
	render3->SetFillColor(sf::Color::Transparent);
	render3->SetZLevel(-1);

	GameEngine::Entity* background4 = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(background4);
	background4->SetPos(sf::Vector2f(3250.f, 250.f));
	background4->SetSize(sf::Vector2f(1000.f, 500.f));
	GameEngine::SpriteRenderComponent* render4 = static_cast<GameEngine::SpriteRenderComponent*>(background4->AddComponent<GameEngine::SpriteRenderComponent>());
	render4->SetTexture(GameEngine::eTexture::forestBackground);
	render4->SetFillColor(sf::Color::Transparent);
	render4->SetZLevel(-1);

	// Commented out: Only need if want to link the character with the background

	// LinkedEntityComponent* linkedCmp = static_cast<LinkedEntityComponent*>(background->AddComponent<LinkedEntityComponent>());

	// linkedCmp->SetFollowedEntity(m_player); 
	// linkedCmp->SetFollowOffset(sf::Vector2f(0.f, -200.f)); // change this if not level with guy
}


void GameBoard::Update()
{	
	
}