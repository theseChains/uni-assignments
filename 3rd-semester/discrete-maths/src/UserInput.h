#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <SFML/Window/Event.hpp>

#include <map>

class UserInput
{
public:
	enum class Action
	{
		createVertex,
		chooseVertex,

		numberOfActions
	};

	UserInput();

	void handleEvent(const sf::Event& event);

private:
	void initializeBindings();

	std::map<sf::Mouse::Button, Action> m_mouseBinding{};
	std::map<sf::Keyboard::Key, Action> m_keyboardBinding{};
};

#endif
