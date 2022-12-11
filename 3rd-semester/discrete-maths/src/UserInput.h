#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <functional>
#include <map>

#include "EntityList.h"

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

	void handleEvent(const sf::Event& event, EntityList& entityList, sf::RenderWindow& window);

private:
	void initializeBindings();
	void initializeActionBindings();

	std::map<sf::Mouse::Button, Action> m_mouseBinding{};
	std::map<Action, std::function<void(EntityList&, sf::RenderWindow&)>> m_actionBinding{};
};

#endif
