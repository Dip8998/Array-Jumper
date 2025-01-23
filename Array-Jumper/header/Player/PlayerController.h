#pragma once
#include "../Event/EventService.h"

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
		EventM::EventService* event_service;

		void destroy();
		bool isPositionInBound(int targetPosition);
		void move(MovementDirection direction);

	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();
		void render();

		void readInput();
		PlayerState getPlayerState();
		void setPlayerState(PlayerState new_player_state);

		int getCurrentPosition();
	};
}