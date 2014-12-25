// The Encapsulated Settings
//------------------------------------------------------------------
// The class containing all the in-game settings.

#ifndef SETTINGS_H
#define SETTINGS_H

#include <SFML\Graphics.hpp>
namespace lha{
class Settings {
public:
	/** Default constructor */
	Settings();
	/** Default destructor */
	virtual ~Settings();

	// Accessor functions
	bool showFps() 								{ return m_ShowFps; }
	void showFps(bool a) 						{ m_ShowFps = a; }
	bool debugLines() 							{ return m_DebugLines; }
	void debugLines(bool a) 					{ m_DebugLines = a; }
	bool debugHitboxes() 						{ return m_DebugHitboxes; }
	void debugHitboxes(bool a) 					{ m_DebugHitboxes = a; }
	const sf::VideoMode& getVideoMode()			{ return m_VideoMode; }
	void setVideoMode(const sf::VideoMode& a)	{ m_VideoMode = a; }
protected:
private:
	bool m_ShowFps;
	sf::VideoMode m_VideoMode;
	bool m_DebugLines;
	bool m_DebugHitboxes;
};
}
#endif // SETTINGS_H
