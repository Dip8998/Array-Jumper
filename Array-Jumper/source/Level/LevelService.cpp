#include "../../header/Level/LevelService.h"
#include "../../header/Level/LevelController.h"
#include "../../header/Level/LevelModel.h"

namespace Level
{

	LevelService::LevelService()
	{
		level_controller = new LevelController();
	}

	LevelService::~LevelService()
	{
		destroy();
	}

	void LevelService::initialize()
	{
		level_controller->initialize();
	}

	void LevelService::update()
	{
		level_controller->update();
	}

	void LevelService::render()
	{
		level_controller->render();
	}

	void LevelService::destroy()
	{
		delete(level_controller);
	}

	BoxDimensions LevelService::getBoxDimensions()
	{
		return level_controller->getBoxDimensions();
	}

	BlockType LevelService::getCurrentBoxValue(int currentPosition)
	{
		return level_controller->getCurrentBoxValue(currentPosition);
	}

	bool LevelController::isLastLevel()
	{
		return level_model->isLastLevel();
	}

	void LevelController::loadNextLevel()
	{
		level_model->loadNextLevel();
	}

	int LevelController::getCurrentLevelNumber()
	{
		return level_model->getCurrentLevelNumber();
	}

	void LevelController::resetLevels()
	{
		level_model->reset();
	}

	int LevelService::getCurrentLevelNumber()
	{
		return level_controller->getCurrentLevelNumber();
	}

	bool LevelService::isLastLevel()
	{
		return level_controller->isLastLevel();
	}

	void LevelService::loadNextLevel()
	{
		level_controller->loadNextLevel();
	}

	void LevelService::resetLevels()
	{
		level_controller->resetLevels();
	}
}