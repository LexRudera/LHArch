#include "Object.hpp"
namespace lha {
Object::~Object() {
	//dtor
}

Object::Object() {
	//ctor
}

Object::Object(const Object& o) {
	*this = o;
}

Object* Object::copy() {
	Object* o = doCopy(nullptr);
	o->m_Logic = m_Logic;
	return o;
}


void Object::doTick() {
	if (m_Logic) {
		tick();
	}
}

void Object::tick() {

}
}
