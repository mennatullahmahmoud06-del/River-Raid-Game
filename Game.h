#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "Toolbar.h"
#include "Tanker.h"
#include "Jets.h"	
#include "helicopter.h"
#include "bridge.h"
#include "Fuel.h"
#include "Bullet.h"
#include "Background.h"
#include "Plane.h"
#include <vector>
#include <ctime>
using namespace std;


class Game
{
private:
	window* pWind;	//Pointer to the CMU graphics window
	Toolbar* gameToolbar;
	Background* background;
	Plane* plane1;
	vector<Bullet*>bullets;
	helicopter* helicopter1;
	bool spacePressedLastFrame = false;
	vector<Enemy*> enemies;
	Enemy* pE = nullptr;
	clock_t lastEnemyGenTime;     
	double enemyGenCooldown;
	vector<Fuel*>fuels;
	Fuel* fuel;
	int score = 0;
	bool isPaused;
	int points = 0;
	int gameSpeed;
	int lives = 5;
	float fuelGauge ; //status bar        
	float spawnTimer = 3.0; // Time between enemy spawns (start at 3 seconds)
	float enemySpeed = 1.0; // Base enemy speed multiplier
	float fuelDrainPerFrame; // Adjust this value for drain speed
	bool isMoving = false;

public:
	~Game();
	Game();

	clicktype getMouseClick(int& x, int& y) const; //Get coordinate where user clicks and returns click type (left/right)
	string getSrting() const;	 //Returns a string entered by the user


	static window* CreateWind(int, int, int, int) ; //creates the game window
	void createToolbar();
	void clearStatusBar() const;	//Clears the status bar
	void addBullet(Bullet* newbullet);
	void updateBullets();
	void launch_bullets();
	void generate_enemys(int level);
	void drawStatusBar();
	void setIsMoving(bool state);

	void updateEnemies();

	void printMessage(string msg) const;	//Print a message on Status bar

	void go() ;

	window* getWind() const;		//returns a pointer to the graphics window

	vector <Bullet*> getbullet() const;
	void UpdateScore(int scoreadded);
	int getscore();
	void removeEnemy(Enemy* e);
	void removeFuel(Fuel* e);
	void saveGame( string filename);
	bool getIsPaused() const { return isPaused; }
	void setIsPaused(bool pause) { isPaused = pause; }
	void resetGame();
	void loadGame(string filename);
	void handlecollision();
	int getspeed();
	int getFuelgauge();
	void showfuel();

};

