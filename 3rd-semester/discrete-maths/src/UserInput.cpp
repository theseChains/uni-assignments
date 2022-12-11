#include "UserInput.h"

UserInput::UserInput()
{
	m_mouseBinding[sf::Mouse::Left] = Action::createVertex;
	m_mouseBinding[sf::Mouse::Right] = Action::chooseVertex;
}

void hanldeEvent(const sf::Event& event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
	}
}

void UserInput::initializeBindings()
{
	m_mouseBinding[sf::Mouse::Left] = Action::createVertex;
	m_mouseBinding[sf::Mouse::Right] = Action::chooseVertex;
}
