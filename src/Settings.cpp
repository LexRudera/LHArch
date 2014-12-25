#include "Settings.hpp"
namespace lha{
Settings::Settings() : m_ShowFps(true),
					   m_DebugLines(false),
					   m_DebugHitboxes(true),
					   m_VideoMode(800,600)
{
	//ctor
}

Settings::~Settings() {
	//dtor
}
}
