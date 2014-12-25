#include "MenuControls/ControlBase.hpp"
namespace lha {
ControlBase::ControlBase() {
	//ctor
}

ControlBase::~ControlBase() {
	//dtor
}

Object* ControlBase::doCopy(Object* o) {
	((ControlBase*)o)->isScrolling(isScrolling());
	return o;
}
}
