#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <math.h>
#include <vector>
#include <memory>

#include "world.hpp"
#include "entity.hpp"



int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 1000), "Physics Sim");
    window.setFramerateLimit(60);

    WorldParams params{};
    PhysicsWorld world{ params };

    constexpr int NUM_PARTICLES{ 40 };

    world.InsertEntities(Entity{
        "Source0",
        {800.0f, 300.0f},
        {.0f, .0f},
        50000,
        std::make_unique<sf::CircleShape>(30.0f)
        });

    world.InsertEntities(Entity{
        "Source1",
        {400.0f, 500.0f},
        {1.0f, .01f},
        2000,
        std::make_unique<sf::CircleShape>(20.0f)
        });

    world.InsertEntities(Entity{
        "Source2",
        {1200.0f, 500.0f},
        {-1.0f, -.01f},
        2000,
        std::make_unique<sf::CircleShape>(20.0f)
        });

    for (int i = 0; i < NUM_PARTICLES; i++)
    {
        world.InsertEntities(Entity{
            std::to_string(i),
            {600.0f, 700.0f},
            {.05f, static_cast<float>(0.2f + (0.1f / NUM_PARTICLES) * i)},
            0,
            std::make_unique<sf::CircleShape>(4.0f)
            });
    }


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

        window.clear();

        world.UpdateEntities();
        world.DrawEntities(window);

        window.display();
    }

    return 0;
}