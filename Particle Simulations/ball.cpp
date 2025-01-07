#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

const double dt = 0.001;

int main(){
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::CircleShape shape(20.f);
	shape.setFillColor(sf::Color(255, 0, 142));
	
	shape.setPosition({0.0f, 300.0f});	
	float velocity = 500.0f;	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
		
		sf::Vector2f position =  shape.getPosition();	
		float radius = shape.getRadius();
		if ( position.x + radius*2 >= 800){
			velocity = -velocity;
		} else if (position.x < 0){
			velocity = -velocity;
		} 
			position.x += velocity * dt;
			shape.setPosition({position.x, position.y});
		window.clear();
		window.draw(shape);
		window.display();
	} 
	return 0;
}
