#include "UserInput.h"

UserInput::UserInput()
{
	m_mouseBinding[sf::Mouse::Left] = Action::createVertex;
	m_mouseBinding[sf::Mouse::Right] = Action::chooseVertex;

	m_keyboardBinding[sf::Keyboard::Num0] = Action::enterZero;
	m_keyboardBinding[sf::Keyboard::Num1] = Action::enterOne;
	m_keyboardBinding[sf::Keyboard::Num2] = Action::enterTwo;
	m_keyboardBinding[sf::Keyboard::Num3] = Action::enterThree;
	m_keyboardBinding[sf::Keyboard::Num4] = Action::enterFour;
	m_keyboardBinding[sf::Keyboard::Num5] = Action::enterFive;
	m_keyboardBinding[sf::Keyboard::Num6] = Action::enterSix;
	m_keyboardBinding[sf::Keyboard::Num7] = Action::enterSeven;
	m_keyboardBinding[sf::Keyboard::Num8] = Action::enterEight;
	m_keyboardBinding[sf::Keyboard::Num9] = Action::enterNine;

	m_keyboardBinding[sf::Keyboard::Enter] = Action::finishEnteringNumber;
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
