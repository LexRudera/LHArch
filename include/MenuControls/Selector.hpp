#ifndef Selector_H
#define Selector_H

#include <MenuControls\ControlBase.hpp>
#include "MenuControls\StaticBox.hpp"
#include "MenuControls\Label.hpp"

namespace lha {
class Selector : public ControlBase {
public:
	/** Default constructor */
	Selector(unsigned int charSize, const sf::Vector2f& size = sf::Vector2f(), const sf::Vector2f& pos = sf::Vector2f(), float rot = 0);
	/** Default destructor */
	virtual ~Selector();

	void tick();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void add(const sf::String& text);

	const sf::String& getSelected() const {
		return m_Selected.getString();
	}
	void setSelected(unsigned int i) {
		m_Selected.setString(m_Entries[i]);
		m_CurrentEntry = i;
	}
protected:
private:
	// Private functions
	void onClick();

	// Data
	StaticBox m_Box;
	std::vector<sf::String> m_Entries;
	unsigned int m_CurrentEntry = 0;
	Label m_Selected;

	sf::ConvexShape m_ArrowRight;
	sf::ConvexShape m_ArrowLeft;
};
}
#endif // Selector_H
