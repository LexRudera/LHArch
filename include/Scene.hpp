#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Object.hpp"
#include "Background.hpp"

namespace lha{
class Scene {
public:
	/** Default constructor */
	Scene();
	Scene(const Scene&); // Why not be cloneable?
	operator= (const Scene&);
	/** Default destructor */
	virtual ~Scene();
	void doLoad();
	void doTick();
	void doRender(sf::RenderTarget& target);
	Background* getBackground() {
		return m_Background;
	}
	void applyBackground(Background* bg) {
		m_Background = bg;
	}

	float getWidth();
	float getHeight();
protected:
	virtual void load() = 0;
	virtual void tick();
	virtual void render(sf::RenderTarget& target);
	virtual void renderList(std::vector<Object*>& RenderList);
	virtual void onClose();

	std::vector<Object*> m_Objects;
	std::vector<Object*> m_RenderList;
private:
	Background* m_Background = 0;
};
}
#endif // SCENE_H
