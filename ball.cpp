#include <SFML/Graphics.hpp>

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Retro Bouncing Ball Game");

    // Initialize the ball
    sf::CircleShape ball(10.0f);
    ball.setFillColor(sf::Color::Red);
    sf::Vector2f ballVelocity(0.1f, 0.1f);

    // Game loop
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update game state
        sf::Vector2f position = ball.getPosition();
        if (position.x < 0 || position.x > 780) ballVelocity.x = -ballVelocity.x;
        if (position.y < 0 || position.y > 580) ballVelocity.y = -ballVelocity.y;
        ball.move(ballVelocity);

        // Render
        window.clear();
        window.draw(ball);
        window.display();
    }

    return 0;
}
