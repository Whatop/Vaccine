#pragma once

enum class SceneState {
	INTRO,
	MENU,
	MAIN,
	FINAL,
	DIE,
	ENDING,
	NONE
};

class SceneDirector : public Singleton<SceneDirector>
{
	Scene* m_CurrentScene;
	SceneState m_Scene;

public:

	SceneDirector();
	~SceneDirector();

	void ChangeScene(Scene* newScene);
	
	void SetScene(SceneState stateScene);
	SceneState GetScene() { return m_Scene; }
	void Update(float deltaTime, float time);
	void Render();

};

