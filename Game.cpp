#include "Game.h"
#include "GameConfig.h"
#include "CMUgraphicsLib/auxil.h"
#include "Tanker.h"
#include "Jets.h"
#include "helicopter.h"
#include "bridge.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

Game::Game()


{
	
	//1 - Create the main window
	pWind = CreateWind(config.windWidth, config.windHeight, config.wx, config.wy);

	//2 - create and draw the toolbar
	createToolbar();
	

	//3 - create and draw the backgroundPlayingArea
	point bg;
	bg.x = 0;
	bg.y = 50;
	background = new Background(this , bg , 1200 , 500, BLUE , BLUE );
	
	

	point r_point;
	int windowWidth = config.windWidth;
	int windowHeight = config.windHeight;
	int planeWidth = 50;
	int planeHeight = 100;
	// Calculate center-bottom position
	point planePoint;
	planePoint.x = (windowWidth - planeWidth) / 2; // Center horizontally
	planePoint.y = windowHeight - planeHeight - 100; // 20px above the bottom
	int speed = 20;
	plane1 = new Plane(this, planePoint, planeWidth, planeHeight, BLUE, BLACK, speed);
	plane1->draw();

	bullets.clear();

	clearStatusBar();

	/*fuels.clear(); 
	for (int i = 0; i < 3; i++) {
		point start;
		start.x = 100 + rand() % 500;
		start.y = 100 + rand() % 500;
		Fuel* f = new Fuel(this, start, 50, 80, YELLOW, RED);
		fuels.push_back(f);
		f->draw();
	}*/

	fuelGauge = 50.0f;          
	fuelDrainPerFrame = 0.02f;
	gameSpeed = 2;
	isMoving = true; 
	fuels.clear();
	for (int i = 0; i < 3; i++) {
		point start;
		start.x = 100 + rand() % 500;
		start.y = 100 + rand() % 500;
		Fuel* f = new Fuel(this, start, 50, 80, YELLOW, RED);
		fuels.push_back(f);
		f->draw();
	}

	
	/*bullet = new Bullet(400, 200);
	bullet->drawbullet(pWind);*/
	isPaused = false;
	point fueel;
	fueel.x = windowWidth/2;
	fueel.y = 70;
	fuel = new Fuel(this, fueel, 30, 40, BLUE, RED);

}

Game::~Game()
{
	for (Bullet* b: bullets)
	{
		delete b;
	}
	bullets.clear();
	for (Enemy* e : enemies)
	{
		delete e;
	}
	for (Fuel* f : fuels) delete f;
	fuels.clear();
	enemies.clear();
	delete plane1;
	delete gameToolbar;
	delete pWind;

}

clicktype Game::getMouseClick(int& x, int& y) const
{
	return pWind->WaitMouseClick(x, y);	//Wait for mouse click

}

string Game::getSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		printMessage(Label);
	}
}

window* Game::CreateWind(int w, int h, int x, int y) 
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(config.bkGrndColor);
	pW->SetPen(config.bkGrndColor, 1);
	pW->DrawRectangle(0, 0, w, h);
	return pW;
}

void Game::createToolbar() 
{
	point toolbarUpperleft;
	toolbarUpperleft.x = 0;
	toolbarUpperleft.y = 0;

	gameToolbar = new Toolbar(this, toolbarUpperleft, 0, config.toolBarHeight);
	gameToolbar->draw();
}

void Game::drawStatusBar()
{
	window* w = pWind;

	// Clear status bar area
	clearStatusBar();

	w->SetPen(WHITE, 2);
	w->SetFont(20, BOLD, BY_NAME, "Arial");

	int yPos = config.windHeight - config.statusBarHeight + 5;
	int columnWidth = config.windWidth / 4;

	// Draw Points
	w->DrawString(10, yPos, "Points: " + to_string(this->getscore()));

	// Draw Game Speed
	w->DrawString(columnWidth, yPos, "Speed: " + to_string(this->getspeed()));

	// Draw Lives
	w->DrawString(columnWidth * 2, yPos, "Lives: " + to_string(lives));

	// Draw Fuel
	w->DrawString(columnWidth * 3, yPos, "Fuel: " + to_string(this->getFuelgauge()));
}

void Game::clearStatusBar() const
{
	//Clear Status bar by drawing a filled rectangle
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
}

void Game::addBullet(Bullet* newbullet)
{
	bullets.push_back(newbullet);
}

void Game::updateBullets()
{

	window* w = getWind();

	// Erase all bullets from their current positions
	for (Bullet* b : bullets) {
		point pos = b->getRefPoint();
		w->SetPen(LIGHTBLUE);  // Background color to erase
		w->SetBrush(LIGHTBLUE);
		w->DrawTriangle(pos.x, pos.y,
			pos.x + 20, pos.y,
			pos.x + 10, pos.y + 30);
	}

	// Update positions and redraw bullets
	for (int i = 0; i < bullets.size(); ) {
		Bullet* b = bullets[i];
		b->moveUp(50);  //

		// Redraw bullet
		b->draw();

		// Check if bullet is off-screen
		if (b->getRefPoint().y < 0) {
			point pos = b->getRefPoint();
			w->SetPen(LIGHTBLUE);
			w->SetBrush(LIGHTBLUE);
			w->DrawTriangle(pos.x, pos.y,
				pos.x + 20, pos.y,
				pos.x + 10, pos.y + 30);
			delete b;
			bullets.erase(bullets.begin() + i);
			i--;

		}
		else {
			++i;
		}
	}

	// Update window buffer and pause for animation
	w->UpdateBuffer();
	

        }

void Game::launch_bullets()
{
	char cKeyData;
	keytype kType = pWind->GetKeyPress(cKeyData);
	

	if ((kType == ASCII) && (cKeyData == ' ')) {
		point bulletpos = { plane1->getRefPoint().x + plane1->getWidth() / 2, plane1->getRefPoint().y };
		Bullet* newBullet = new Bullet(this, bulletpos);
		addBullet(newBullet);
	}
}



void Game::generate_enemys(int level)
{
	float difficulty = 1 + (points / 1000.0);
	double Cooldown = 3;
	double enemyGenCooldown = Cooldown - (level * 0.2);
	float tempCooldown = 3.0f - points * 0.002f;
	// Update spawn cooldown (at least 0.5 seconds)
	spawnTimer = 3.0f - (points * 0.002f);
	if (spawnTimer < 0.5f) spawnTimer = 0.5f;

	// Update enemy speed (up to 8.0)
	float currentSpeed = enemySpeed + (points * 0.005f);
	if (currentSpeed > 8.0f) currentSpeed = 8.0f;


	if (double(clock() - lastEnemyGenTime) / ((clock_t)1000) < enemyGenCooldown)
		return;





	lastEnemyGenTime = clock();
	int baseCount = 1;
	int totalEnemies = baseCount * level;
	int enemiesToSpawn = 1 + (points / 500); // More enemies at higher scores
	for (int i = 0; i < enemiesToSpawn; i++) {
		for (int i = 0; i < totalEnemies; ++i) {
			int type = rand() % 4;
			point pos{ 300 + rand() % (900 - 300), 50 + rand() % (300 - 50) };



			switch (type) {
			case 0:

				pE = new Jets(this, pos, 100, 50, RED, BLACK);
				break;
			case 1:
				pE = new Tanker(this, pos, 80, 60, BLUE, WHITE);
				break;
			case 2:
				pE = new helicopter(this, pos, 120, 30, GREEN, BLACK);
				break;
			case 3:
				pE = new Bridge(this, pos, 150, 40, GRAY, BLACK);
				break;
			default:
				pE = nullptr;
				break;
			}

			if (pE) {
				pE->setSpeed(currentSpeed);
				enemies.push_back(pE);

			}
		}
	}
}
void Game::setIsMoving(bool state)
{
	isMoving = state;
}


void Game::updateEnemies()
{
	for (int i = 0; i < enemies.size(); )
	{
		Enemy* enemy = enemies[i];

		enemy->erase(pWind);
		enemy->move();
		enemy->draw();

		point pos = enemy-> getRefPoint();
		if (pos.y > config.windHeight) {
			delete enemy;
			enemies.erase(enemies.begin() + i);
			continue;  
		}

		++i;
	}
}



void Game::printMessage(string msg) const
{
	clearStatusBar();	//First clear the status bar

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - (int)(0.85 * config.statusBarHeight), msg);

}

window* Game::getWind() const
{
	return pWind;
}

vector <Bullet*> Game::getbullet() const
{
	return bullets;
}

void Game::UpdateScore(int scoreadded)
{
	score = score + scoreadded;
	//add a line to draw this score in the status bar.
}

int Game::getscore()
{
	return score;
}

void Game::removeEnemy(Enemy* e)
{
	/*window* w = getWind();*/
	

	auto it = std::find(enemies.begin(), enemies.end(), e);
	
	if (it != enemies.end()) {
		delete* it;
		enemies.erase(it);
		

	}



}

void Game::removeFuel(Fuel* e)
{
	auto it = std::find(fuels.begin(), fuels.end(), e);

	if (it != fuels.end()) {
		delete* it;
		fuels.erase(it);


	}

}

void Game::saveGame(string filename)
{
	fstream outFile("IO files\\" + filename + ".txt", ios::out);

	// Save player position
	point planePos = plane1->getRefPoint();
	outFile << "PLANE " << planePos.x << " " << planePos.y << endl;

	// Save score
	outFile << "SCORE " << score << endl;

	// Save bullets
	outFile << "BULLETS " << bullets.size() << endl;
	for (auto* b : bullets) {
		point pos = b->getRefPoint();
		outFile << pos.x << " " << pos.y << endl;
	}

	// Save enemies
	outFile << "ENEMIES " << enemies.size() << endl;
	for (auto* e : enemies) {
		point pos = e->getRefPoint();
		outFile << static_cast<int>(e->getType()) << " " << pos.x << " " << pos.y << endl;
	}

	outFile.close(); // Always close after writing
	printMessage("Game saved successfully.");

}

void Game::resetGame()
{

	// 1. Clear bullets
	for (Bullet* b : bullets) {
		delete b;
	}
	bullets.clear();

	// 2. Clear enemies
	for (Enemy* e : enemies) {
		delete e;
	}
	enemies.clear();

	// 3. Reset player position
	point r_point;
	int windowWidth = config.windWidth;
	int windowHeight = config.windHeight;
	int planeWidth = 50;
	int planeHeight = 100;
	// Calculate center-bottom position
	point planePoint;
	planePoint.x = (windowWidth - planeWidth) / 2; // Center horizontally
	planePoint.y = windowHeight - planeHeight - 100; // 20px above the bottom
	int speed = 20;
	plane1->erasePreviousPosition(pWind);
	plane1->setRefPoint(planePoint);

	// 4. Reset score
	score = 0;

	//if we were to include game level
	isPaused = false; // Make sure game isn't paused


}

void Game::loadGame(string filename)
{


	// 1. Clear current game state
	for (Bullet* b : bullets) delete b;
	bullets.clear();

	for (Enemy* e : enemies) delete e;
	enemies.clear();

	// Optional: Clear fuels or other collectibles
	for (Fuel* f : fuels) delete f;
	fuels.clear();

	// 2. Open the file
	fstream inFile("IO files\\" + filename + ".txt", ios::in);
	if (!inFile.is_open()) {
		printMessage("Failed to load file!");
		return;
	}

	string line;
	while (getline(inFile, line)) {
		istringstream iss(line);
		string objType;
		iss >> objType;

		if (objType == "PLANE") {
			int x, y;
			iss >> x >> y;
			point planePos = { x, y };
			plane1->setRefPoint(planePos);
		}
		else if (objType == "SCORE") {
			int s;
			iss >> s;
			score = s;
		}
		else if (objType == "BULLETS") {
			int count;
			iss >> count;

			for (int i = 0; i < count; ++i) {
				int x, y;
				inFile >> x >> y;
				point pos = { x, y };
				bullets.push_back(new Bullet(this, pos));
			}
		}
		else if (objType == "ENEMIES") {
			int count;
			iss >> count;

			for (int i = 0; i < count; ++i) {
				int typeInt, x, y;
				inFile >> typeInt >> x >> y;

				GameObjectType type = static_cast<GameObjectType>(typeInt);
				point pos = { x, y };

				switch (type) {
				case GameObjectType::JET_ENEMY:
					enemies.push_back(new Jets(this, pos, 100, 50, RED, BLACK));
					break;
				case GameObjectType::TANKER_ENEMY:
					enemies.push_back(new Tanker(this, pos, 80, 60, BLUE, WHITE));
					break;
				case GameObjectType::HELICOPTER_ENEMY:
					enemies.push_back(new helicopter(this, pos, 120, 30, GREEN, BLACK));
					break;
				case GameObjectType::BRIDGE_ENEMY:
					enemies.push_back(new Bridge(this, pos, 150, 40, GRAY, BLACK));
					break;
				default:
					continue;
				}
			}
		}
	}

	inFile.close();
	printMessage("Game loaded successfully.");


}

void Game::handlecollision()
{
	window* w = getWind();
	for (size_t i = 0; i < bullets.size(); ++i) {
		Bullet* b = bullets[i];
		for (size_t j = 0; j < enemies.size(); ++j) {
			Enemy* e = enemies[j];
			if (b->CollisionDetection(*e)) {
				cout << "HIT DETECTED!" << endl;
				e->collisionAction(); // Destroy enemy and update score
				// b->collisionAction(); 
					point pos = b->getRefPoint();
				w->SetPen(LIGHTBLUE);
				w->SetBrush(LIGHTBLUE);
				w->DrawTriangle(pos.x, pos.y,
					pos.x + 20, pos.y,
					pos.x + 10, pos.y + 30);
				delete b;
				bullets.erase(bullets.begin() + i);
				i--;


			}
		}
	}
	for (size_t i = 0; i < bullets.size(); ++i) {
		Bullet* b = bullets[i];
		for (size_t j = 0; j < fuels.size(); ++j) {
			Fuel* e = fuels[j];
			if (b->CollisionDetection(*e)) {
				cout << "HIT DETECTED!" << endl;
				e->collisionAction(); // Destroy enemy and update score
				// b->collisionAction(); 
				point pos = b->getRefPoint();
				w->SetPen(LIGHTBLUE);
				w->SetBrush(LIGHTBLUE);
				w->DrawTriangle(pos.x, pos.y,
					pos.x + 20, pos.y,
					pos.x + 10, pos.y + 30);
				delete b;
				bullets.erase(bullets.begin() + i);
				i--;


			}
		}
	}
}

int Game::getspeed()
{
	return gameSpeed;
}

int Game::getFuelgauge()
{
	return fuelGauge;
}

void Game::showfuel()
{
	window* w = getWind();
	for (int i = 0; i < fuels.size(); ) {
		Fuel* b = fuels[i];
		
		b->draw();

	}

	
}

void Game::go()
{
	//This function reads the position where the user clicks to determine the desired operation
	int x, y;
	bool isExit = false;
	int level = 1;
	int score = 0;
	int speed = 2;

	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - River Raid (CIE101-project) - - - - - - - - - -");

	do

	{
		gameToolbar->draw();
		if (!isPaused) {
			background->scrollDown(speed);
			background->draw();
			fuel->draw();
			

			for (Fuel* f : fuels) {
				if (!f->isDestroyed()) {
					f->draw();
				}
			}
			if (fuelGauge <= 20.0f && fuelGauge > 0.0f) {
				string msg = "Low fuel: " ;
				pWind->SetPen(RED);
				pWind->DrawString(config.windWidth / 2 - 50, 20, msg);
			}
			if (!isPaused && isMoving) {
				// Drain fuel only when moving
				fuelGauge -= fuelDrainPerFrame;
				if (fuelGauge <= 0.0) {
					printMessage("Out of fuel! ");
					isPaused = true;
				}
			}

			
			for (Fuel* f : fuels) {
				if (plane1->CollisionDetection(*f)) {
					fuelGauge += 20.0f;
					if (fuelGauge > 100.0f) fuelGauge = 100.0f;
					f->markDestroyed();
				}
			}


			pWind->SetPen(config.bkGrndColor);
			pWind->SetBrush(config.bkGrndColor);
			plane1->erasePreviousPosition(pWind);
			plane1->updateposition();
			plane1->draw();
			pWind->SetPen(config.bkGrndColor);
			pWind->SetBrush(config.bkGrndColor);


			
			generate_enemys(level);

			updateEnemies();
			
			handlecollision();
			for (Enemy* enemy : enemies) {
				enemy->draw();
			}
			/* for (Fuel f : fuels) {

				if (f != nullptr) {
					f->draw();
				}
			}*/

				launch_bullets();
			updateBullets();
			/*Pause(3);*/
			static clock_t lastSpeedIncrease = clock();
			if ((clock() - lastSpeedIncrease) > 5000) {
				speed++;
				lastSpeedIncrease = clock();
			}
			
			for (int i = 0; i < fuels.size(); ) {
				if (fuels[i]->isDestroyed()) {
					delete fuels[i];
					fuels.erase(fuels.begin() + i);
				}
				else {
					++i;
				}
			}
			drawStatusBar();

		}
		if (isPaused) {
			printMessage("Game Paused");
		}
		pWind->GetMouseClick(x, y);
		if (y >= 0 && y < config.toolBarHeight)
		{
			isExit = gameToolbar->handleClick(x, y);
		}
		if (y >= 0 && y < config.toolBarHeight)
		{
			isExit = gameToolbar->handleClick(x, y);
		}
		// Display another message
		/*/ printMessage("Ready..."); /*/

	} while (!isExit);

}


