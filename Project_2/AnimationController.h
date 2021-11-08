#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animation.h"

class AnimationController
{
	std::map < std::string, Animation > m_animations;
	std::string m_animationName;

	size_t m_columns;
	size_t m_tileSizeX;
	size_t m_tileSizeY;

public:
	AnimationController(size_t columns = 16, size_t tileSizeX = 32, size_t tileSizeY = 32) :
		m_columns(columns),
		m_tileSizeX(tileSizeX),
		m_tileSizeY(tileSizeY)
	{

	}

	void setCurrentAnim(std::string anim) { m_animationName; }
	void update(sf::Time deltaTime);
	void changeCurrentAnim(std::string name);
	sf::IntRect getCurrentRect() { return m_animations[m_animationName].getRect(); }
	void addAnimation(std::string name, Animation anim) { m_animations[name] = anim; }
	std::vector<sf::IntRect> getAllRect(std::vector<size_t> lstId);
	std::vector<sf::IntRect> getAllRect(size_t idBegin, size_t idEnd);
};

