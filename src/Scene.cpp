#include "Scene.hpp"
#include "Core.hpp"
#include "Utilities.hpp"
#include "InputManager.hpp"

namespace lha{
Scene::Scene() {
	//ctor
}

Scene::Scene(const Scene& c) {
*this = c;
}

Scene::operator= (const Scene& c){
	//m_Objects = c.m_Objects;
	for(unsigned int i = 0; i < m_Objects.size(); i++) {
		Object* o = c.m_Objects[i]->copy();
		m_Objects.push_back(o);
	}

}

Scene::~Scene() {
	delete m_Background;
	for (unsigned int i = 0; i < m_Objects.size(); i++) {
		delete m_Objects[i];
	}
}


void Scene::doLoad() {
	// Universal loading statements
	Core::get()->getView()->setCenter(Core::get()->getView()->getSize().x/2, Core::get()->getView()->getSize().y/2);
	// Scene individual loading
	load();
}

void Scene::doTick() {
	if (Core::get()->getInputManager()->isKeyDown(Key::Escape))
		onClose();
	//for (unsigned int i = 0; i < m_Objects.size(); i++)
	for (std::vector<Object*>::reverse_iterator i = m_Objects.rbegin(); i != m_Objects.rend(); i++) {
		//Log("Render loop: " + *((Label)m_Objects[i]).getString());
		//m_Objects[i]->DoTick();
		(*i)->doTick();
	}
	tick();
}

float Scene::getWidth() {
	if (!m_Background)
		return Core::get()->getWindow()->getSize().x;
    else
        return m_Background->getSize().x;
}
float Scene::getHeight() {
	if (!m_Background)
		return Core::get()->getWindow()->getSize().y;
    else
        return m_Background->getSize().y;
}

void Scene::tick() {

}

void Scene::doRender(sf::RenderTarget& target) {
	if (m_Background != 0) {
		target.draw(*m_Background, sf::RenderStates::Default);

	}
	render(target); // Just the scene/background stuff

	m_RenderList.clear();
	renderList(m_RenderList);
	//for (unsigned int i = 0; i < m_Objects.size(); i++) {
	for (unsigned int i = 0; i < m_RenderList.size(); i++) {
		//Log("Render loop: " + *((Label)m_Objects[i]).getString());
		target.draw(*m_RenderList[i], sf::RenderStates::Default);
	}
	if (Core::get()->getSettings()->debugLines()) {
		// Middle
		sf::Vertex hort[] = {sf::Vertex(sf::Vector2f(Core::get()->getView()->getCenter().x-Core::get()->getWindow()->getSize().x/2, Core::get()->getView()->getCenter().y)),
							 sf::Vertex(sf::Vector2f(Core::get()->getView()->getCenter().x+Core::get()->getWindow()->getSize().x/2, Core::get()->getView()->getCenter().y))};
		sf::Vertex vert[] = {sf::Vertex(sf::Vector2f(Core::get()->getView()->getCenter().x, Core::get()->getView()->getCenter().y-Core::get()->getWindow()->getSize().y/2)),
							 sf::Vertex(sf::Vector2f(Core::get()->getView()->getCenter().x, Core::get()->getView()->getCenter().y+Core::get()->getWindow()->getSize().y/2))};
		target.draw(hort,2,sf::PrimitiveType::Lines);
		target.draw(vert,2,sf::PrimitiveType::Lines);

		// Vertical
		for (int offset = 100; Core::get()->getWindow()->getSize().x/2-offset > 0 ; offset+=100) {
		sf::Vertex xvertleft[]  = {sf::Vertex(sf::Vector2f(Core::get()->getView()->getCenter().x-offset, Core::get()->getView()->getCenter().y-Core::get()->getWindow()->getSize().y/2)),
								   sf::Vertex(sf::Vector2f(Core::get()->getView()->getCenter().x-offset, Core::get()->getView()->getCenter().y+Core::get()->getWindow()->getSize().y/2))};
		sf::Vertex xvertright[] = {sf::Vertex(sf::Vector2f(Core::get()->getView()->getCenter().x+offset, Core::get()->getView()->getCenter().y-Core::get()->getWindow()->getSize().y/2)),
								   sf::Vertex(sf::Vector2f(Core::get()->getView()->getCenter().x+offset, Core::get()->getView()->getCenter().y+Core::get()->getWindow()->getSize().y/2))};
		target.draw(xvertleft,2,sf::PrimitiveType::Lines);
		target.draw(xvertright,2,sf::PrimitiveType::Lines);
		}

		// Horizontal
		for (int offset = 100; Core::get()->getWindow()->getSize().x/2-offset > 0 ; offset+=100) {
		sf::Vertex xhorttop[]  = {sf::Vertex(sf::Vector2f(Core::get()->getView()->getCenter().x-Core::get()->getWindow()->getSize().x/2, Core::get()->getView()->getCenter().y-offset)),
								   sf::Vertex(sf::Vector2f(Core::get()->getView()->getCenter().x+Core::get()->getWindow()->getSize().x/2, Core::get()->getView()->getCenter().y-offset))};
		sf::Vertex xhortbottom[] = {sf::Vertex(sf::Vector2f(Core::get()->getView()->getCenter().x-Core::get()->getWindow()->getSize().x/2, Core::get()->getView()->getCenter().y+offset)),
								   sf::Vertex(sf::Vector2f(Core::get()->getView()->getCenter().x+Core::get()->getWindow()->getSize().x/2, Core::get()->getView()->getCenter().y+offset))};
		target.draw(xhorttop,2,sf::PrimitiveType::Lines);
		target.draw(xhortbottom,2,sf::PrimitiveType::Lines);
		}
	}
}

void Scene::render(sf::RenderTarget& target) {

}
void Scene::renderList(std::vector<Object*>& renderLst) {
renderLst = m_Objects;
}

// In retrospect, this seems a tad pointless, when you can just use the static Core::get.
// It's on my To-Do list, after Settings
void Scene::onClose() {
	Core::get()->quit();
}
}
