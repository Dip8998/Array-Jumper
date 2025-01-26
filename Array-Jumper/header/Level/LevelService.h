#pragma once

namespace Level
{
	class LevelController;
	struct BoxDimensions;
	enum BlockType;

	class LevelService
	{
	private:
		LevelController* level_controller;
		void destroy();

	public:
		LevelService();
		~LevelService();

		void initialize();
		void update();
		void render();

		BoxDimensions getBoxDimensions();

		BlockType getCurrentBoxValue(int currentPosition);
		void loadNextLevel();
		int getCurrentLevelNumber();
		bool isLastLevel();
		void resetLevels();
	};
}
