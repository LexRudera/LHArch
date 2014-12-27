//#include "Game.hpp"
#include "InputManager.hpp"
#include <iostream>
#include "Utilities.hpp"

namespace lha {
//sf::Time Core::sm_frameTime;
//Core* Core::sm_Instance;
Core* Core::m_Instance;

Core::Core() {
	Core::m_Instance = this;

	m_ResManager = new ResourceManager();
	m_InputMan = new InputManager(this);
	getResourceManager()->loadFont("Gentium", "Gentium-R.ttf", Global);
}

Core::Core(Settings* sett) : Core() {
	m_Settings = sett;
}

Core::~Core() {
	delete m_ActiveScene;
	delete m_InputMan;
	delete m_Settings;
	delete m_ResManager;
	delete m_Window;
}

int Core::run(Scene* scn) {
	//Log("Initializing");
	m_FrameTime = m_Clock.restart();
	//m_window = new sf::RenderWindow(sf::VideoMode(800,600),"Some Game",sf::Style::Fullscreen/*sf::Style::Titlebar*/);
	m_Window = new sf::RenderWindow(m_Settings->getVideoMode(), "CMC Next", sf::Style::Titlebar);
	//m_window->setFramerateLimit(58);
	verticalSync(1);
	m_View = m_Window->getDefaultView();

	changeScene(scn);

	sf::Event event;
	sf::Text FpsTxt;
	FpsTxt.setCharacterSize(20);
	FpsTxt.setFont(*getResourceManager()->getFont("Gentium"));
	Log("Initialized");
	while (m_Window->isOpen()) {
		// Scene Management
		//------------------
		if (m_NextScene != 0) {
			Log("Changing Scene");
			// Destroy the scene
			delete m_ActiveScene;
			m_ActiveScene = m_NextScene;
			m_NextScene = 0;
			// Destroy resources acordingly to level change message
			getResourceManager()->clear(m_LvlChngLvl);
			m_LvlChngLvl = Level;
			// Load and apply next scene
			m_ActiveScene->doLoad();
			Log("Scene Changed");
		}

		// Input/events
		//--------------
		//Log("Input");
		m_InputMan->clear();
		while (m_Window->pollEvent(event)) {
			// Close window : exit
			if (event.type == sf::Event::Closed)
				m_Window->close();
			// Feed the InputManager
			m_InputMan->processInput(event);
		}
		//Log("Inputed?");

		// Logic
		//-------
		//Log("Tick");
		getActiveScene()->doTick();
		//Log("Ticked");

		// Render
		//--------
		//Log("Render");
		m_Window->setView(m_View);
		m_Window->clear( );
		getActiveScene()->doRender(*m_Window);
		//Log("Rendering FPS");
		if (getSettings()->showFps() && m_Window->isOpen()) { // Why it matters if the window is open or not, I don't know.
			FpsTxt.setPosition(m_View.getCenter()-sf::Vector2f(m_View.getSize().x/2, m_View.getSize().y/2));
			FpsTxt.setString(toString(1/m_FrameTime.asSeconds()));
			m_Window->draw(FpsTxt);
		}
		m_Window->display();
		//Log("Rendered");

		// After frame stuff
		//-------------------
		//Log("After");
		m_FrameTime = m_Clock.restart();
		//Log("Aftered");
	}
	return 0;
}
void Core::changeScene(Scene* scn, const Persistence& depth) {
	/*if (m_activeScene != 0)
	{
	    delete m_activeScene;
	    //m_activeScene = 0;
	}
	Log("Changing scene");
	m_activeScene = scn;
	Log("Changed scene");
	return;*/

	m_LvlChngLvl = depth;
	m_NextScene = scn;
}

void Core::verticalSync(short a) {
	switch(a) {
	default:
	case 0: //Off
		m_Window->setFramerateLimit(0);
		m_Window->setVerticalSyncEnabled(false);
		m_VerticalSync = a;
		break;
	case 1: //On
		m_Window->setFramerateLimit(0);
		m_Window->setVerticalSyncEnabled(true);
		m_VerticalSync = a;
		break;
	case 2: //Frame Limter
		m_Window->setFramerateLimit(60);
		m_Window->setVerticalSyncEnabled(false);
		m_VerticalSync = a;
		break;
	}
	m_Window->setVerticalSyncEnabled(a);
	m_VerticalSync = a;
}
}
