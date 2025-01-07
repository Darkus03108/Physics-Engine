#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include <tuple>


const float g = 9.81f;
const float dt = 0.01f;
const float e = 0.8;
const float u = 0.5f;
const int num_Particles = 200; //Number of balls which you are gonna see falling

struct Particle{
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	sf::CircleShape shape;

	Particle(){
		int R = rand() % 256;
		int B = rand() % 256;
		int G = rand() % 256;
		position = {static_cast<float>(rand() % 800), static_cast<float>(rand() % 600)};
		velocity = {0, 0};
		shape.setPosition(position);
		shape.setRadius(10.f);	
		shape.setFillColor(sf::Color(R, B, G)); 

		float randomAx = static_cast<int>(rand() % 2)/100.0f;
		randomAx = rand() % 2 == 0 ? -randomAx : randomAx;
		acceleration = {randomAx + rand() % 9, g};
	}
	void update (float dt) {
	velocity.x += dt * acceleration.x;
	velocity.y += dt * acceleration.y;

	position.x += dt * velocity.x;
	position.y += dt * velocity.y;

	shape.setPosition(position);
	}

	void checkCollision(float windowWidth, float windowHeight, float e){


		if(position.x < 0){
			acceleration.x = -acceleration.x;
			velocity.x = -u * velocity.x;
			position.x = 0;
		}
		if(position.x + shape.getRadius() * 2 >= 800){
			acceleration.x = -acceleration.x;
			velocity.x = -u * velocity.y;
			position.x = windowWidth - shape.getRadius() * 2;
		}


		if(position.y < 0){
			velocity.y = -velocity.y;
			position.y = 0;
		}

		if(position.y + shape.getRadius() * 2 >= 600){
			velocity.y = -e * velocity.y;
			position.y = windowHeight - shape.getRadius() * 2;
		}

		if(position.y + shape.getRadius() * 2 == 600){
			velocity.x *= u;
		}

		shape.setPosition(position);

		
	}
};


int main(){
	sf::RenderWindow window(sf::VideoMode(800, 600), "OMG!!! WTF IS THIS CHAOSSSS!!!!!???");
	
	std::array<Particle, num_Particles> particle;
	
		
	while(window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}}

		for (auto& particlei : particle){
			particlei.update(dt);
			particlei.checkCollision(window.getSize().x, window.getSize().y, e);
		}

		window.clear();

		for (auto& particlei : particle){
			window.draw(particlei.shape);
		}
		window.display();
	}
	return 0;
}

