#ifndef INPUT_H
#define INPUT_H

#include "Core.hpp"


typedef sf::Keyboard::Key Key;
typedef sf::Mouse::Button Button;
namespace lha {
class InputManager {
public:
	InputManager(Core* parent);
	virtual ~InputManager();

	void processInput(const sf::Event& event);
	void clear();

	// Keyboard
	bool isKeyPressed(const sf::Keyboard::Key& key) {
		return m_keysPressed[key];
	}
	bool isKeyDown(const sf::Keyboard::Key& key) {
		return m_keysDown[key];
	}
	bool isKeyUp(const sf::Keyboard::Key& key) {
		return m_keysUp[key];
	}
	// Mouse
	bool isButtonPressed(const sf::Mouse::Button& key) {
		return m_buttonsPressed[key];
	}
	bool isButtonDown(const sf::Mouse::Button& key) {
		return m_buttonsDown[key];
	}
	bool isButtonUp(const sf::Mouse::Button& key) {
		return m_buttonsUp[key];
	}
	sf::Vector2i getMousePos() {
		return sf::Mouse::getPosition(*m_Root->getWindow());
	}
	sf::Vector2i getAbsoluteMousePos() {
		return sf::Mouse::getPosition();
	}
protected:
private:
	// Keyboard
	bool m_keysPressed[sf::Keyboard::Key::KeyCount];
	bool m_keysDown[sf::Keyboard::Key::KeyCount];
	bool m_keysUp[sf::Keyboard::Key::KeyCount];
	// Mouse
	bool m_buttonsPressed[sf::Mouse::Button::ButtonCount];
	bool m_buttonsDown[sf::Mouse::Button::ButtonCount];
	bool m_buttonsUp[sf::Mouse::Button::ButtonCount];

	Core* m_Root;
};
}

#endif // INPUT_H
