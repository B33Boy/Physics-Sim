#include "entity.hpp"


void Entity::draw(sf::RenderWindow& window) const
{
    if (shape_)
        window.draw(*shape_);
}

sf::String Entity::get_name() const { return name_; }

sf::Vector2f Entity::get_pos() const { return pos_; }

sf::Vector2f Entity::get_vel() const { return vel_; }

float Entity::get_mass() const { return mass_; }

bool Entity::is_fixed() const { return fixed_; }

void Entity::set_pos(sf::Vector2f const& pos)
{
    pos_ = pos;
    shape_->setPosition(pos_);
}

void Entity::set_vel(sf::Vector2f const& vel) { vel_ = vel; }

void Entity::set_mass(float mass) { mass_ = mass; }

sf::Vector2f Entity::get_dist(Entity const& other) const
{
    // return sf::Vector2f{ other.get_pos().x - get_pos().x, other.get_pos().y - get_pos().y };
    return other.get_pos() - get_pos();
}