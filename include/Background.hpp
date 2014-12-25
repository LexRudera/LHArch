// A background class
//------------------------------------------------------
// Here you define textures to be used as background
// and you can piece them together like a collage.
// Funky stuph.

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <Object.hpp>

namespace lha {
class Background : public Object {
public:
	Background();
	virtual ~Background();

	void add(const sf::Texture* tex, const sf::Vector2f& pos = sf::Vector2f(), const sf::Vector2f& scale = sf::Vector2f(), float rot = 0);
	void rearrange(unsigned int from, unsigned int to);
	void remove(int at);
	int amount() {
		return m_BgTextures.size();
	}
	sf::Sprite* getLayer(int i);
	sf::Vector2f getSize() {return m_Size;}
protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	std::vector<sf::Sprite*> m_BgTextures;
	sf::Vector2f m_Size;
};
}

#endif // BACKGROUND_H
