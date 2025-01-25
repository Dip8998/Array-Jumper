#pragma once
#include "../Level/BlockType.h"

namespace Gameplay
{
	class GameplayController
	{
	private:
		void processObstacle();
		bool isObstacle(Level::BlockType value);
		bool isEndBlock(Level::BlockType value);
		

	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();

		void onPositionChanged(int position);
	};
}