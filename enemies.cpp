
#include "enemies.h"
#include "Game.h"







void Game :: drawEnemyShip(window* pWind, int x, int y)
{
	pWind->SetPen(BLACK, 1);
	pWind->SetBrush(DARKRED);
	pWind->DrawRectangle(x - 75, y + 45, x + 75, y + 65, FILLED);
	pWind->SetBrush(GRAY);
	pWind->DrawRectangle(x - 60, y + 30, x + 60, y + 45, FILLED);
	pWind->DrawRectangle(x - 30, y + 15, x + 30, y + 30, FILLED);
	pWind->DrawRectangle(x, y, x + 30, y + 15, FILLED);
	pWind->SetBrush(STEELBLUE);
	pWind->DrawRectangle(x - 50, y + 65, x + 50, y + 80, FILLED);
}


void Game :: drawBridge(window* pWind, int x, int y, int width, int height)
{

	pWind->SetPen(BLACK, 1);
	pWind->SetBrush(DARKGRAY);
	pWind->DrawRectangle(x, y, x + width, y + height);


	pWind->SetPen(WHITE, 2);
	for (int i = x + 10; i < x + width; i += 30) {
		pWind->DrawLine(i, y + height / 2, i + 20, y + height / 2);
	}
}


void Game :: generateRandomEnemy(int& x, int& y) {
	int w, h;
	x = rand() % w;
	y = rand() % h;
}

