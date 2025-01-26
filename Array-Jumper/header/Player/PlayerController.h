#pragma once
#include "../Event/EventService.h"
#include "../Level/BlockType.h"

namespace Player
{
	class PlayerView;
	class PlayerModel;
	enum class PlayerState;
	enum MovementDirection;

	class PlayerController
	{
	private:
		PlayerModel* player_model;
		PlayerView* player_view;
		Event::EventService* event_service;

		void move(MovementDirection direction);
		void jump(MovementDirection direction);
		bool isPositionInBound(int targetPosition);
		Level::BlockType getCurrentBoxValue(int currentPosition);

		void readInput();
		void destroy();
		void onDeath();

	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();
		void render();

		PlayerState getPlayerState();
		void setPlayerState(PlayerState new_player_state);
		void takeDamage();
		void resetPlayer();
		int getCurrentPosition();
		int getCurrentLives();

	};
}
