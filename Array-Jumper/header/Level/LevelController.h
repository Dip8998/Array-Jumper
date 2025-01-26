#pragma once
#include "BlockType.h"

namespace Level
{
	class LevelModel;
	class LevelView;
	struct BoxDimensions;

	class LevelController
	{
	private:
		LevelModel* level_model;
		LevelView* level_view;

		void destroy();

	public:
		LevelController();
		~LevelController();


		void initialize();
		void update();
		void render();

		void loadNextLevel();
		int getCurrentLevelNumber();
		bool isLastLevel();
		void resetLevels();


		BlockType getCurrentBoxValue(int currentPosition);
		BoxDimensions getBoxDimensions();
	};
}