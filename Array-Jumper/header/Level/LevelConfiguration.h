#pragma once
#include "LevelData.h"
#include "BlockType.h"

namespace Level
{
    class LevelConfiguration
    {
    private:

        BlockType level_1[LevelData::number_of_boxes] =
        {
            ONE, TWO, OBSTACLE_ONE, TWO, THREE, ONE, OBSTACLE_TWO, TWO, ONE, TARGET
        };

        BlockType level_2[LevelData::number_of_boxes] =
        {
            ONE, TWO, OBSTACLE_TWO, ONE, TWO, OBSTACLE_ONE, THREE, OBSTACLE_ONE, ONE, TARGET
        };

        BlockType level_3[LevelData::number_of_boxes] =
        {
            ONE, THREE, OBSTACLE_ONE, OBSTACLE_TWO, ONE, TWO, OBSTACLE_ONE, TWO, ONE, TARGET
        };

    public:
        static const int numnber_of_levels = 3;
        LevelData levels[numnber_of_levels];

        LevelConfiguration()
        {
            for (int i = 0; i < LevelData::number_of_boxes; i++)
            {
                levels[0].level_boxes[i] = level_1[i];
            }

            for (int i = 0; i < LevelData::number_of_boxes; i++)
            {
                levels[1].level_boxes[i] = level_2[i];
            }

            for (int i = 0; i < LevelData::number_of_boxes; i++)
            {
                levels[2].level_boxes[i] = level_3[i];
            }
        }
    };
}