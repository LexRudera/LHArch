// An object that is to be rendered on the screen.
// Empty and pure virtual. This is not meant to be
// actually made into an object and rendered. It is
// to be derived from as the absolute base class
// of all renderable things.

#ifndef OBJECT_H
#define OBJECT_H

#include <SFML\Graphics.hpp>
namespace lha {
class Object : public sf::Drawable, public sf::Transformable {
public:
	Object();
	Object(const Object& o);

	virtual ~Object();

	Object* copy();
	void doTick();

	sf::Vector2f getPosition() {
		return sf::Transformable::getPosition();
	}
	void getPosition(float* x, float* y) {
		*x = getPosition().x;
		*y = getPosition().y;
	}
	float getRotation() {
		return sf::Transformable::getRotation();
	}
	void getRotation(float* r) {
		*r = sf::Transformable::getRotation();
	}
	void activateLogic() {
		m_Logic = true;
	}
	void deactivateLogic() {
		m_Logic = false;
	}
	int id(){
		return reinterpret_cast<long long>(this);
	}
protected:
	virtual Object* doCopy(Object*) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
	virtual void tick();
private:
	bool m_Logic = true;
};
}
#endif // OBJECT_H
