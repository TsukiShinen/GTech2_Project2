#pragma once
#include "Entity.h"
#include <math.h>
class Sword : public Entity
{
private:
	sf::Vector2f m_rotationPoint {15, 16};
	int m_range = 30;
	float m_damage = 1;
	
	float m_attackSpeed = 0.5f;
	float m_elapsedTime = 0;

	float m_ratio = 180/m_attackSpeed;
	float m_startAngle = 1;

	bool m_hitting = false;

public:
	Sword(const sf::Texture* texture);
	void setAnimation();
	void attack(float angle);
	float& getDamage() { return m_damage; };
	int& getRange() { return m_range; };
	void update(sf::Time, sf::Vector2f, bool);
	bool isHitting() { return m_hitting; }
};
