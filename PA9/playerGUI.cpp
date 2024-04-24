#include "playerGUI.hpp"

PlayerGUI::PlayerGUI(Andy* player) { 
	andy = player; 
	this->initializeFont();
	this->initializeHPBar();
}

PlayerGUI::~PlayerGUI() {

}

void PlayerGUI::initializeFont() {

}

void PlayerGUI::initializeHPBar() {

	this->hpBarBack.setSize(sf::Vector2f(100.0f, 10.0f));
	this->hpBarBack.setFillColor(sf::Color::Black);

	this->hpBarFront.setSize(sf::Vector2f(100.0f, 10.0f));
	this->hpBarFront.setFillColor(sf::Color::Green);  
}

void PlayerGUI::updateHPBar() {

	this->hpBarBack.setPosition(andy->getPosition().x + 35, andy->getPosition().y - 25); 
	this->hpBarFront.setPosition(this->hpBarBack.getPosition());

	float percent = andy->getHP() / andy->getMaxHP();

	this->hpBarFront.setSize(sf::Vector2f(100.0f * percent, 10.0f)); 

	if (percent <= 0.66f) {
		this->hpBarFront.setFillColor(sf::Color::Yellow); 
	}
	
	if (percent <= 0.33f) {
		this->hpBarFront.setFillColor(sf::Color::Red);  
	}
}

void PlayerGUI::update() {
	updateHPBar(); 
}

void PlayerGUI::renderHPBar(sf::RenderTarget& target) {
	target.draw(this->hpBarBack);
	target.draw(this->hpBarFront);
}

void PlayerGUI::render(sf::RenderTarget& target) {
	this->update(); 
	this->renderHPBar(target); 
}

