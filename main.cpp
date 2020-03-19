#include <TGUI/TGUI.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <functional>
#include <math.h>
//#include <ofstream>

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

std::string globaltraits[12] {"/10 Intellect(Dumb)", "/10 Intellect(Average)", "/10 Intellect(Smart)", "/10 Stamina(Smoker)", "/10 Stamina(Average)", "/10 Stamina(Healthy)", "/10 Mastery(Inept)", "/10 Mastery(Average)", "/10 Mastery(Skilled)", "/10 Versatility(Useless)", "/10 Versatility(Average)", "/10 Versatility(Competent)"};



//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

	void signalHandler(tgui::EditBox::Ptr statbox, tgui::EditBox::Ptr checkbox)
	{
		auto val = (rand() % 10) + 1;
		int i = val;
		if (val <= 4){
		statbox->setText(std::to_string(val).append(globaltraits[0]));
		} else if (val >= 4 && val <= 7){
		statbox->setText(std::to_string(val).append(globaltraits[1]));
		} else if (val >= 8){
		statbox->setText(std::to_string(val).append(globaltraits[2]));

	}
		//if (i>0)
		//{
			//i = i*2;
			//checkbox->setText(std::to_string(i));
			
		//}
		
	}

	void signalHandler_2(tgui::EditBox::Ptr statbox_2, tgui::EditBox::Ptr checkbox)
	{
		auto val = (rand() % 10) + 1;
		auto i = val;
		if (val <= 4){
		statbox_2->setText(std::to_string(val).append(globaltraits[3]));
		} else if (val >= 4 && val <= 7){
		statbox_2->setText(std::to_string(val).append(globaltraits[4]));
		} else if (val >= 8){
		statbox_2->setText(std::to_string(val).append(globaltraits[5]));
	}
		//if (i>0)
		//{
			//i = i*2;
			//checkbox->setText(std::to_string(i));
			
		//}
	}

	void signalHandler_3(tgui::EditBox::Ptr statbox_3, tgui::EditBox::Ptr checkbox)
	{
		auto val = (rand() % 10) + 1;
		auto i = val;
		if (val <= 4){
		statbox_3->setText(std::to_string(val).append(globaltraits[6]));
		} else if (val >= 4 && val <= 7){
		statbox_3->setText(std::to_string(val).append(globaltraits[7]));
		} else if (val >= 8){
		statbox_3->setText(std::to_string(val).append(globaltraits[8]));
	}
		//if (i>0)
		//{
			//i = i*2;
			//checkbox->setText(std::to_string(i));
			
		//}
	}

	void signalHandler_4(tgui::EditBox::Ptr statbox_4, tgui::EditBox::Ptr checkbox)
	{
		auto val = (rand() % 10) + 1;
		auto i = val;
		if (val <= 4){
		statbox_4->setText(std::to_string(val).append(globaltraits[9]));
		} else if (val >= 4 && val <= 7){
		statbox_4->setText(std::to_string(val).append(globaltraits[10]));
		} else if (val >= 8){
		statbox_4->setText(std::to_string(val).append(globaltraits[11]));
	}
		//if (i>0)
		//{
			//i = i*2;
			//checkbox->setText(std::to_string(i));
			
		//}
	}
	void signalMeaning(tgui::EditBox::Ptr statbox, tgui::EditBox::Ptr statbox_2, tgui::EditBox::Ptr statbox_3, tgui::EditBox::Ptr statbox_4, tgui::EditBox::Ptr checkbox)
	{
		sf::RenderWindow window_2(sf::VideoMode{800, 600}, "Stat Meanings");
		tgui::Gui gui2{window_2};
		std::string scales[3] {" Health", " Mana", " Damage"};

		std::string mint = statbox->getText();
		std::string msta = statbox_2->getText();
		std::string mmas = statbox_3->getText();
		std::string mver = statbox_4->getText();
		int intl = std::stoi(mint);
		int stam = std::stoi(msta);
		int mast = std::stoi(mmas);
		int vers = std::stoi(mver);
		int hp = (stam*10 + mast*0.5);
		int mana = (intl*2 + 30);
		int dmg = (stam*2+50 + vers*0.2);
		sf::Text HP;
		sf::Font font1;
		HP.setFont(font1);
		HP.setCharacterSize(40);
		HP.setFillColor(sf::Color::Green);
		HP.setString("");
		HP.setPosition(sf::Vector2f(20.f, 100.f));
		sf::Text MANA;
		MANA.setFont(font1);
		MANA.setCharacterSize(40);
		MANA.setFillColor(sf::Color::Blue);
		MANA.setString("");
		MANA.setPosition(sf::Vector2f(20.f, 300.f));
		sf::Text DMG;
		DMG.setFont(font1);
		DMG.setCharacterSize(40);
		DMG.setFillColor(sf::Color::Red);
		DMG.setString("");
		DMG.setPosition(sf::Vector2f(20.f, 500.f));
	
		



		if (!font1.loadFromFile("Manjari-Thin.otf"))
	{
	std::cout << "pucko" << std::endl;
	}
	
		while (window_2.isOpen())
		{
			sf::Event event_2;
			while (window_2.pollEvent(event_2))
			{
			HP.setString(std::to_string(hp).append(scales[0]));
			MANA.setString(std::to_string(mana).append(scales[1]));
			DMG.setString(std::to_string(dmg).append(scales[2]));




			if (event_2.type == sf::Event::Closed)
				window_2.close();
			gui2.handleEvent(event_2);
			}





		window_2.clear();
		window_2.draw(HP);
		window_2.draw(MANA);
		window_2.draw(DMG);
		window_2.display();
		}
	}


	

		
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
	sf::Text text;
	sf::Font font;
	text.setFont(font);
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::White);
	text.setString("");
	text.setPosition(sf::Vector2f(20.f, 100.f));
	
	sf::Text RP;
	RP.setFont(font);
	RP.setCharacterSize(40);
	RP.setFillColor(sf::Color::White);
	RP.setString("RP Character Generator");
	RP.setPosition(sf::Vector2f(100.f, 0.f));
	
	sf::Text twig;
	twig.setFont(font);
	twig.setCharacterSize(20);
	twig.setFillColor(sf::Color::White);
	twig.setString("Stat Clarification");
	twig.setPosition(sf::Vector2f(600.f, 350.f));

	sf::Text trait;
	trait.setFont(font);
	trait.setCharacterSize(40);
	trait.setFillColor(sf::Color::White);
	trait.setString("");
	trait.setPosition(sf::Vector2f(20.f, 100.f));

	sf::Text titletext;
	titletext.setFont(font);
	titletext.setCharacterSize(20);
	titletext.setFillColor(sf::Color::White);
	titletext.setString("");
	titletext.setPosition(sf::Vector2f(25.f, 150.f));

	sf::Text titletextset;
	titletextset.setFont(font);
	titletextset.setCharacterSize(20);
	titletextset.setFillColor(sf::Color::White);
	titletextset.setString("Title:");
	titletextset.setPosition(sf::Vector2f(300.f, 475.f));

	sf::Text randomizetext;
	randomizetext.setFont(font);
	randomizetext.setCharacterSize(20);
	randomizetext.setFillColor(sf::Color::White);
	randomizetext.setString("Randomize Your Stats");
	randomizetext.setPosition(sf::Vector2f(600.f, 250.f));

	sf::Text nametext;
	nametext.setFont(font);
	nametext.setCharacterSize(40);
	nametext.setFillColor(sf::Color::White);
	nametext.setString("Name:");
	nametext.setPosition(sf::Vector2f(300.f, 400.f));
	
	sf::RenderWindow window{{800, 600}, "Window"};	
		tgui::Gui gui{window};	
	tgui::EditBox::Ptr namebox = tgui::EditBox::create();
		gui.add(namebox);
	tgui::EditBox::Ptr titlebox = tgui::EditBox::create();
		gui.add(titlebox);
		
	tgui::EditBox::Ptr statbox = tgui::EditBox::create();
		gui.add(statbox);
	tgui::EditBox::Ptr statbox_2 = tgui::EditBox::create();
		gui.add(statbox_2);
	tgui::EditBox::Ptr statbox_3 = tgui::EditBox::create();
		gui.add(statbox_3);
	tgui::EditBox::Ptr statbox_4 = tgui::EditBox::create();
		gui.add(statbox_4);
	tgui::EditBox::Ptr checkbox = tgui::EditBox::create();
		//gui.add(checkbox);
	
	tgui::Button::Ptr meaningbutton = tgui::Button::create(); //meaning button
		gui.add(meaningbutton);
		meaningbutton->connect("pressed", signalMeaning, std::ref(statbox), std::ref(statbox_2), std::ref(statbox_3), std::ref(statbox_4), std::ref(checkbox));
	

	tgui::Button::Ptr button = tgui::Button::create();
		gui.add(button);
		button->connect("pressed", signalHandler, std::ref(statbox), std::ref(checkbox));
	tgui::Button::Ptr button_2 = tgui::Button::create();
		button->connect("pressed", signalHandler_2, std::ref(statbox_2), std::ref(checkbox));
	tgui::Button::Ptr button_3 = tgui::Button::create();
		button->connect("pressed", signalHandler_3, std::ref(statbox_3), std::ref(checkbox));
	tgui::Button::Ptr button_4 = tgui::Button::create();
		button->connect("pressed", signalHandler_4, std::ref(statbox_4), std::ref(checkbox));

	meaningbutton->setPosition(600, 400);
	statbox->setSize({190, 20});
	statbox_2->setSize({190, 20});
	statbox_3->setSize({190, 20});
	statbox_4->setSize({190, 20});
	titlebox->setPosition(300, 500);
	statbox->setPosition(600, 200);
	statbox_2->setPosition(600, 150);
	statbox_3->setPosition(600, 100);
	statbox_4->setPosition(600, 50);
	namebox->setPosition(300, 450);
	button->setPosition(600, 300);
	
	//sf::Image image;
	//sf::Sprite sprite;
	//sprite.setTexture(image);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------	
	

	if (!font.loadFromFile("Manjari-Thin.otf"))
	{
	std::cout << "pucko" << std::endl;
	}

	//if (!texture.loadFromFile("image.png"))
	//{
    	//std::cout << "Really Dumb" << std::endl;
	//}




    while (window.isOpen())
    {
	
	

        sf::Event event;
        while (window.pollEvent(event))
        {
	
		
	if (event.key.code == sf::Keyboard::Return)
	{
		//std:: cout << i << std::endl;
		
		text.setString(namebox->getText());
		titletext.setString(titlebox->getText());
		
	}
	if (event.type == sf::Event::Closed)
                window.close();

            gui.handleEvent(event);
        }

        window.clear();
        gui.draw();
	//window.draw(sprite);
	//texture.update(image);
	window.draw(twig);
	window.draw(nametext);
	window.draw(titletext);
	window.draw(randomizetext);
	window.draw(text);
	window.draw(titletextset);
	window.draw(RP);
        window.display();
	
}
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

