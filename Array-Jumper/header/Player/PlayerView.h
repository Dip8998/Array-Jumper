#pragma once
#include "../../header/UI/UIElement/ImageView.h"
#include "../Level/LevelModel.h"

namespace Player
{
	using namespace UI::UIElement;

	class PlayerController;

	class PlayerView
	{
	private:
		UI::UIElement::ImageView* player_image;
		sf::RenderWindow* game_window;
		PlayerController* player_controller;

		Level::BoxDimensions current_box_dimensions;

		float player_height;
		float player_width;

		void initializePlayerImage();
		void drawPlayer();
		void loadPlayer();
		void calculatePlayerDimensions();
		void updatePlayerPosition();
		sf::Vector2f calculatePlayerPosition();

	public:
		PlayerView(PlayerController* controller);
		~PlayerView();

		void initialize();
		void update();
		void render();
	};

}