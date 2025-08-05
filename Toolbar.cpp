#include "Toolbar.h"
#include "GameConfig.h"
#include "game.h"



ToolbarIcon::ToolbarIcon(Game* r_pGame, point r_point, int r_width, int r_height, string img_path) : Drawable(r_pGame, r_point, r_width, r_height)
{
	image_path = img_path;
}

void ToolbarIcon::draw() const
{
	//draw image of this object
	window* pWind = pGame->getWind();
	pWind->DrawImage(image_path, RefPoint.x, RefPoint.y, width, height);
}

RestartIcon::RestartIcon(Game* r_pGame, point r_point, int r_width, int r_height, string img_path) : ToolbarIcon(r_pGame, r_point, r_width, r_height, img_path)
{
}

void RestartIcon::onClick()
{
	//TO DO: add code for restarting the game here
	pGame->printMessage("Restarting game...");
	Sleep(500);
	pGame->resetGame();

}


PauseIcon::PauseIcon(Game* r_pGame, point r_point, int r_width, int r_height, string img_path) :ToolbarIcon(r_pGame, r_point, r_width, r_height, img_path)
{
}

void PauseIcon::onClick()
{
	// Add a code for pausingg the game
	pGame -> setIsPaused(true);
	pGame->printMessage("Game Paused");

}

ResumeIcon::ResumeIcon(Game* r_pGame, point r_point, int r_width, int r_height, string img_path) : ToolbarIcon(r_pGame, r_point, r_width, r_height, img_path)
{
	
}

void ResumeIcon::onClick()
{
	//TO DO: add code for Resuming the game here
	if (pGame->getIsPaused()) {
		pGame->setIsPaused(false);
		pGame->printMessage("Game Resumed");
	}
	else {
		pGame->printMessage("Game is not paused.");
	}
}

SaveIcon::SaveIcon(Game* r_pGame, point r_point, int r_width, int r_height, string img_path) : ToolbarIcon(r_pGame, r_point, r_width, r_height, img_path)
{
}

void SaveIcon::onClick()
{

	//TO DO: add code for Saving the game here
	pGame->printMessage("Enter file name to save design in:");
	string filename = pGame->getSrting(); // Get user input
	if (!filename.empty()) {
		pGame->saveGame(filename);       // Call save function
		pGame->printMessage("Game saved!");
	}
	else {
		pGame->printMessage("Save cancelled.");
	}
}

LoadIconn::LoadIconn(Game* r_pGame, point r_point, int r_width, int r_height, string img_path) : ToolbarIcon(r_pGame, r_point, r_width, r_height, img_path)
{
}

void LoadIconn::onClick()
{
	//TO DO: add code for Loading a save of the game here
	pGame->printMessage("Enter file name to load design from:");
	string filename = pGame->getSrting();
	pGame->loadGame(filename);
}

ExitIcon::ExitIcon(Game* r_pGame, point r_point, int r_width, int r_height, string img_path) : ToolbarIcon(r_pGame, r_point, r_width, r_height, img_path)
{
}

void ExitIcon::onClick()
{
	//TO DO: add code for cleanup and game exit here
}

//Toolbar::Toolbar(int iWidth, int iHeight, int y)
//    : iconWidth(iWidth ), iconHeight(iHeight), yPos(y){ }
//
//void Toolbar::draw(window& w, int windowWidth) {
//    w.SetFont(20, BOLD, BY_NAME, "Arial");
//
//    // Toolbar background
//    w.SetPen(LIGHTGRAY);
//    w.SetBrush(LIGHTGRAY);
//    w.DrawRectangle(0, 0, windowWidth, 50);
//
//    // Calculate positions for 5 icons
//    int spacing = windowWidth / 6; // Divide window into 6 parts to place 5 icons
//
//    // 1. Restart icon
//    int x1 = spacing - iconWidth / 2;
//    w.SetPen(BLACK);
//    w.SetBrush(GREEN);
//    int restartX[] = { x1, x1, x1 + iconWidth };
//    int restartY[] = { yPos, yPos + iconHeight, yPos + iconHeight / 2 };
//    w.DrawPolygon(restartX, restartY, 3, FILLED);
//    w.SetPen(BLACK);
//    w.DrawString(x1, yPos + iconHeight + 2, "Restart");
//
//    // 2. Pause icon 
//    int x2 = spacing * 2 - iconWidth / 2;
//    w.SetPen(BLACK);
//    w.SetBrush(BLUE);
//    w.DrawRectangle(x2, yPos, x2 + iconWidth / 3, yPos + iconHeight);
//    w.DrawRectangle(x2 + iconWidth * 2 / 3, yPos, x2 + iconWidth, yPos + iconHeight);
//    w.SetPen(BLACK);
//    w.DrawString(x2, yPos + iconHeight + 2, "Pause");
//
//    // 3. Resume icon
//    int x3 = spacing * 3 - iconWidth / 2;
//    w.SetPen(BLACK);
//    w.SetBrush(GREEN);
//    int resumeX[] = { x3, x3, x3 + iconWidth };
//    int resumeY[] = { yPos, yPos + iconHeight, yPos + iconHeight / 2 };
//    w.DrawPolygon(resumeX, resumeY, 3, FILLED);
//    w.SetPen(BLACK);
//    w.DrawString(x3, yPos + iconHeight + 2, "Resume");
//
//    // 4. Save icon
//    int x4 = spacing * 4 - iconWidth / 2;
//    w.SetPen(BLACK);
//    w.SetBrush(RED);
//    w.DrawRectangle(x4, yPos, x4 + iconWidth, yPos + iconHeight);
//    // white rectangle inside
//    w.SetPen(WHITE);
//    w.SetBrush(WHITE);
//    w.DrawRectangle(x4 + 10, yPos + 10, x4 + iconWidth - 10, yPos + iconHeight - 10);
//    w.SetPen(BLACK);
//    w.DrawString(x4, yPos + iconHeight + 2, "Save");
//
//    // 5. Load icon
//    int x5 = spacing * 5 - iconWidth / 2;
//    w.SetPen(BLACK);
//    w.SetBrush(YELLOW);
//    // Draw folder base
//    w.DrawRectangle(x5, yPos + 10, x5 + iconWidth, yPos + iconHeight);
//    w.DrawString(x5, yPos + iconHeight + 2, "Load");
//}


Toolbar::Toolbar(Game* r_pGame, point r_point, int r_width, int r_height) : Drawable(r_pGame, r_point, r_width, r_height)
{

	//First prepare List of images for each icon
	//To control the order of these images in the menu, reoder them in enum ICONS above	
	iconsImages[ICON_RESTART] = "images\\RESTART.jpg";
	iconsImages[ICON_PAUSE] = "images\\PAUSE.jpg";
	iconsImages[ICON_RESUME] = "images\\RESUME.jpg";
	iconsImages[ICON_SAVE] = "images\\SAVE.jpg";
	iconsImages[ICON_LOAD] = "images\\LOAD.jpg";
	iconsImages[ICON_EXIT] = "images\\EXIT.jpg";


	point p;
	p.x = 0;
	p.y = 0;

	iconsList = new ToolbarIcon * [ICON_COUNT];

	//For each icon in the tool bar create an object 
	iconsList[ICON_RESTART] = new RestartIcon(pGame, p, config.iconWidth, config.toolBarHeight, iconsImages[ICON_RESTART]);
	p.x += config.iconWidth;
	iconsList[ICON_PAUSE] = new PauseIcon(pGame, p, config.iconWidth, config.toolBarHeight, iconsImages[ICON_PAUSE]);
	p.x += config.iconWidth;
	iconsList[ICON_RESUME] = new ResumeIcon(pGame, p, config.iconWidth, config.toolBarHeight, iconsImages[ICON_RESUME]);
	p.x += config.iconWidth;
	iconsList[ICON_SAVE] = new SaveIcon(pGame, p, config.iconWidth, config.toolBarHeight, iconsImages[ICON_SAVE]);
	p.x += config.iconWidth;
	iconsList[ICON_LOAD] = new LoadIconn(pGame, p, config.iconWidth, config.toolBarHeight, iconsImages[ICON_LOAD]);
	p.x += config.iconWidth;
	iconsList[ICON_EXIT] = new ExitIcon(pGame, p, config.iconWidth, config.toolBarHeight, iconsImages[ICON_EXIT]);




}

Toolbar::~Toolbar()
{
	for (int i = 0; i < ICON_COUNT; i++)
		delete iconsList[i];
	delete iconsList;
}

void Toolbar::draw() const
{
	for (int i = 0; i < ICON_COUNT; i++)
		iconsList[i]->draw();
	window* pWind = pGame->getWind();
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, config.toolBarHeight, pWind->GetWidth(), config.toolBarHeight);
}

bool Toolbar::handleClick(int x, int y)
{
	if (x > ICON_COUNT * config.iconWidth)	//click outside toolbar boundaries
		return false;


	//Check whick icon was clicked
	//==> This assumes that menu icons are lined up horizontally <==
	//Divide x co-ord of the point clicked by the icon width (int division)
	//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

	int clickedIconIndex = (x / config.iconWidth);
	iconsList[clickedIconIndex]->onClick();	//execute onClick action of clicled icon

	if (clickedIconIndex == ICON_EXIT) return true;

	return false;

}