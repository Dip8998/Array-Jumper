#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Level/LevelController.h"
#include "../../header/Main/GameService.h"

namespace Gameplay
{
	using namespace Global;
	using namespace SoundM;
	using namespace Main;

	GameplayController::GameplayController()
	{

	}

	GameplayController::~GameplayController()
	{

	}

	void GameplayController::initialize()
	{

	}

	void GameplayController::update()
	{

	}

	void GameplayController::render()
	{

	}

	void GameplayController::processObstacle()
	{
		ServiceLocator::getInstance()->getPlayerService()->takeDamage();
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
	}

	bool GameplayController::isObstacle(Level::BlockType value)
	{
		if (value == Level::BlockType::OBSTACLE_ONE || value == Level::BlockType::OBSTACLE_TWO)
		{
			return true;
		}
		return false;
	}

	void GameplayController::onPositionChanged(int position)
	{
		Level::BlockType value = ServiceLocator::getInstance()->getLevelService()->getCurrentBoxValue(position);

		if (isObstacle(value))
		{
			processObstacle();
		}

		if (isEndBlock(value))
		{
			processEndBlock();
		}

	}

	bool GameplayController::isEndBlock(Level::BlockType value)
	{
		if (value == Level::BlockType::TARGET)
		{
			return true;
		}
		return false;
	}

	void GameplayController::processEndBlock()
	{
		ServiceLocator::getInstance()->getPlayerService()->levelComplete();
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::LEVEL_COMPLETE);
		GameService::setGameState(GameState::CREDITS);
	}

	void GameplayController::gameOver()
	{
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
		GameService::setGameState(GameState::CREDITS);
	}

	void GameplayController::onDeath()
	{
		gameOver();
	}
}