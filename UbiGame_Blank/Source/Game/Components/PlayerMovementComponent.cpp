#include "PlayerMovementComponent.h"
#include "GameEngine\GameEngineMain.h"

#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

#include <SFML/Window/Keyboard.hpp>

using namespace Game;

PlayerMovementComponent::PlayerMovementComponent()
	: m_lastFaceIndex(0)
	, m_wasFaceSwapButtonPressed(false)
	, m_animComponent(nullptr)
{
	
}


PlayerMovementComponent::~PlayerMovementComponent()
{

}

void PlayerMovementComponent::OnAddToWorld()
{
	__super::OnAddToWorld();
	m_animComponent = GetEntity()->GetComponent<GameEngine::AnimationComponent>();
}

void PlayerMovementComponent::Update()
{
	__super::Update();

	//Grabs how much time has passed since the last Update() call
	float dt = GameEngine::GameEngineMain::GetTimeDelta();

	//by default the wanted velocity is 0
	sf::Vector2f wantedVel = sf::Vector2f(0.f, 0.f);
	//player Velocity is applied when we have some input (for the time being let's make it 10pixels a second)
	float playerVel = 200.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		wantedVel.x -= playerVel * dt;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		wantedVel.x += playerVel * dt;
	}
	
	//int maxFaces = 7;


	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		//Button is not pressed now, but it was pressed last fame, which means it just has been released
		/*if (m_wasFaceSwapButtonPressed)
		{
			m_lastFaceIndex++;
			if (m_lastFaceIndex >= maxFaces)
				m_lastFaceIndex = 0;

			GameEngine::SpriteRenderComponent* spriteRender = GetEntity()->GetComponent<GameEngine::SpriteRenderComponent>();
			if (spriteRender)
			{
				spriteRender->SetTileIndex(sf::Vector2i(m_lastFaceIndex, 0));
			}*/
			
			


			/*GameEngine::AnimationComponent* animComponent = GetEntity()->GetComponent<GameEngine::AnimationComponent>();
			if (animComponent)
			{
				animComponent->SetIsLooping(false);

				//Check if animation is already playing, make sure to stop!
				// Render component has mirrors
				//set scale to 1,1,-1
				animComponent->PlayAnim(GameEngine::EAnimationId::PlayerWink);
			}

		}
		m_wasFaceSwapButtonPressed = false;
	}*/

	GameEngine::AnimationComponent* animComponent = GetEntity()->GetComponent<GameEngine::AnimationComponent>();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		
			
			if (animComponent)
			{
				
				if (animComponent->GetCurrentAnimation() != GameEngine::EAnimationId::R_walk)
				{
					animComponent->PlayAnim(GameEngine::EAnimationId::R_walk);
				}



				
			}

	}
	else if (animComponent->GetCurrentAnimation() != GameEngine::EAnimationId::Idle)
	{
		animComponent->PlayAnim(GameEngine::EAnimationId::Idle);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
	
	}
	

	//Update the entity position with new velocity
	GetEntity()->SetPos(GetEntity()->GetPos() + wantedVel);

}