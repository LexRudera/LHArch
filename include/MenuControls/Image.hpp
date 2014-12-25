#ifndef MENU_IMAGE_HPP
#define MENU_IMAGE_HPP

#include <MenuControls/ControlBase.hpp>

namespace lha {
class Image : public ControlBase {
public:
	Image(const sf::String& image, const sf::Vector2f& pos = sf::Vector2f(), const sf::Vector2i& size = Image::DefaultSize, float rot = 0);
	virtual ~Image();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	bool loadTexture(const sf::String& strng);

	const sf::Texture* getTexture() {
		return m_Img.getTexture();
	}

	static sf::Vector2i DefaultSize;
protected:
private:
	sf::Sprite m_Img;
};
}
#endif // MENU_IMAGE_HPP
