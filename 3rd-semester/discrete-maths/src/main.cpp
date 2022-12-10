#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>

int main()
{
	sf::RenderWindow window{ sf::VideoMode{ 800, 600}, "assignment" };
	window.setFramerateLimit(60);

	sf::CircleShape circle{};
	circle.setRadius(100.0f);
	circle.setPosition(10.0f, 10.0f);
	circle.setFillColor(sf::Color::Blue);

	while (window.isOpen())
	{
		sf::Event event{};
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(circle);
		window.display();
	}

	return 0;
}
