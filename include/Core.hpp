#ifndef CORE_H
#define CORE_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Settings.hpp"
#include "Scene.hpp"
#include "ResourceManager.hpp"
//#include "InputManager.hpp"

namespace lha {
class InputManager;
class Core {
public:
	// De/Con-structors
	Core(Settings* conf);
	virtual ~Core();

	// Static Functions
	static Core* get()						{return m_Instance;}

	// Accessors
	sf::RenderWindow* getWindow() const		{return m_Window;}
	Scene* getActiveScene() const			{return m_ActiveScene;}
	Settings* getSettings() 				{return m_Settings;}
	ResourceManager* getResourceManager()	{return m_ResManager;}
	InputManager* getInputManager()			{return m_InputMan;}
	const sf::Time* getFrameTime() const	{return &m_FrameTime;}
	sf::View* getView()						{return &m_View;}
	short verticalSync()					{return m_VerticalSync;}
	void verticalSync(short a);

	// Functions
	int run(Scene* scn);
	void changeScene(Scene* scn, const Persistence& depth = Level);
	void quit() {getWindow()->close();}
protected:
private:
	Core();

	static Core* m_Instance;

	sf::Clock m_Clock;
	sf::View m_View;
	Settings* m_Settings = 0;
	sf::RenderWindow* m_Window = 0;
	Scene* m_ActiveScene = 0;
	Scene* m_NextScene = 0;
	Persistence m_LvlChngLvl = Level;
	ResourceManager* m_ResManager;
	InputManager* m_InputMan;
	short m_VerticalSync = 1;

	sf::Time m_FrameTime;
};
}
#endif // CORE_H
