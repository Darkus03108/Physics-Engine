#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

int main(){
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "Whatever the shit you've(I) written! ");
	sf::CircleShape shape(20.f);
	shape.setFillColor(sf::Color::Green);
	
	sf::Vector2f velocity(50*sqrt(2), 50*sqrt(2));
	
	shape.setPosition(0, 300);
	float dt = 0.01;

	while(window.isOpen()){
	
		sf::Event event;
		while(window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed){
		window.close();
		}
	}
		//Your Code Here...
		
		sf::Vector2f position = shape.getPosition();
		
		if(position.y + shape.getRadius() * 2 >= 600){

			velocity.y = -velocity.y;

		} else if (position.y < 0){

			velocity.y = -velocity.y;

		} else if ( position.x + shape.getRadius() * 2 >= 800 ) {

			velocity.x = -velocity.x;

		} else if ( position.x < 0 ){

			velocity.x = -velocity.x;

		} 
		
		position.x += velocity.x * dt;
		position.y += velocity.y * dt;
		
		shape.setPosition(position);	
		


		


	window.clear();
	window.draw(shape);
	window.display();

	}
	return 0;
}
	
