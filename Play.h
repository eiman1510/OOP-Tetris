//#include<SFML/Graphics.hpp>
//#include<fstream>
//#include"Well.h"
//#include <vector>
//#include <algorithm>
//#include<time.h>
//#include<iostream>
//
//using namespace sf;
//
//class play
//{
//
//private:
//
//	enum class GameState { NameInput, GameRunning };
//	GameState gameState = GameState::NameInput;
//
//	float speed;
//	int s = 0, sc = 0;
//	int level = 1;
//	int lines = 0;
//
//	RenderWindow* window;
//	sf::Clock Clock;
//	Event evt;
//
//	bool nameEntered = false;
//	std::string playerName;
//
//	std::vector<int> scores;
//	std::string inputFileName = "Record.txt";
//	std::string outputFileName = "input.txt";
//
//public:
//
//	Text diplayname;
//	well grid;
//
//private:
//
//	void saveScore(int score)
//	{
//		std::ofstream outputFile("Record.txt", std::ios::app);
//
//		if (outputFile.is_open())
//		{
//			outputFile << score << std::endl;
//			outputFile.close();
//			std::cout << "Score saved to Record.txt" << std::endl;
//		}
//	}
//
//	void loadScores()
//	{
//		std::ifstream inputFile("input.txt");
//		if (inputFile.is_open())
//		{
//			int score;
//			while (inputFile >> score)
//			{
//				scores.push_back(score);
//			}
//			inputFile.close();
//		}
//	}
//	void sortNumbersDescending(const std::string& inputFileName, const std::string& outputFileName)
//	{
//		std::ifstream inputFile(inputFileName);
//		int number;
//		std::vector<int> numbers;
//		while (inputFile >> number) {
//			numbers.push_back(number);
//		}
//		inputFile.close();
//
//		std::sort(numbers.rbegin(), numbers.rend());
//
//		std::ofstream outputFile(outputFileName);
//		int count = 0;
//		for (const auto& num : numbers) {
//			outputFile << num << std::endl;
//			count++;
//			if (count == 5)
//			{
//				break;
//			}
//		}
//		outputFile.close();
//	}
//public:
//
//	play() :evt(),speed(0)
//	{
//		Clock.restart();
//		grid.t();
//		window = new sf::RenderWindow(sf::VideoMode(1200, 950), "Tetris", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
//		grid.filling();
//		window->setFramerateLimit(60);
//	}
//	void displayScores()
//	{
//		std::ifstream inputFile("input.txt");
//		if (inputFile.is_open()) {
//			std::string score;
//			int yPos = 320;
//			sf::Font font;
//			font.loadFromFile("ALGER.ttf");
//			sf::Text scoreText;
//			scoreText.setFont(font);
//			scoreText.setCharacterSize(45);
//			scoreText.setFillColor(sf::Color::White);
//
//			RectangleShape back(Vector2f(1200, 950));
//			Texture t;
//			t.loadFromFile("tri.jpg");
//			back.setTexture(&t);
//			window->draw(back);
//
//			RectangleShape hold(Vector2f(450, 650));
//			hold.setFillColor(Color::Transparent);
//			hold.setOutlineColor(Color::White);
//			hold.setOutlineThickness(10);
//			hold.setPosition(400, 150);
//			window->draw(hold);
//
//			Text scores;
//			scores.setFont(font);
//			scores.setString("Game Over\n Highscores");
//			scores.setCharacterSize(50);
//			scores.setPosition(450, 200);
//			scores.setFillColor(Color::White);
//			window->draw(scores);
//
//			while (std::getline(inputFile, score)) {
//				scoreText.setString(score);
//				scoreText.setPosition(550, yPos);
//				window->draw(scoreText);
//				yPos += 100;
//			}
//
//			inputFile.close();
//		}
//
//	}
//	void format()
//	{
//		int x = 50, y = 50;
//		sf::RectangleShape block;
//
//		//big grid
//		block.setPosition(sf::Vector2f(x, y));
//		block.setSize(sf::Vector2f(500, 950));
//		block.setOutlineColor(sf::Color::Color(96, 96, 96));
//		block.setFillColor(sf::Color::White);
//		block.setOutlineThickness(5);
//		window->draw(block);
//		//frame
//		RectangleShape a1(Vector2f(50.0f, 50.05));
//		RectangleShape a2(Vector2f(35.0f, 35.0f));
//		RectangleShape a3(Vector2f(23.0f, 23.0f));
//		block.setSize(sf::Vector2f(50, 45));
//		block.setOutlineThickness(1);
//		for (int i = 0; i < 20; i++)
//		{
//			for (int j = 0; j < 10; j++)
//			{
//				block.setPosition(sf::Vector2f(x, y));
//				a1.setPosition(Vector2f(x, y));
//				a2.setPosition(Vector2f(7 + x, 7 + y));
//				a3.setPosition(Vector2f(12 + x, 12 + y));
//				switch (grid.w[i][j])
//				{
//				case 1:
//					block.setFillColor(sf::Color(1, 255, 255));
//					a1.setFillColor(Color::Color(0, 102, 102));
//					a2.setFillColor(Color::Color(0, 153, 153));
//					a3.setFillColor(Color::Color(1, 204, 204));
//					break;
//				case 5:
//					block.setFillColor(sf::Color::Blue);
//					a1.setFillColor(Color::Color(0, 0, 102));
//					a2.setFillColor(Color::Color(0, 0, 153));
//					a3.setFillColor(Color::Color(0, 0, 204));
//					break;
//				case 2:
//					block.setFillColor(sf::Color(255, 165, 0));
//					a1.setFillColor(Color::Color(204, 102, 0));
//					a2.setFillColor(Color::Color(255, 128, 0));
//					a3.setFillColor(Color::Color(255, 153, 51));
//					break;
//				case 4:
//					block.setFillColor(sf::Color::Yellow);
//					a1.setFillColor(Color::Color(204, 204, 0));
//					a2.setFillColor(Color::Color(255, 255, 51));
//					a3.setFillColor(Color::Color(255, 255, 102));
//					break;
//				case 3:
//					block.setFillColor(sf::Color::Green);
//					a1.setFillColor(Color::Color(0, 102, 0));
//					a2.setFillColor(Color::Color(0, 153, 0));
//					a3.setFillColor(Color::Color(1, 204, 0));
//					break;
//				case 7:
//					block.setFillColor(sf::Color(170, 0, 255));
//					a1.setFillColor(Color::Color(102, 0, 51));
//					a2.setFillColor(Color::Color(153, 0, 76));
//					a3.setFillColor(Color::Color(204, 0, 102));
//					break;
//				case 6:
//					block.setFillColor(sf::Color::Red);
//					a2.setFillColor(Color::Color(204, 0, 0));
//					a1.setFillColor(Color::Color(153, 0, 0));
//					a3.setFillColor(Color::Red);
//					break;
//				case 0:
//					block.setFillColor(sf::Color::White);
//					a2.setFillColor(Color::Color(192, 192, 192));
//					a1.setFillColor(Color::Color(160, 160, 160));
//					a3.setFillColor(Color::Color(192, 192, 192));
//					break;
//				}
//				window->draw(block);
//				window->draw(a1);
//				window->draw(a2);
//				window->draw(a3);
//				x += 50;
//			}
//			x = 50;
//			y += 45;
//		}
//	}
//	void inputName()
//	{
//		RectangleShape b(Vector2f(1100, 900));
//		b.setPosition(Vector2f(50, 0));
//		Texture back;
//		back.loadFromFile("back.png");
//		b.setTexture(&back);
//
//		Font font;
//		font.loadFromFile("ALGER.ttf");
//		sf::Text promptText;
//		promptText.setFont(font);
//		promptText.setCharacterSize(50);
//		promptText.setString("Enter your name:");
//		promptText.setPosition(400, 550);
//
//		sf::Text nameText;
//		nameText.setFont(font);
//		nameText.setCharacterSize(50);
//		nameText.setPosition(400, 600);
//
//		sf::Event event;
//
//		while (window->isOpen() && !nameEntered)
//		{
//			while (window->pollEvent(event))
//			{
//				if (event.type == sf::Event::Closed)
//					window->close();
//
//				if (event.type == sf::Event::TextEntered)
//				{
//					if (event.text.unicode < 128)
//					{
//						if (event.text.unicode == '\b' && !playerName.empty())
//						{
//							playerName.pop_back();
//						}
//						else if (event.text.unicode == '\r' || event.text.unicode == '\n')
//						{
//							nameEntered = true;
//						}
//						else if (event.text.unicode != '\b')
//						{
//							playerName += static_cast<char>(event.text.unicode);
//						}
//						nameText.setString(playerName);
//						diplayname.setString("Player : " + (playerName));
//					}
//				}
//			}
//
//			window->clear();
//			window->draw(b);
//			window->draw(promptText);
//			window->draw(nameText);
//			window->display();
//		}
//	}
//	void scoring()
//	{
//		sf::Text scoreText, Lines, Level, TotalLines;
//		sf::Font font;
//		font.loadFromFile("ALGER.ttf");
//		Level.setFont(font);
//		if (lines >= 10)
//		{
//			level++;
//			lines = 0;
//			speed = speed - 0.9;
//		}
//		RectangleShape back(Vector2f(1200, 950));
//		Texture t;
//		t.loadFromFile("tri.jpg");
//		back.setTexture(&t);
//		RectangleShape a1(Vector2f(410, 100));
//		RectangleShape a2(Vector2f(410, 100));
//		RectangleShape a3(Vector2f(410, 100));
//		RectangleShape a4(Vector2f(410, 100));
//		RectangleShape a5(Vector2f(410, 100));
//		a1.setPosition(Vector2f(675, 100));
//		a2.setPosition(Vector2f(675, 250));
//		a3.setPosition(Vector2f(675, 400));
//		a4.setPosition(Vector2f(675, 550));
//		a5.setPosition(Vector2f(675, 700));
//		a1.setOutlineThickness(7);
//		a2.setOutlineThickness(7);
//		a3.setOutlineThickness(7);
//		a4.setOutlineThickness(7);
//		a5.setOutlineThickness(7);
//		a1.setOutlineColor(Color::White);
//		a2.setOutlineColor(Color::White);
//		a3.setOutlineColor(Color::White);
//		a4.setOutlineColor(Color::White);
//		a5.setOutlineColor(Color::White);
//		a1.setFillColor(Color::Transparent);
//		a2.setFillColor(Color::Transparent);
//		a3.setFillColor(Color::Transparent);
//		a4.setFillColor(Color::Transparent);
//		a5.setFillColor(Color::Transparent);
//		Level.setString("Level: " + std::to_string(level));
//		Level.setCharacterSize(50);
//		Level.setFillColor(sf::Color::White);
//		Level.setPosition(700, 275);
//		scoreText.setFont(font);
//		scoreText.setString("Score: " + std::to_string(sc));
//		scoreText.setCharacterSize(50);
//		scoreText.setFillColor(sf::Color::White);
//		scoreText.setPosition(700, 425);
//		Lines.setFont(font);
//		Lines.setString("Level Lines: " + std::to_string(lines));
//		Lines.setCharacterSize(50);
//		Lines.setFillColor(sf::Color::White);
//		Lines.setPosition(700, 575);
//		TotalLines.setFont(font);
//		TotalLines.setString("Total Lines: " + std::to_string(sc / 100));
//		TotalLines.setCharacterSize(50);
//		TotalLines.setFillColor(sf::Color::White);
//		TotalLines.setPosition(700, 725);
//		diplayname.setFont(font);
//		diplayname.setCharacterSize(50);
//		diplayname.setFillColor(Color::White);
//		diplayname.setPosition(700, 125);
//		window->draw(back);
//		window->draw(a1);
//		window->draw(a2);
//		window->draw(a4);
//		window->draw(a3);
//		window->draw(a5);
//		window->draw(diplayname);
//		window->draw(scoreText);
//		window->draw(Lines);
//		window->draw(Level);
//		window->draw(TotalLines);
//	}
//	bool game()
//	{
//		loadScores();
//		sortNumbersDescending(inputFileName, outputFileName);
//		return window->isOpen();
//	}
//	void setup()
//	{
//		speed = 1;
//		bool key = 0;
//		window->clear(sf::Color(0, 0, 0, 0));
//		while (window->pollEvent(evt))
//		{
//			if (!nameEntered)
//			{
//				inputName();
//			}
//			else
//			{
//				if (evt.type == sf::Event::Closed)
//					window->close();
//				if (Keyboard::isKeyPressed(Keyboard::Key::Right))
//					grid.right();
//				else if (Keyboard::isKeyPressed(Keyboard::Key::Left))
//					grid.left();
//				else if (Keyboard::isKeyPressed(Keyboard::Key::Up))
//					grid.rotate();
//				else if (Keyboard::isKeyPressed(Keyboard::Key::Down) && evt.type == sf::Event::KeyPressed)
//					key = 1;
//				else if (Keyboard::isKeyPressed(Keyboard::Key::Down) && evt.type == sf::Event::KeyReleased)
//					key = 0;
//			}
//		}
//		if (grid.next())
//		{
//			lines = lines + grid.lineclearing(s);
//			sc = sc + s;
//			grid.t();
//		}
//		if (key == 1)
//		{
//			speed = 0.01;
//		}
//		if (Clock.getElapsedTime().asSeconds() >= speed)
//		{
//			if (grid.chckend() == false)
//			{
//				sleep(seconds(0.5));
//				int n = sc;
//				saveScore(n);
//				window->clear();
//				displayScores();
//				window->display();
//				sleep(seconds(3));
//				window->clear();
//				grid.filling();
//				sc = 0;
//				level = 1;
//				lines = 0;
//			}
//			grid.move();
//			Clock.restart();
//		}
//		scoring();
//		format();
//	}
//
//	void disp()
//	{
//		window->display();
//	}
//	~play()
//	{
//		delete[]window;
//	}
//
//};