#ifndef WORLD_HPP
#define WORLD_HPP


#include <SFML/Graphics.hpp>

#include <vector>

#include "entity.hpp"

struct WorldParams
{
    const float G{ 6.6743e-11 };
    const float deltaTime{ .04f };
};

class PhysicsWorld
{
public:

    PhysicsWorld(WorldParams const& params) : G_(params.G), deltaTime_(params.deltaTime) {}

    // void InsertEntities(Entity const& entity);
    void InsertEntities(Entity&& entity);

    void UpdateEntities();
    void DrawEntities(sf::RenderWindow& window) const;

private:
    std::vector<Entity> entities{};

    const float G_;
    const float deltaTime_;
};


#endif