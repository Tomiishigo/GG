#include "Game.hpp"
#include <iostream>

// ===== Testing =====

sf::CircleShape circle(10);

void testRender(sf::RenderWindow *m_window) {
    m_window->draw(circle);
}

void testLoad() {
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(20, 20);
}

void handleKeyMove(sf::Time m_time) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        circle.move(sf::Vector2f(-1 * m_time.asSeconds() * 100, 0));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        circle.move(sf::Vector2f(0, -1 * m_time.asSeconds() * 100));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        circle.move(sf::Vector2f(m_time.asSeconds() * 100, 0));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        circle.move(sf::Vector2f(0, m_time.asSeconds() * 100));
    }
}

void handleMouseMove(sf::Time m_time) {

}


// ============================

void Game::start() {
    load();
    while(!quit) {
        m_time = m_clock.restart(); // resetTimer();

        handleInputs();
        update();
        render();
    }
    close();
}

void Game::load() {
    m_window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "LL");
    
}

void Game::handleInputs() {
    sf::Event event;
    while(m_window.pollEvent(event)) {
        switch(event.type) {
            case sf::Event::Closed:
                quit = true;
                break;
            case sf::Event::KeyPressed:

                break;
            default:
                break;
        }
    }

}

void Game::update() {
    handleKeyMove(m_time);
}

void Game::render() {
    m_window.clear();
    testRender(&m_window);
    m_window.display();
}

void Game::close() {
    m_window.close();
}

bool Game::quit = false;

sf::RenderWindow Game::m_window;

sf::Clock Game::m_clock;

sf::Time Game::m_time;

