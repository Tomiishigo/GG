#ifndef GAME_HPP
#define GAME_HPP

#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define WIN_WIDTH 1080
#define WIN_HEIGHT 720

class Game
{
public:
    static void start();

private:
    static void load();
    static void resetTimer();
    static void handleInputs();
    static void update();
    static void render();
    static void close();

    static bool quit;
    static sf::RenderWindow m_window;
    static sf::Clock m_clock;
    static sf::Time m_time;
};


#endif // GAME_HPP