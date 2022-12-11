#include "Application.h"

Application::Application()
	: m_window{ sf::RenderWindow{ sf::VideoMode{ 800, 600 }, "assignment" } }
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

		if (event.type == sf::Event::Closed)
			m_window.close();
	}
}

void Application::update(sf::Time deltaTime)
{
}

void Application::render()
{
	m_window.clear(sf::Color{ 20, 20, 30 });

	m_entityList.draw(m_window);

	m_window.display();
}
