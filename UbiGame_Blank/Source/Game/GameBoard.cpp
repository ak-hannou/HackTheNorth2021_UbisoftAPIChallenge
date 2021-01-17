#include "GameBoard.h"

#include "GameEngine\GameEngineMain.h"

#include "Game/Components/PlayerMovementComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/AnimationComponent.h"
#include "GameEngine/Util/PlayerCameraComponent.h"
#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"
#include "GameEngine/EntitySystem/Components/PawnPhysicsComponent.h"


using namespace Game;

GameBoard::GameBoard()
	: m_player(nullptr), m_text(nullptr)
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

	m_player->SetPos(sf::Vector2f(50.f, 100.f));
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



	m_text = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_text);

	m_text->SetPos(sf::Vector2f(50.f, 100.f));
	m_text->SetSize(sf::Vector2f(50.f, 50.f));

	GameEngine::TextRenderComponent* text = m_text->AddComponent<GameEngine::TextRenderComponent>();

	text->SetFont("Good Mood.ttf");
	text->SetFillColor(sf::Color::Transparent);
	text->SetColor(sf::Color::White);
	text->SetString("This ... is a COOL GAME");
	text->SetCharacterSizePixels(100);

	

	m_player->AddComponent<PawnPhysicsComponent>();



	m_floor = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_floor);

	m_floor->SetPos(sf::Vector2f(1300.f, 440.f));
	m_floor->SetSize(sf::Vector2f(6840.f, 10.f));

	GameEngine::RenderComponent* floorRender = m_floor->AddComponent<GameEngine::RenderComponent>();

	floorRender->SetFillColor(sf::Color::Transparent);

	m_floor->AddComponent<GameEngine::CollidablePhysicsComponent>();



	m_bridge = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_bridge);

	m_bridge->SetPos(sf::Vector2f(1240.f, 430.f));
	m_bridge->SetSize(sf::Vector2f(200.f, 30.f));

	GameEngine::RenderComponent* bridgeRender = m_bridge->AddComponent<GameEngine::RenderComponent>();

	bridgeRender->SetFillColor(sf::Color::Transparent);

	m_bridge->AddComponent<GameEngine::CollidablePhysicsComponent>();


	
	m_penguin = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_penguin);

	m_penguin->SetPos(sf::Vector2f(740.f, 160.f));
	m_penguin->SetSize(sf::Vector2f(1200.f, 180.f));

	GameEngine::SpriteRenderComponent* penguinRender = static_cast<GameEngine::SpriteRenderComponent*>
		(m_penguin->AddComponent<GameEngine::SpriteRenderComponent>());

	penguinRender->SetFillColor(sf::Color::Transparent);

	penguinRender->SetTexture(GameEngine::eTexture::penguin);



}

void GameBoard::CreateBackground() 
{
	GameEngine::Entity* background = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(background);
	background->SetPos(sf::Vector2f(100.f, 250.f));
	background->SetSize(sf::Vector2f(1500.f, 750.f));
	GameEngine::SpriteRenderComponent* render = static_cast<GameEngine::SpriteRenderComponent*>(background->AddComponent<GameEngine::SpriteRenderComponent>());
	render->SetTexture(GameEngine::eTexture::forestBackground); 
	render->SetFillColor(sf::Color::Transparent);
	render->SetZLevel(-2);

	GameEngine::Entity* background2 = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(background2);
	background2->SetPos(sf::Vector2f(1300.f, 250.f));
	background2->SetSize(sf::Vector2f(1500.f, 750.f));
	GameEngine::SpriteRenderComponent* render2 = static_cast<GameEngine::SpriteRenderComponent*>(background2->AddComponent<GameEngine::SpriteRenderComponent>());
	render2->SetTexture(GameEngine::eTexture::forestBackground);
	render2->SetFillColor(sf::Color::Transparent);
	render2->SetZLevel(-2);

	GameEngine::Entity* background3 = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(background3);
	background3->SetPos(sf::Vector2f(2700.f, 250.f));
	background3->SetSize(sf::Vector2f(1500.f, 750.f));
	GameEngine::SpriteRenderComponent* render3 = static_cast<GameEngine::SpriteRenderComponent*>(background3->AddComponent<GameEngine::SpriteRenderComponent>());
	render3->SetTexture(GameEngine::eTexture::forestBackground);
	render3->SetFillColor(sf::Color::Transparent);
	render3->SetZLevel(-2);

	GameEngine::Entity* background4 = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(background4);
	background4->SetPos(sf::Vector2f(4100.f, 250.f));
	background4->SetSize(sf::Vector2f(1500.f, 750.f));
	GameEngine::SpriteRenderComponent* render4 = static_cast<GameEngine::SpriteRenderComponent*>(background4->AddComponent<GameEngine::SpriteRenderComponent>());
	render4->SetTexture(GameEngine::eTexture::forestBackground);
	render4->SetFillColor(sf::Color::Transparent);
	render4->SetZLevel(-2);

	GameEngine::Entity* background5 = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(background5);
	background5->SetPos(sf::Vector2f(1250.f, 390.f));
	background5->SetSize(sf::Vector2f(500.f, 200.f));
	GameEngine::SpriteRenderComponent* render5 = static_cast<GameEngine::SpriteRenderComponent*>(background5->AddComponent<GameEngine::SpriteRenderComponent>());
	render5->SetTexture(GameEngine::eTexture::bridge);
	render5->SetFillColor(sf::Color::Transparent);
	render5->SetZLevel(-1);

	GameEngine::Entity* background6 = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(background6);
	background6->SetPos(sf::Vector2f(4790.f, 390.f));
	background6->SetSize(sf::Vector2f(500.f, 200.f));
	GameEngine::SpriteRenderComponent* render6 = static_cast<GameEngine::SpriteRenderComponent*>(background6->AddComponent<GameEngine::SpriteRenderComponent>());
	render6->SetTexture(GameEngine::eTexture::brokenBridge);
	render6->SetFillColor(sf::Color::Transparent);
	render6->SetZLevel(-1);

	GameEngine::Entity* background7 = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(background7);
	background7->SetPos(sf::Vector2f(100.f, 390.f));
	background7->SetSize(sf::Vector2f(200.f, 50.f));
	GameEngine::SpriteRenderComponent* render7 = static_cast<GameEngine::SpriteRenderComponent*>(background7->AddComponent<GameEngine::SpriteRenderComponent>());
	render7->SetTexture(GameEngine::eTexture::berry);
	render7->SetFillColor(sf::Color::Transparent);
	render7->SetZLevel(-1);

	GameEngine::Entity* background8 = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(background8);
	background8->SetPos(sf::Vector2f(700.f, 340.f));
	background8->SetSize(sf::Vector2f(200.f, 50.f));
	GameEngine::SpriteRenderComponent* render8 = static_cast<GameEngine::SpriteRenderComponent*>(background8->AddComponent<GameEngine::SpriteRenderComponent>());
	render8->SetTexture(GameEngine::eTexture::berry);
	render8->SetFillColor(sf::Color::Transparent);
	render8->SetZLevel(-1);

	GameEngine::Entity* background9 = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(background9);
	background9->SetPos(sf::Vector2f(1500.f, 370.f));
	background9->SetSize(sf::Vector2f(200.f, 50.f));
	GameEngine::SpriteRenderComponent* render9 = static_cast<GameEngine::SpriteRenderComponent*>(background9->AddComponent<GameEngine::SpriteRenderComponent>());
	render9->SetTexture(GameEngine::eTexture::berry);
	render9->SetFillColor(sf::Color::Transparent);
	render9->SetZLevel(-1);

	GameEngine::Entity* background10 = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(background10);
	background10->SetPos(sf::Vector2f(2200.f, 390.f));
	background10->SetSize(sf::Vector2f(200.f, 50.f));
	GameEngine::SpriteRenderComponent* render10 = static_cast<GameEngine::SpriteRenderComponent*>(background10->AddComponent<GameEngine::SpriteRenderComponent>());
	render10->SetTexture(GameEngine::eTexture::berry);
	render10->SetFillColor(sf::Color::Transparent);
	render10->SetZLevel(-1);
}


void GameBoard::Update()
{	
	if (GameEngine::GameEngineMain::GetGameTime() >= 60) {

		m_black = new GameEngine::Entity();
		GameEngine::GameEngineMain::GetInstance()->AddEntity(m_black);

		m_black->SetPos(sf::Vector2f(0, 0));
		m_black->SetSize(sf::Vector2f(10000.f, 10000.f));

		GameEngine::RenderComponent* blackRender = m_black->AddComponent<GameEngine::RenderComponent>();

		blackRender->SetFillColor(sf::Color::Black);
	}
}