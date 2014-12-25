#ifndef CONTROLBASE_H
#define CONTROLBASE_H

#include "Object.hpp"
namespace lha {
class Menu;
typedef void (Menu::* MenuEvent)(); // MenuEvent type definition

class ControlBase : public Object {
public:
	ControlBase();
	virtual ~ControlBase();
	bool isScrolling() {
		return m_Scrolling;
	}
	void isScrolling(bool a) {
		m_Scrolling = a;
	}
protected:
	virtual Object* doCopy(Object*);
	Menu* m_Parent;
private:
	bool m_Scrolling = true;
};
}
#endif // CONTROLBASE_H
