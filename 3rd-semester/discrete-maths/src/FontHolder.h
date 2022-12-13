#ifndef FONT_HOLDER_H
#define FONT_HOLDER_H

#include <SFML/Graphics/Font.hpp>

#include <cassert>
#include <map>
#include <memory>
#include <string>

#include "FontIdentifiers.h"

class FontHolder
{
private:
	std::map<Fonts::ID, std::unique_ptr<sf::Font>> m_fontMap{};

public:
	void loadFont(Fonts::ID identifier, const std::string& filename);
	sf::Font& getFont(Fonts::ID identifier) const;
};

#endif
