#pragma once
#include <string>
class Scene
{

protected:
	bool finished;
	std::string nextScene;
	
	
public:
	Scene()
		: finished(false), nextScene("") {}
	virtual void Start() {finished = false;	}
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Finish() = 0;

	inline bool IsFinished() { return finished; }
	inline std::string GetNextScene() { return nextScene; }
};
