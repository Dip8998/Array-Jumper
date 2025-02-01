#pragma once

namespace Level
{
	class LevelModel;
	class LevelView;
	struct BoxDimensions;
	enum BlockType;

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

		BlockType getCurrentBoxValue(int currentPosition);
		BoxDimensions getBoxDimensions();

		bool isLastLevel();
		void loadNextLevel();
		void resetLevels();
		int getCurrentLevelNumber();
	};
}
