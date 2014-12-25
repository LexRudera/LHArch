#ifndef ME_BUTTON_H
#define ME_BUTTON_H

#include <MenuControls/ControlBase.hpp>
#include "MenuControls/Label.hpp"
#include "MenuControls/StaticBox.hpp"
#include "Menu.hpp"

namespace lha {
struct BtnStateStyle;
class Button : public ControlBase {
public:


	Button(Menu* parent,
	       const sf::String& text,
	       const sf::Vector2f& size = sf::Vector2f(50,50),
	       const sf::Vector2f& pos = sf::Vector2f(),
	       float rot = 0);
	virtual ~Button();

	void tick();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	bool loadTexture(const sf::String& strng);
	void setOnClickFunction(MenuEvent Func) {m_OnClick = Func;}

	void setString(const sf::String& t) {m_Text.setString(t); centerText();}
	const sf::String& getString() {return m_Text.getString();}

	void setSize(const sf::Vector2f& i) {m_Btn.setSize(i); centerText();}
	const sf::Vector2f& getSize() {return m_Btn.getSize();}

protected:
	virtual Object* doCopy(Object*);
private:
	void applyState(BtnStateStyle* Style);
	void centerText();

	// Elements of a button
	Label m_Text;
	StaticBox m_Btn;

	// Function Delegates
	MenuEvent m_OnClick = 0;

	// Visual Styles
	BoxStyle* m_IdleStyle = 0;
	BoxStyle* m_DownStyle = 0;
	BoxStyle* m_HoverStyle = 0;
};
}
#endif // ME_BUTTON_H
