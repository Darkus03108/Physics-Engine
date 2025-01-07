#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <sstream>
#include <cstdlib>

const float g = 9.81f;
const float e = 0.8f;
const float u = 0.5f;
const float m = 1.0f;
const float dt = 0.01f;


int main(){

	sf::RenderWindow window(sf::VideoMode(800, 600), "Just fall to death!");
	sf::CircleShape particle(20.0f);

	sf::Vector2f acc(g/3, g);
	sf::Vector2f vel(0, 0);
	particle.setPosition(234, 124);
	while(window.isOpen()){
		
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}
		}
		
		while(event.type == sf::Event::MousButttone

		sf::Vector2f position = particle.getPosition();

		if(position.y + particle.getRadius() * 2 >= 600){
			vel.y = -e * vel.y;
			position.y = 600 - particle.getRadius() * 2;
		} if(position.x + particle.getRadius() * 2 >= 800){
			acc.x = -acc.x;
			vel.x = -0.5 * vel.x;
			position.x = 800 - particle.getRadius() * 2;
		} if (position.x < 0) {
			acc.x = -acc.x;
			vel.x = -0.5 * vel.x;
			position.x = 0;
		}
		vel.x += acc.x * dt;
		vel.y += acc.y * dt;
		
		if(position.y + 2 * particle.getRadius() == 600){
			vel.x *= u;
		}

		position.x += vel.x * dt;
		position.y += vel.y * dt;

		particle.setPosition(position);

		window.clear();
		window.draw(particle);
		window.display();

	}
	return 0;
}

		
