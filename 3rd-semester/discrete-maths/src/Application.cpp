#include "Application.h"
#include "Config.h"

Application::Application()
	: m_window{ sf::RenderWindow{ sf::VideoMode{ constants::windowWidth, constants::windowHeight },
		"assignment" } }
	, m_userInput{}
{
	m_window.setVerticalSyncEnabled(true);
}

void Application::run()
{
	sf::Clock clock{};
	while (m_window.isOpen())
	{
		processInput();
		update(clock.restart());
		render();
	}
}

void Application::processInput()
{
	sf::Event event{};
	while (m_window.pollEvent(event))
	{
		m_userInput.handleEvent(event, m_entityList, m_window);

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			m_window.close();

		if (event.type == sf::Event::Closed)
			m_window.close();
	}
}

void Application::update([[maybe_unused]] sf::Time deltaTime)
{
}

void Application::render()
{
	m_window.clear(sf::Color{ background::red, background::green, background::blue });

	m_entityList.draw(m_window);
	m_adjacencyMatrix.draw(m_window);

	m_window.display();
}
