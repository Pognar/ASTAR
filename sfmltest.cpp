#include <SFML/Window.hpp>

int main()
{


	sf::Window window;
	window.create(sf::VideoMode(800, 600), "SFMLTEST.CPP");
	
	while(window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
		
	if (event.type == sf::Event::Closed)
		window.close();

	window.clear(sf::Color::Black);

	sf::Vertex vertex;
	vertex.position = sf::Vector2f(10.f, 50.f);
	vertex.color = sf::Color::Red;
	vertex.texCoords = sf::Vector2f(100.f, 100.f);
	


	window.display();


}
}


	return 0;
}
