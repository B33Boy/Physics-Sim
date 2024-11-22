
#include <cmath>
#include "world.hpp"

void PhysicsWorld::InsertEntities(Entity&& entity)
{
    entities.push_back(std::move(entity));
}


void PhysicsWorld::UpdateEntities()
{
    for (auto& entity : entities)
    {
        if (entity.is_fixed()) continue;

        if (entity.get_pos().x < 0 || entity.get_pos().x > 1600)
            entity.set_vel({ -1.0f * entity.get_vel().x, entity.get_vel().y });

        if (entity.get_pos().y < 0 || entity.get_pos().y > 1000)
            entity.set_vel({ entity.get_vel().x, -1.0f * entity.get_vel().y });

        for (auto const& other : entities)
        {
            if (other.get_name() != entity.get_name())
            {
                const auto dist_vec = entity.get_dist(other);
                auto dist = sqrt(dist_vec.x * dist_vec.x + dist_vec.y * dist_vec.y);

                if (dist < 20.0f) dist = 30.0f;

                const auto inverse_dist = 1.f / dist;
                float norm_x = dist_vec.x * inverse_dist;
                float norm_y = dist_vec.y * inverse_dist;

                float inverse_squared_dropoff = inverse_dist * inverse_dist;
                float accel_x = norm_x * other.get_mass() * inverse_squared_dropoff;
                float accel_y = norm_y * other.get_mass() * inverse_squared_dropoff;

                const auto accel = sf::Vector2f{ accel_x, accel_y };

                entity.set_vel(entity.get_vel() + accel * deltaTime_);
                entity.set_pos(entity.get_pos() + entity.get_vel() * deltaTime_);
            }
        }
    }
}

void PhysicsWorld::DrawEntities(sf::RenderWindow& window) const
{
    for (auto const& entity : entities)
    {
        entity.draw(window);
    }
}
