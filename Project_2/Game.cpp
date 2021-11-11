#include "Game.h"
#include "TileMap.h"

Game::Game(Point screenSize)
{
    m_screenSize = screenSize;
}

void Game::load()
{
    m_ressource.load();

    m_map = TileMap("SandBox2.json");
    m_player.setPosition(m_map.getStartingPosition().toVector2());

    for (sf::IntRect* enemyZone : m_map.getEnemySpawn()) {
        m_orc.push_back(new Enemy(enemyZone, m_ressource.getOrcTexture(), m_ressource.getlifeBarTexture()));
    }

    gameView.setCenter(m_player.getPosition());
    gameView.setSize((m_screenSize/4).toVector2());

}

void Game::update(sf::Time& deltaTime)
{
    
    for (Enemy* enemy : m_orc) {
        enemy->update(deltaTime, m_player.getPosition());
    }
    m_map.update(deltaTime);
    m_player.update(deltaTime, m_map.getRectCollision(m_player.getMapLevel()));
    sf::Vector2f cameraPosition = m_player.getPosition();
    if (cameraPosition.y < 75) {
        cameraPosition.y = 75;
    }
    if (cameraPosition.x < 100) {
        cameraPosition.x = 100;
    }
    gameView.setCenter(cameraPosition);

    for (auto& rect : m_map.getRectLevel()) {
        if (m_player.collides(rect.rect)) {
            m_player.setMapLevel(rect.toLevel);
        }
    }

    // Remove dead people
    for (int i = m_orc.size() - 1; i >= 0; --i) {
        if (m_orc[i]->toRemove()) {
            m_orc.erase(m_orc.begin() + i);
        }
    }
}

void Game::draw(sf::RenderWindow& window)
{
    window.setView(gameView);
    m_map.drawBeforePlayer(window, m_player.getMapLevel(), m_debugMode);

    
    m_player.draw(window);
    for (Enemy* enemy : m_orc) {
        enemy->draw(window, m_debugMode);
    }

    m_map.drawAfterPlayer(window, m_player.getMapLevel(), m_debugMode);
}

void Game::keypressed(sf::Keyboard::Key keyCode)
{
    if (keyCode == sf::Keyboard::C) {
        m_debugMode = !m_debugMode;
    }
    if (keyCode == sf::Keyboard::R) {
        m_map = TileMap("SandBox2.json");
    }
    if (keyCode == sf::Keyboard::P) {
        for (Enemy* enemy : m_orc) {
            enemy->takeDamage(2);
        }
    }
}
