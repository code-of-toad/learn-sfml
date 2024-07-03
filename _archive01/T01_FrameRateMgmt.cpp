#include "T01_FrameRateMgmt.hpp"

void FrameRateMgmt_FixedTimeStep() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Fixed Time Step Example");

    sf::Clock clock;
    const sf::Time timePerFrame = sf::seconds(1.f/60.f);  // 60 FPS
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Green);
    float speed = 100.f; // 100 pixels per second

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }

            timeSinceLastUpdate += clock.restart();

            while (timeSinceLastUpdate > timePerFrame) {
                timeSinceLastUpdate -= timePerFrame;
                // EXPLANATION:
                // ------------
                // 1. Process events.
                // 2. Update game logic exactly 60 times per second.
                // ------------
            }

            window.clear();
            // Draw your game scene here.
            // window.draw(elt1);
            // window.draw(elt2);
            // window.draw(elt3);
            window.display();
        }
    }
}

void FrameRateMgmt_VariableTimeStep() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Delta Time Example");

    float speed = 100.f; // 100 pixels per second
    sf::Clock clock;

    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
        }

        sf::Time deltaTime = clock.restart();
        float moveAmount = speed * deltaTime.asSeconds();

        // Update the shape's position
        shape.move(moveAmount, 0); // Move right

        window.clear();
        window.draw(shape);
        window.display();
    }
}