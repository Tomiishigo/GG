#include "Game.hpp"

// ===== Testing =====

sf::CircleShape player(20);
TriangleShape t1(30);
TriangleShape t2(30);
TriangleShape t3(30);
TriangleShape t4(30);

void getDistance() {
    return;    
}

void testLoad() {
    player.setPosition(200, 200);
    player.setFillColor(sf::Color::Green);

    t1.setFillColor(sf::Color::Blue);
    t2.setPosition(150, 150);
    t3.setPosition(100, 150);
    t4.setPosition(150, 100);
}

void testRender(sf::RenderWindow *m_window) {
    m_window->draw(player);
    m_window->draw(t1);
    m_window->draw(t2);
    m_window->draw(t3);
    m_window->draw(t4);
}

void handleKeyMove(sf::Time m_time) {
    float speed = 150;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        player.move(sf::Vector2f(-1 * m_time.asSeconds() * speed, 0));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        player.move(sf::Vector2f(0, -1 * m_time.asSeconds() * speed));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player.move(sf::Vector2f(m_time.asSeconds() * speed, 0));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        player.move(sf::Vector2f(0, m_time.asSeconds() * speed));
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
    testLoad();
}

void Game::handleInputs() {
    sf::Event event;
    while(m_window.pollEvent(event)) {
        switch(event.type) {
            case sf::Event::Closed:
                quit = true;
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        quit = true;
                        break;
                    default:
                        break;
                }
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

