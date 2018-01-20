// sf_template.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "AssetManager.h"
#include <string>

const float BUTTON_WIDTH = 100, BUTTON_HEIGHT = 50;
struct musicButton
{
	sf::Vector2f buttonPos;
	sf::RectangleShape buttonShape;
	sf::Text buttonText;
	sf::Music buttonMusic;
	bool IsPlaying = false;
};


int _tmain(int argc, _TCHAR* argv[])
{
	AssetManager manager;

	sf::RenderWindow window(sf::VideoMode(420, 600), "Stage Audio");

	musicButton stageShow[13];

	//////////////////////////////////audio部分///////////////////////////////////////////////////////

	stageShow[0].buttonMusic.openFromFile("music/1.wav");
	stageShow[1].buttonMusic.openFromFile("music/2.wav");
	stageShow[2].buttonMusic.openFromFile("music/3.wav");
	stageShow[3].buttonMusic.openFromFile("music/4.wav");
	stageShow[4].buttonMusic.openFromFile("music/5.wav");
	stageShow[5].buttonMusic.openFromFile("music/6.wav");
	stageShow[6].buttonMusic.openFromFile("music/7.wav");
	stageShow[7].buttonMusic.openFromFile("music/8.wav");
	stageShow[8].buttonMusic.openFromFile("music/9.wav");
	stageShow[9].buttonMusic.openFromFile("music/10.wav");
	stageShow[10].buttonMusic.openFromFile("music/11.wav");
	stageShow[11].buttonMusic.openFromFile("music/12.wav");
	stageShow[12].buttonMusic.openFromFile("music/13.wav");

	sf::Sound LightOff(AssetManager::GetSoundBuffer("music/light_off.wav"));

	bool RingOn = false;
	sf::Sound Ring(AssetManager::GetSoundBuffer("music/ring.wav"));
	Ring.setLoop(true);

	/////////////////////////////////////////图形部分/////////////////////////////////////////
	for (int i = 0; i < 6; i++)
	{
		stageShow[i].buttonPos = sf::Vector2f(0, 90.0f * i);
		stageShow[i].buttonShape.setSize(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));
		stageShow[i].buttonShape.setPosition(stageShow[i].buttonPos);
		stageShow[i].buttonShape.setFillColor(sf::Color::Yellow);
	}

	for (int i = 0; i < 7; i++)
	{
		stageShow[i+6].buttonPos = sf::Vector2f(300, 90.0f * i);
		stageShow[i+6].buttonShape.setSize(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));
		stageShow[i+6].buttonShape.setPosition(stageShow[i+6].buttonPos);
		stageShow[i+6].buttonShape.setFillColor(sf::Color::Yellow);
	}

	/////////////////////////////////////文本部分//////////////////////////////////////////////////
 	sf::String str[13];
 	str[0] = "Num1";
 	str[1] = "Num2";
 	str[2] = "Num3";
 	str[3] = "Num4";
 	str[4] = "Num5";
 	str[5] = "Num6";
 	str[6] = "Num7";
 	str[7] = "Num8";
 	str[8] = "Num9";
 	str[9] = "Num10";
 	str[10] = "Num11";
 	str[11] = "Num12";
 	str[12] = "Num13";

	for (int i = 0; i < 13; i++)
	{
		stageShow[i].buttonText.setString(str[i]);
		stageShow[i].buttonText.setFont(AssetManager::GetFont("sansation.ttf"));
		stageShow[i].buttonText.setColor(sf::Color::Blue);
		stageShow[i].buttonText.setPosition(stageShow[i].buttonPos);
	}

	sf::Text Signature("written by WangXin", AssetManager::GetFont("sansation.ttf"));
	Signature.setPosition(sf::Vector2f(0, 540));
	Signature.setColor(sf::Color::White);
///////////////////////////////////////////控制部分/////////////////////////////////////////////////
	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
			if (e.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2f ClickPos(sf::Mouse::getPosition(window));
				for (int i = 0; i < 13; i++)
				{
					if (ClickPos.x > stageShow[i].buttonPos.x && ClickPos.x < stageShow[i].buttonPos.x + BUTTON_WIDTH
						&& ClickPos.y > stageShow[i].buttonPos.y && ClickPos.y < stageShow[i].buttonPos.y + BUTTON_HEIGHT)
					{
						stageShow[i].IsPlaying = !stageShow[i].IsPlaying;
						if (stageShow[i].IsPlaying)
							stageShow[i].buttonMusic.play();
						else
							stageShow[i].buttonMusic.stop();
					}
				}
			}
			if (e.type == sf::Event::KeyPressed)
			{
				switch (e.key.code)
				{
				case sf::Keyboard::Num1:
				{
					stageShow[0].IsPlaying = !stageShow[0].IsPlaying;
					if (stageShow[0].IsPlaying == true)
						stageShow[0].buttonMusic.play();
					else
						stageShow[0].buttonMusic.stop();
					break;
				}
				case sf::Keyboard::Num2:
				{  
					stageShow[1].IsPlaying = !stageShow[1].IsPlaying;
					if (stageShow[1].IsPlaying == true)
						stageShow[1].buttonMusic.play();
					else
						stageShow[1].buttonMusic.stop();
					break; 
				}
				case sf::Keyboard::Num3:
				{
										   stageShow[2].IsPlaying = !stageShow[2].IsPlaying;
										   if (stageShow[2].IsPlaying == true)
											   stageShow[2].buttonMusic.play();
										   else
											   stageShow[2].buttonMusic.stop();
										   break;
				}
				case sf::Keyboard::Num4:
				{
										   stageShow[3].IsPlaying = !stageShow[3].IsPlaying;
										   if (stageShow[3].IsPlaying == true)
											   stageShow[3].buttonMusic.play();
										   else
											   stageShow[3].buttonMusic.stop();
										   break;
				}
				case sf::Keyboard::Num5:
				{
										   stageShow[4].IsPlaying = !stageShow[4].IsPlaying;
										   if (stageShow[4].IsPlaying == true)
											   stageShow[4].buttonMusic.play();
										   else
											   stageShow[4].buttonMusic.stop();
										   break;
				}
				case sf::Keyboard::Num6:
				{
										   stageShow[5].IsPlaying = !stageShow[5].IsPlaying;
										   if (stageShow[5].IsPlaying == true)
											   stageShow[5].buttonMusic.play();
										   else
											   stageShow[5].buttonMusic.stop();
										   break;
				}
				case sf::Keyboard::Num7:
				{
										   stageShow[6].IsPlaying = !stageShow[6].IsPlaying;
										   if (stageShow[6].IsPlaying == true)
											   stageShow[6].buttonMusic.play();
										   else
											   stageShow[6].buttonMusic.stop();
										   break;
				}
				case sf::Keyboard::Num8:
				{
										   stageShow[7].IsPlaying = !stageShow[7].IsPlaying;
										   if (stageShow[7].IsPlaying == true)
											   stageShow[7].buttonMusic.play();
										   else
											   stageShow[7].buttonMusic.stop();
										   break;
				}
				case sf::Keyboard::Num9:
				{
										   stageShow[8].IsPlaying = !stageShow[8].IsPlaying;
										   if (stageShow[8].IsPlaying == true)
											   stageShow[8].buttonMusic.play();
										   else
											   stageShow[8].buttonMusic.stop();
										   break;
				}
				case sf::Keyboard::Num0:
				{
										   stageShow[9].IsPlaying = !stageShow[9].IsPlaying;
										   if (stageShow[9].IsPlaying == true)
											   stageShow[9].buttonMusic.play();
										   else
											   stageShow[9].buttonMusic.stop();
										   break;
				}
				case sf::Keyboard::Q:
				{
										   stageShow[10].IsPlaying = !stageShow[10].IsPlaying;
										   if (stageShow[10].IsPlaying == true)
											   stageShow[10].buttonMusic.play();
										   else
											   stageShow[10].buttonMusic.stop();
										   break;
				}
				case sf::Keyboard::W:
				{
										   stageShow[11].IsPlaying = !stageShow[11].IsPlaying;
										   if (stageShow[11].IsPlaying == true)
											   stageShow[11].buttonMusic.play();
										   else
											   stageShow[11].buttonMusic.stop();
										   break;
				}
				case sf::Keyboard::E:
				{
										   stageShow[12].IsPlaying = !stageShow[12].IsPlaying;
										   if (stageShow[12].IsPlaying == true)
											   stageShow[12].buttonMusic.play();
										   else
											   stageShow[12].buttonMusic.stop();
										   break;
				}
				case sf::Keyboard::Down:
					LightOff.play(); break;
				case sf::Keyboard::Up:
				{
										 RingOn = !RingOn;
										 if (RingOn)
											 Ring.play();
										 else
											 Ring.stop();
				}


 				case sf::Keyboard::S:
					for (int i = 0; i < 13; i++)
					{
						stageShow[i].buttonMusic.stop();
						stageShow[i].IsPlaying = false;
					}
					break;

				default:
					break;

				}
			}

			window.clear();
			for (int i = 0; i < 13; i++)
			{
				if (stageShow[i].IsPlaying == true)
					stageShow[i].buttonShape.setFillColor(sf::Color::Red);
				if (stageShow[i].IsPlaying == false)
					stageShow[i].buttonShape.setFillColor(sf::Color::Yellow);
			}
			for (int i = 0; i < 13; i++)
			{
			 	window.draw(stageShow[i].buttonShape);
			}
			for (int i = 0; i < 13; i++)
			{
				window.draw(stageShow[i].buttonText);
			}
			window.draw(Signature);
			window.display();
		}
		
	}
	return 0;
}

