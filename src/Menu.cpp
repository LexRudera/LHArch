#include "Menu.hpp"
#include "Core.hpp"
#include "Utilities.hpp"

namespace lha {
Menu::Menu() {
	//ctor
}

Menu::~Menu() {
	//dtor
}

void Menu::add(ControlBase* obj) {
	m_Objects.push_back(obj);
}

void Menu::tick() {
	m_ButtonedFrame = false;
}

// A bit of explaination may be required. Let's imagine a scenario with two buttons,
// on top of each other. The logic loop will go through each of them, and pass through this test.
// Only the first button gets to be executed, locking the rest out. It resets each frame.
bool Menu::buttonReady() {
	if (m_ButtonedFrame == false) {
		m_ButtonedFrame = true;
		return true;
	}
	return false;
}
}
