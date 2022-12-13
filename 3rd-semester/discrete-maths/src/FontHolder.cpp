#include "FontHolder.h"

#include <exception>

void FontHolder::loadFont(Fonts::ID identifier, const std::string& filename)
{
	auto font{ std::make_unique<sf::Font>() };
	if (!font->loadFromFile(filename))
	{
		throw std::runtime_error{ "FontHolder::load - failed to load " + filename };
	}

	auto inserted{ m_fontMap.insert(std::make_pair(identifier, std::move(font))) };
	// don't allow inserting the same resource twice
	assert(inserted.second && "FontHolder::load - failed to insert font into map\n");
}

sf::Font& FontHolder::getFont(Fonts::ID identifier) const
{
	auto found{ m_fontMap.find(identifier) };
	return *found->second;
}
