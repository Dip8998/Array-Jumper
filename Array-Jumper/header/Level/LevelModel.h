#pragma once
#include "LevelConfiguration.h"

namespace Level
{
	class LevelModel
	{
	private:
		LevelConfiguration level_configuration;
		int current_level_index;

	public:
		LevelModel();
		~LevelModel();

		void initialize();
		void update();

		BlockType getCurrentBoxValue(int currentPosition);

		void loadNextLevel();
		int getCurrentLevelNumber();
		bool isLastLevel();
		void reset();
		
	};

	struct BoxDimensions
	{
		float box_width;
		float box_height;
		float box_spacing;

		float box_spacing_percentage = 0.3f;
		float bottom_offset = 200.f;
	};
}
