#include "Collision.h"



void Collision::checkCollision(std::vector<Ball*>& balls)
{
    for (int i = 0; i < balls.size(); i++)
    {
        for (int j = i + 1; j < balls.size(); j++)
        {
            Ball* a = balls[i];
            Ball* b = balls[j];

            // Direction from ball A to ball B
            sf::Vector2f normal = b->midpoint - a->midpoint;

            float distanceSquared =
                normal.x * normal.x +
                normal.y * normal.y;

            float radiusSum = a->radius + b->radius;

            if (distanceSquared < radiusSum * radiusSum)
            {
                float distance = std::sqrt(distanceSquared);

                // Avoid divide by zero if balls are exactly at same position
                if (distance == 0.0f)
                {
                    normal = sf::Vector2f(1.0f, 0.0f);
                    distance = 1.0f;
                }
                else
                {
                    // Normalize collision direction
                    normal.x /= distance;
                    normal.y /= distance;
                }

                // Relative velocity
                sf::Vector2f relativeVelocity = b->velocity - a->velocity;

                // How fast they are moving along the collision normal
                float velocityAlongNormal =
                    relativeVelocity.x * normal.x +
                    relativeVelocity.y * normal.y;

                // If they are already moving away, don't apply impulse
                if (velocityAlongNormal > 0)
                    continue;

                // Bounciness
                // 1.0 = perfectly elastic
                // 0.8 = loses some energy
                // 0.0 = no bounce
                float restitution = 0.8f;

                // Masses
                float massA = a->mass;
                float massB = b->mass;

                float inverseMassA = 1.0f / massA;
                float inverseMassB = 1.0f / massB;

                // Impulse scalar
                float impulseMagnitude =
                    -(1.0f + restitution) * velocityAlongNormal /
                    (inverseMassA + inverseMassB);

                // Impulse vector
                sf::Vector2f impulse = impulseMagnitude * normal;

                // Apply impulse
                a->velocity -= inverseMassA * impulse;
                b->velocity += inverseMassB * impulse;

                // Positional correction to stop balls sticking together
                float penetration = radiusSum - distance;

                float percent = 0.8f; // correction strength
                float slop = 0.01f;   // small allowed overlap

                sf::Vector2f correction =
                    std::max(penetration - slop, 0.0f) /
                    (inverseMassA + inverseMassB) *
                    percent *
                    normal;

                a->midpoint -= inverseMassA * correction;
                b->midpoint += inverseMassB * correction;
            }
        }
    }
}