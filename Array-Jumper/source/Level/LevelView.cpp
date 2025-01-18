#include "../../header/Level/LevelView.h"
#include "../../header/Level/LevelController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"

using namespace Level;
using namespace Global;
using namespace UI::UIElement;

void Level::LevelView::createImages()
{
	background_image = new ImageView();
}

void Level::LevelView::initializeImages()
{
	background_image->initialize(Config::array_jumper_bg_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
	background_image->setImageAlpha(background_alpha);
}

void Level::LevelView::updateImages()
{
	background_image->update();
}

void Level::LevelView::drawLevel()
{
	background_image->render();
}

void Level::LevelView::deleteImages()
{
	delete(background_image);
}

LevelView::LevelView(LevelController* controller)
{
	game_window = nullptr;
	level_controller = controller;
	createImages();
}

LevelView::~LevelView()
{
	deleteImages();
}

void LevelView::initialize()
{
	game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
	initializeImages();
}

void LevelView::update()
{
	updateImages();
}

void LevelView::render()
{
	drawLevel();
}
