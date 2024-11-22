#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <memory>

class Entity
{

public:

    Entity(sf::String const& name, sf::Vector2f const& pos, sf::Vector2f const& vel, float mass, std::unique_ptr<sf::Shape> shape) :
        name_(name),
        pos_(pos),
        vel_(vel),
        mass_(mass),
        shape_(std::move(shape))
    {
        if (vel_.x == 0 && vel_.y == 0)
        {
            fixed_ = true;
            shape_->setPosition(pos_);
            shape_->setFillColor(sf::Color::Cyan);
        }
    }

    void draw(sf::RenderWindow& window) const;

    sf::String get_name() const;
    sf::Vector2f get_pos() const;
    sf::Vector2f get_vel() const;
    float get_mass() const;
    bool is_fixed() const;

    void set_pos(sf::Vector2f const& pos);
    void set_vel(sf::Vector2f const& vel);
    void set_mass(float mass);

    sf::Vector2f get_dist(Entity const& other) const;

private:

    sf::String name_;

    sf::Vector2f pos_;
    sf::Vector2f vel_;

    float mass_;

    std::unique_ptr<sf::Shape> shape_;

    bool fixed_{ false };

};

#endif