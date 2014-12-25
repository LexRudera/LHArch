#include "InputManager.hpp"
#include "Utilities.hpp"

namespace lha {
InputManager::InputManager(Core* parent) {
	// set the root core
	m_Root = parent;

	// Clear the arrays, just to be safe.
	for (unsigned int i = 0; i < sf::Keyboard::Key::KeyCount; i++) {
		m_keysPressed[i] = false;
		m_keysDown[i] = false;
		m_keysUp[i] = false;
	}
	for (unsigned int i = 0; i < sf::Mouse::Button::ButtonCount; i++) {
		m_buttonsPressed[i] = false;
		m_buttonsDown[i] = false;
		m_buttonsUp[i] = false;
	}
}
InputManager::~InputManager() {

}

//Array clearing
void InputManager::clear() {
	// Reset KeysDown and KeysUp, since there are only supposed
	// to be true for a single tick. Run this before the eventloop
	// Keyboard
	for (unsigned int i = 0; i < sf::Keyboard::Key::KeyCount; i++) {
		m_keysDown[i] = false;
		m_keysUp[i] = false;
	}
	// Mouse
	for (unsigned int i = 0; i < sf::Mouse::Button::ButtonCount; i++) {
		m_buttonsDown[i] = false;
		m_buttonsUp[i] = false;
	}
}

// Input processing.
// Called each event pull.
void InputManager::processInput(const sf::Event& event) {
	switch (event.type) {
	case sf::Event::TextEntered:{
			Log("TextEntered Message");
			break;
		}
	case sf::Event::LostFocus:{
			Log("GainedFocus Message");
			break;
		}
	case sf::Event::GainedFocus:{
			Log("GainedFocus Message");
			break;
		}
	case sf::Event::Resized:{
			Log("Resized Message");
			break;
		}
	case sf::Event::Closed:{
			Log("Closed Message");
			break;
		}
	case sf::Event::KeyPressed: {
			// Let's exploit the fact that an enumerated value,
			// actually is a numeric value.
			m_keysPressed[event.key.code] = true;
			m_keysDown[event.key.code] = true;
			break; // Don't forget your darn breaks!
		}
	case sf::Event::KeyReleased: {
			m_keysPressed[event.key.code] = false;
			m_keysUp[event.key.code] = true;
			break;
		}
	case sf::Event::EventType::MouseButtonPressed: {
			m_buttonsPressed[event.mouseButton.button] = true;
			m_buttonsDown[event.mouseButton.button] = true;
			break;
		}
	case sf::Event::EventType::MouseButtonReleased: {
			m_buttonsPressed[event.mouseButton.button] = false;
			m_buttonsUp[event.mouseButton.button] = true;
			break;
		}
	default: {
		Log("Received faulty input event!");
		break;
	}
	}
}
}
