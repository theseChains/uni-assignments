#include "UserInput.h"
#include "UserInputStructs.h"

UserInput::UserInput()
{
	initializeBindings();
	initializeActionBindings();
}

void UserInput::handleEvent(const sf::Event& event, Context context)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		// check for our designated mouse buttons
		auto found{ m_mouseBinding.find(event.mouseButton.button) };
		if (found != m_mouseBinding.end())
		{
			m_actionBinding[found->second](context);
		}
	}
	else if (event.type == sf::Event::KeyPressed)
	{
		auto found{ m_keyBinding.find(event.key.code) };
		if (found != m_keyBinding.end())
		{
			m_actionBinding[found->second](context);
		}
	}
}

void UserInput::initializeBindings()
{
	m_mouseBinding[sf::Mouse::Left] = Action::changeMatrixNumber;

	m_keyBinding[sf::Keyboard::C] = Action::createVertex;
	m_keyBinding[sf::Keyboard::R] = Action::removeVertex;
	m_keyBinding[sf::Keyboard::D] = Action::chooseVertexForDistance;
	m_keyBinding[sf::Keyboard::N] = Action::chooseVertexForNumberOfRoutes;
}

void UserInput::initializeActionBindings()
{
	m_actionBinding[Action::createVertex] = VertexCreator{};
	m_actionBinding[Action::removeVertex] = VertexRemover{};
	m_actionBinding[Action::chooseVertexForNumberOfRoutes] = VertexChooserForRoutes{};
	m_actionBinding[Action::chooseVertexForDistance] = VertexChooserForDistance{};

	m_actionBinding[Action::changeMatrixNumber] = MatrixNumberChanger{};
}
