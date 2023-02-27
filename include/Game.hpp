#ifndef GAME_HPP
#define GAME_HPP

#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <vector>
#include <math.h>

#define WIN_WIDTH 1080
#define WIN_HEIGHT 720

class TriangleShape : public sf::ConvexShape
{
public:
    explicit TriangleShape(float length)
    {
        m_length = length;
        setPointCount(3);
        setPoint(0, sf::Vector2f(m_length, m_length));
        setPoint(1, sf::Vector2f(0, m_length));
        setPoint(2, sf::Vector2f(m_length / 2, sqrt((3 / 4) * m_length * m_length)));
    }

private:
    float m_length;
};

class Game
{
public:
    static void start();



private:
    static void load();
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