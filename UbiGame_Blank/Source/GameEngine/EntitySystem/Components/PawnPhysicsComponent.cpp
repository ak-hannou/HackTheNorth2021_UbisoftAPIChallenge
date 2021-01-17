#include "PawnPhysicsComponent.h"
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/GameEngineMain.h"

using namespace Game;

PawnPhysicsComponent::PawnPhysicsComponent()
    : m_velocity(sf::Vector2f(0.f, 0.f))
    , m_lastPos(sf::Vector2f(0.f, 0.f))
    , m_wantedVelocity(sf::Vector2f(0.f, 0.f))
{

}


PawnPhysicsComponent::~PawnPhysicsComponent()
{

}

void PawnPhysicsComponent::OnAddToWorld()
{
    __super::OnAddToWorld();
    m_lastPos = GetEntity()->GetPos();
}


void PawnPhysicsComponent::Update()
{
    //Get DELTA time from the previous frame
    float dt = GameEngine::GameEngineMain::GetTimeDelta();
    //Log the current Y, before anything happens
    float currentY = GetEntity()->GetPos().y;

    //This is our A
    float gForce = 250.f;

    if (dt > 0.f)
    {
        float lerpTime = 1.2f;
        //Set the current velocity as a lerp of last one towards wanted. Lerp time is multiplied by DT, since we apply the given change in dt, same as vel.
        m_velocity.x = Lerp(m_velocity.x, m_wantedVelocity.x, lerpTime * dt);
        m_velocity.y += m_wantedVelocity.y;

        //Accelerate Y of our velocity by gravity in time
        m_velocity.y += gForce * dt;

        //V = Dx / Dt => Dx = V * Dt
        sf::Vector2f deltaVelocity = dt * m_velocity;
        GetEntity()->SetPos(GetEntity()->GetPos() + deltaVelocity);
    }

    __super::Update();

    //Determine deltY AFTER the collision update, so that it indicates actual distance that entity travelled
    float deltaY = GetEntity()->GetPos().y - currentY;
    if (dt > 0.f)
    {
        //Our actual velocity is that position different in time:
        m_velocity.y = deltaY / dt;
    }
}
float PawnPhysicsComponent::Lerp(float a, float b, float f)
{
    return (a * (1.0f - f)) + (b * f);
}