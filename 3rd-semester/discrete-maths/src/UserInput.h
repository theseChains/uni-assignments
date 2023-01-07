#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <functional>
#include <map>

#include "AdjacencyMatrix.h"
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
		getAnswer,

		numberOfActions
	};

	UserInput();

	void handleEvent(const sf::Event& event, Context context);

private:
	void initializeBindings();
	void initializeActionBindings();

	std::map<sf::Mouse::Button, Action> m_mouseBinding{};
	std::map<sf::Keyboard::Key, Action> m_keyBinding{};
	std::map<Action, std::function<void(Context)>> m_actionBinding{};
};

#endif
