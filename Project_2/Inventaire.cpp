#include "Inventaire.h"
#include<iostream>
#include<functional>

Inventaire::Inventaire(size_t size, const sf::Texture* texture, const sf::Texture* itemSelectedTexture) :
	m_size(size),
	m_background(*texture),
	m_spriteItemSelected(*itemSelectedTexture)
{
	m_background.setTextureRect(sf::IntRect(0, 0, 64, 64));
	m_spriteItemSelected.setTextureRect(sf::IntRect(0, 0, 12, 12));
	m_background.setPosition(0, 86);

}

void Inventaire::draw(sf::RenderWindow& window, bool debugMode)
{
	window.draw(m_background);

	for (int i = 0; i < m_lstItem.size(); i++)
	{
		sf::Vector2f offset = m_background.getPosition() + sf::Vector2f(15, 20);
		if (i == m_selectedItem) {
			m_spriteItemSelected.setPosition(sf::Vector2f((i % 3) * 13 - 2, (i / 3) * 13 - 2) + offset);
			window.draw(m_spriteItemSelected);
		}
		if (m_lstItem[i] != nullptr) {
			if (m_lstItem[i]->getType() != Item::Type::None) {
				m_lstItem[i]->setPosition(sf::Vector2f((i % 3) * 13, (i / 3) * 13) + offset);
				m_lstItem[i]->drawIcon(window, debugMode);
			}
		}
	}
}

bool Inventaire::addItem(Item* item)
{
	for (size_t i = 0; i < m_lstItem.size(); ++i) {
		if (m_lstItem[i] == nullptr) {
			m_lstItem[i] = item;
			return true;
		}
		else if (m_lstItem[i]->getType() == Item::Type::None) {
			m_lstItem[i] = item;
			return true;
		}
	}
	return false;
}

void Inventaire::keypressed(sf::Keyboard::Key keyCode)
{
	if (keyCode == sf::Keyboard::Up) {
		m_selectedItem -= 3;
		if (m_selectedItem < 0) {
			m_selectedItem += 9;
		}
	}
	if (keyCode == sf::Keyboard::Right) {
		m_selectedItem += 1;
		if (m_selectedItem % 3 == 0) {
			m_selectedItem -= 3;
		}
	}
	if (keyCode == sf::Keyboard::Down) {
		m_selectedItem += 3;
		if (m_selectedItem > 8) {
			m_selectedItem -= 9;
		}
	}
	if (keyCode == sf::Keyboard::Left) {
		m_selectedItem -= 1;
		if (m_selectedItem % 3 == 2 || m_selectedItem < 0) {
			m_selectedItem += 3;
		}
	}
	if (keyCode == sf::Keyboard::Space) {
		if (m_lstItem[m_selectedItem] != nullptr) {
			if (m_lstItem[m_selectedItem]->getType() != Item::Type::None) {
				m_lstItem[m_selectedItem]->use(3);
				m_lstItem[m_selectedItem] = nullptr;
			}
		}
	}
}