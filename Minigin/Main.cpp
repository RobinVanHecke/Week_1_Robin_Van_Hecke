#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "Scene.h"

#include "GameObject.h"
#include "TextComponent.h"
#include "TransformComponent.h"
#include "RenderComponent.h"
#include "TextureComponent.h"
#include "FpsComponent.h"

void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");
	const auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	
	const auto goBackground = std::make_shared<dae::GameObject>();
	goBackground->AddComponent<TextureComponent>()->SetTexture("background.tga");
	goBackground->AddComponent<RenderComponent>();
	scene.Add(goBackground);
	
	const auto goLogo = std::make_shared<dae::GameObject>();
	goLogo->AddComponent<TextureComponent>()->SetTexture("logo.tga");
	goLogo->GetComponent<TransformComponent>()->SetWorldPosition(216.f, 180.f);
	goLogo->AddComponent<RenderComponent>();
	scene.Add(goLogo);
	
	const auto goTitle = std::make_shared<dae::GameObject>();
	goTitle->AddComponent<TextComponent>()->SetText("Programming 4 Assignment");
	goTitle->GetComponent<TextComponent>()->SetFont(font);
	goTitle->GetComponent<TransformComponent>()->SetWorldPosition(80.f, 50.f);
	goTitle->AddComponent<TextureComponent>();
	goTitle->AddComponent<RenderComponent>();
	scene.Add(goTitle);

	const auto goFps = std::make_shared<dae::GameObject>();
	goFps->AddComponent<FpsComponent>();
	goFps->AddComponent<TextComponent>();
	goFps->GetComponent<TextComponent>()->SetFont(font);
	goFps->GetComponent<TransformComponent>()->SetWorldPosition(0.f, 0.f);
	goFps->AddComponent<TextureComponent>();
	goFps->AddComponent<RenderComponent>();
	scene.Add(goFps);

	const auto goMainCharacter = std::make_shared<dae::GameObject>();
	goMainCharacter->GetComponent<TransformComponent>()->SetWorldPosition(200.f, 200.f);
	goMainCharacter->AddComponent<TextureComponent>()->SetTexture("MainCharacter.png");
	goMainCharacter->AddComponent<RenderComponent>();
	scene.Add(goMainCharacter);

	const auto goEnemyCharacter = std::make_shared<dae::GameObject>();
	goEnemyCharacter->GetComponent<TransformComponent>()->SetWorldPosition(300.f, 300.f);
	goEnemyCharacter->AddComponent<TextureComponent>()->SetTexture("EnemyCharacter.png");
	goEnemyCharacter->AddComponent<RenderComponent>();
	scene.Add(goEnemyCharacter);


	// TODO game objects should not be raw pointers
	//const auto rootObject = std::make_shared<dae::GameObject>();
	//scene.Add(rootObject);

	////const auto goBackground = std::make_shared<dae::GameObject>();
	//dae::GameObject* goBackground = new dae::GameObject();
	//goBackground->AddComponent<TextureComponent>()->SetTexture("background.tga");
	//goBackground->AddComponent<RenderComponent>();
	//goBackground->SetParent(rootObject.get());

	//dae::GameObject* goLogo = new dae::GameObject();
	//goLogo->AddComponent<TextureComponent>()->SetTexture("logo.tga");
	//goLogo->GetComponent<TransformComponent>()->SetWorldPosition(216.f, 180.f);
	//goLogo->AddComponent<RenderComponent>();
	//goLogo->SetParent(rootObject.get());

	//const auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	//dae::GameObject* goTitle = new dae::GameObject();
	//goTitle->AddComponent<TextComponent>()->SetText("Programming 4 Assignment");
	//goTitle->GetComponent<TextComponent>()->SetFont(font);
	//goTitle->GetComponent<TransformComponent>()->SetWorldPosition(80.f, 50.f);
	//goTitle->AddComponent<TextureComponent>();
	//goTitle->AddComponent<RenderComponent>();
	//goTitle->SetParent(rootObject.get());

	//dae::GameObject* goFps = new dae::GameObject();
	//goFps->AddComponent<FpsComponent>();
	//goFps->AddComponent<TextComponent>();
	//goFps->GetComponent<TextComponent>()->SetFont(font);
	//goFps->GetComponent<TransformComponent>()->SetWorldPosition(0.f, 0.f);
	//goFps->AddComponent<TextureComponent>();
	//goFps->AddComponent<RenderComponent>();
	//goFps->SetParent(rootObject.get());
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}