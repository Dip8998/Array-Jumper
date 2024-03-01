#include "../../header/Main/GameService.h"

namespace Main
{
	using namespace Graphics;
	using namespace UI;
	using namespace Sound;
	using namespace Global;

	GameState GameService::current_state = GameState::BOOT;

	GameService::GameService()
	{
		game_window = nullptr;
		service_locator = nullptr;
	}

	GameService::~GameService() { onDestroy(); }

	void GameService::ignite()
	{
		service_locator = ServiceLocator::getInstance();
		initialize();
		setGameState(GameState::SPLASH_SCREEN);
	}

	void GameService::initialize()
	{
		service_locator->initialize();
		game_window = service_locator->getGraphicService()->getGameWindow();
	}

	// Main Game Loop.
	void GameService::update()
	{
		// Process Events.
		service_locator->getEventService()->processEvents();

		// Update Game Logic.
		service_locator->update();
	}

	void GameService::render()
	{
		game_window->clear();
		service_locator->render();
		game_window->display();
	}

	bool GameService::isRunning() { return service_locator->getGraphicService()->isGameWindowOpen(); }

	void GameService::onDestroy() { service_locator->deleteServiceLocator(); }

	void GameService::setGameState(GameState new_state) { current_state = new_state; }

	GameState GameService::getGameState() { return current_state; }
}