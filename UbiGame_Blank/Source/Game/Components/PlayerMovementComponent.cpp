#include "PlayerMovementComponent.h"
#include "GameEngine\GameEngineMain.h"

#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

#include <SFML/Window/Keyboard.hpp>

#include "GameEngine/EntitySystem/Components/PawnPhysicsComponent.h"

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
    float dt = GameEngine::GameEngineMain::GetTimeDelta();
    float playerVelocity = 100.f;
    float jumpVelocity = 20000.f;

    sf::Vector2f wantedVelocity = sf::Vector2f(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        wantedVelocity.x -= playerVelocity * dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        wantedVelocity.x += playerVelocity * dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        //This boolean flag makes sure we react to pressing up only ONCE, rather than to apply this velocity for as long as the button is pressed
        if (!m_wasJumpButtonPressed)
        {
            wantedVelocity.y -= jumpVelocity * dt;
            m_wasJumpButtonPressed = true;
        }
    }
    else
    {
        m_wasJumpButtonPressed = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        wantedVelocity.y += playerVelocity * dt;
    }

    PawnPhysicsComponent* pawnPhys = GetEntity()->GetComponent<PawnPhysicsComponent>();
    if (pawnPhys)
    {
        pawnPhys->SetVelocity(wantedVelocity);
    }


    //Update the entity position with new velocity
    GetEntity()->SetPos(GetEntity()->GetPos() + wantedVelocity);
    GameEngine::AnimationComponent* animComponent = GetEntity()->GetComponent<GameEngine::AnimationComponent>();
    GameEngine::SpriteRenderComponent* spriteRender = GetEntity()->GetComponent<GameEngine::SpriteRenderComponent>();


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {

        spriteRender->SetMirrored(false);

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
        spriteRender->SetMirrored(true);
        if (animComponent != nullptr)
        {
            if (animComponent->GetCurrentAnimation() != GameEngine::EAnimationId::R_walk)
            {
                animComponent->PlayAnim(GameEngine::EAnimationId::R_walk);
            }
        }

    }

}


