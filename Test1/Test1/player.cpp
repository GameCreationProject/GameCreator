#include "DarkGDK.h"
#include "main.h"
#include "player.h"

int pAnim[12];
int playerH = 25;
int playerX = 5;
int playerY = 5;

int playerDir = 2; //0 = North (Up), 1 = East (Right), 2 = South (Down), 3 = West (Left)
int playerAnim = 0; //0, 1, 2. Allows appearance of movement.
int relativePosition = 0; //Used to make movement between tiles less... jumpy?
bool inMotion = false;

void playerSetup()
{
	for (int i = 1; i <= 12; i++)
	{
		pAnim[i] = i;
		
		dbLoadImage(strcat(dbStr(i),".bmp"), pAnim[i]);
	}
}

bool playerInMotion()
{
	return inMotion;
}

int getPlayerHealth()
{
	return playerH;
}

int getPlayerX()
{
	return playerX;
}

int getPlayerY()
{
	return playerY;
}

bool movePlayerUp()
{
	if (playerY > 0)
	{
		playerY -= 1;
		playerDir = 0;
		playerAnim = 0;
		return true;
	}
	else return false;
}

bool movePlayerDown()
{
	if (playerY < MAX_TILE_ROW)
	{
		playerY += 1;
		playerDir = 2;
		playerAnim = 0;
		return true;
	}
	else return false;
}

bool movePlayerLeft()
{
	if (playerX > 0)
	{
		playerX -= 1;
		playerDir = 3;
		playerAnim = 0;
		return true;
	}
	else return false;
}

bool movePlayerRight()
{
	if (playerX < MAX_TILE_COL)
	{
		playerX += 1;
		playerDir = 1;
		playerAnim = 0;
		return true;
	}
	else return false;
}

bool movePlayer( int x, int y )
{
	if (x > 0 && x < MAX_TILE_COL && y > 0 && y < MAX_TILE_ROW)
	{
		playerX = x;
		playerY = y;
		playerDir = 2;
		playerAnim = 0;
		return true;
	}
	else return false;
}

int getPlayerAnim()
{
	switch (playerDir)
	{
		case 0:
			return playerAnim + 1;
			break;
		case 1:
			return playerAnim + 10;
			break;
		case 2:
			return playerAnim + 4;
			break;
		case 3:
			return playerAnim + 7;
			break;
		default:
			return 1;
	}

}