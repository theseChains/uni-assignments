#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Event.hpp>

#include <functional>
#include <map>

#include "AdjacencyMatrix.h"
#include "Button.h"
#include "Context.h"
#include "EntityList.h"

class UserInput
{
public:
	enum class Action
	{
		createVertex,
		removeVertex,
		chooseVertexForDistance,
		chooseVertexForNumberOfRoutes,
		changeMatrixNumber,
		getNumberOfRoutes,
		getDistance,

		numberOfActions
	};

	UserInput();

	void handleEvent(const sf::Event& event, Context context);
	void drawButtons(sf::RenderWindow& window);
	void initializeButtons(const sf::Font& font);

private:
	void initializeBindings();
	void initializeActionBindings();

	std::map<sf::Mouse::Button, Action> m_mouseBinding{};
	std::map<sf::Keyboard::Key, Action> m_keyBinding{};
	std::map<Button, Action> m_buttonBinding{};
	std::map<Action, std::function<void(Context)>> m_actionBinding{};
};

#endif
