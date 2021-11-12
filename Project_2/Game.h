#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Point.h"

#include "Player.h"
#include "Enemy.h"
#include "TileMap.h"
#include "Entity.h"
#include "Ressources.h"

class Game
{
	Point m_screenSize;

	sf::View gameView;
	Ressource m_ressource;
	Player m_player = Player(m_ressource.getPlayerTexture());
	std::vector<Enemy*> m_orc;
	sf::Texture pTexture;
	TileMap m_map;
	std::vector<sf::RectangleShape> listOfElement{ 10 };

public:
	Game(Point screenSize = Point(0, 0));
	void load();
	void update(sf::Time& deltaTime);
	void draw(sf::RenderWindow& window);
	void keypressed(sf::Keyboard::Key keyCode);
};

