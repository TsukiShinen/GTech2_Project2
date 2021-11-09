#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#include "AnimationController.h"

class Player 
{
private:
	float _speed = 30.f;
	sf::Vector2f _direction {0.f, 0.f};
	bool _debug = false;
	//std::vector<sf::IntRect> _anim;
	sf::Texture _texture;
	AnimationController _animCtrl;
	sf::Sprite _sprite;
	sf::RectangleShape _hitbox;
	sf::RectangleShape _movebox;
	std::string _directionAnim = "WalkBL";
	int m_mapLevel = 0;
public:
	Player();
	void update(sf::Time, std::vector<sf::FloatRect>&);
	void draw(sf::RenderWindow&);

	int getMapLevel() { return m_mapLevel; }
	void setMapLevel(int level) { m_mapLevel = level; }

	bool collides(sf::FloatRect);
	void changeShowDebug() { _debug = !_debug; }
	void setPosition(sf::Vector2f position) { _sprite.setPosition(position); }
	const sf::Vector2f& getPosition() { return _sprite.getPosition(); }
	void changeSprite();
};

