#include "Background.hpp"
#include "Utilities.hpp"
#include "Core.hpp"

namespace lha {
Background::Background() {
	m_Size = sf::Vector2f(Core::get()->getWindow()->getSize().x, Core::get()->getWindow()->getSize().y);
	//ctor
}

Background::~Background() {
	for (unsigned int i = 0; i< m_BgTextures.size(); i++) {
		delete m_BgTextures[i];
	}
}

void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	for (unsigned int i = 0; i< m_BgTextures.size(); i++) {
		target.draw(*m_BgTextures[i],states);
	}
}

void Background::add(const sf::Texture* tex, const sf::Vector2f& pos, const sf::Vector2f& scl, float rot) {
	sf::Sprite* t = new sf::Sprite(*tex);
	t->setPosition(pos);
	if (scl != sf::Vector2f()) {
		// Heads up: Don't let it scale to the default 0,0,
		// then it's just gonna shrink out of existence.
		// What a bummer that would be.
		t->setScale(scl);
	}
	t->setRotation(rot);
	m_BgTextures.push_back(t);
	// Size update
	if (m_Size.x < pos.x+tex->getSize().x)
		m_Size.x = pos.x+tex->getSize().x;
	if (m_Size.y < pos.y+tex->getSize().y)
		m_Size.y = pos.y+tex->getSize().y;
}
void Background::rearrange(unsigned int from, unsigned int to) {
	std::vector<sf::Sprite*>::iterator it = m_BgTextures.begin();
	sf::Sprite* t = m_BgTextures[from];

	m_BgTextures.erase(it+from);
	if (to >= m_BgTextures.size())
		m_BgTextures.push_back(t);
	else
		m_BgTextures.insert(it+to,t);
}
void Background::remove(int at) {
	m_BgTextures.erase(m_BgTextures.begin() + at);
}

// get to the actual sprite, so you can manupulate (manipulate) it,
// realitve (relative) to the rest of the background.
sf::Sprite* Background::getLayer(int i) {
	return m_BgTextures[i];
}
}
