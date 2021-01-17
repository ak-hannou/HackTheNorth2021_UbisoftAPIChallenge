#pragma once
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"

namespace Game
{
    class PawnPhysicsComponent : public GameEngine::CollidablePhysicsComponent
    {
    public:
        PawnPhysicsComponent();
        ~PawnPhysicsComponent();

        virtual void OnAddToWorld() override;
        virtual void Update() override;

        void SetVelocity(sf::Vector2f vel) { m_wantedVelocity = vel; }
        float Lerp(float a, float b, float f);

    private:
        //Velocity that the pawn wants to have
        sf::Vector2f m_wantedVelocity;
        //Current pawn velocity
        sf::Vector2f m_velocity;
        //Position of the pawn in the last frame.
        sf::Vector2f m_lastPos;
    };

}