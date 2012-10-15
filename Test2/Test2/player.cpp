#include "DarkGDK.h"
#include "main.h"
#include "player.h"

const int PLAYER_SPRITE = 1;

int pAnim[12];
int playerH = 25;
int playerX = 8;
int playerY = 8;

int playerDir = 2; //0 = North (Up), 1 = East (Right), 2 = South (Down), 3 = West (Left)
int playerAnim = 0; //0, 1, 2. Allows appearance of movement.
int relativePosition = 0; //Used to make movement between tiles less... jumpy?
bool inMotion = false;

void playerSetup()
{
	for (int i = 0; i <= 12; i++)
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

int getPlayerDir()
{
	return playerDir;
}

int getPlayerAnimation()
{
	return playerAnim;
}

bool movePlayerUp()
{
	playerDir = 0;
	if (playerY > 0)
	{
		playerY -= 1;
		if (playerY < 0)
			playerY = 0;
		return true;
	}
	else
	{
		playerAnim = 2;
		return false;
	}
}

bool movePlayerDown()
{
	playerDir = 2;
	if (playerY < MAX_TILE_ROW)
	{
		playerY += 1;
		if (playerY > MAX_TILE_ROW)
			playerY = MAX_TILE_ROW;
		return true;
	}
	else
	{
		playerAnim = 2;
		return false;
	}
}

bool movePlayerLeft()
{
	playerDir = 3;
	if (playerX > 0)
	{
		playerX -= 1;
		if (playerX < 0)
			playerX = 0;
		return true;
	}
	else
	{
		playerAnim = 2;
		return false;
	}
}

bool movePlayerRight()
{
	playerDir = 1;
	if (playerX < MAX_TILE_COL)
	{
		playerX += 1;
		if (playerX > MAX_TILE_COL)
			playerX = MAX_TILE_COL;
		return true;
	}
	else
	{
		playerAnim = 2;
		return false;
	}
}

bool movePlayer( int x, int y )
{
	playerDir = 2;
	if (x > 0 && x < MAX_TILE_COL && y > 0 && y < MAX_TILE_ROW)
	{
		playerX = x;
		playerY = y;
		playerAnim = 0;
		return true;
	}
	else return false;
}

void playerNextAnimation()
{
	playerAnim++;
	if (playerAnim > 2)
		playerAnim = 0;
}

void resetPlayerAnimation()
{
	playerAnim = 2;
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