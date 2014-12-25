#ifndef MENU_H
#define MENU_H

#include "Scene.hpp"
#include "MenuControls\Button.hpp"
#include "MenuControls\Image.hpp"
#include "MenuControls\Label.hpp"
#include "MenuControls\Selector.hpp"
#include "MenuControls\StaticBox.hpp"

//---------------------------------------------------------
// The virtual menu class.
// A menu is not just a menu. It's always a specific type
// of menu, like a main menu or options menu.
//---------------------------------------------------------
namespace lha {
class Menu : public Scene {
public:
	/** Default constructor */
	Menu();
	/** Default destructor */
	virtual ~Menu();
	bool buttonReady();
protected:
	void add(ControlBase* obj);
	void tick();
private:
	bool m_ButtonedFrame = false;
};
}
#endif // MENU_H
