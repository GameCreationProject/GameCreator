#include "DarkGDK.h"
#include "main.h"
#include "player.h"


bool PLAYER_MOVED = false;

void checkMovement();
void gridLines();
void drawPlayer();

void DarkGDK()
{
	dbSetImageColorKey(84,138,150);

	playerSetup();

	dbSync(); 
	dbSyncRate(60);

	while (LoopGDK())
	{
		dbClear(0,0,0);

		checkMovement();
	}
}

void checkMovement()
{
	PLAYER_MOVED = false;
		
		if (!playerInMotion())
		{
			if (dbUpKey() == 1)
			{
				char* coor;
				for (int i = 1; i <= 4; i++)
				{
					movePlayerUp();
					drawPlayer();
					dbWait(50);
				}
				resetPlayerAnimation();
				coor = strcat(dbStr(getPlayerX() + 1)," : ");
				coor = strcat(coor,dbStr(getPlayerY() + 1));
				coor = strcat(coor," | " );
				coor = strcat(coor,dbStr(getPlayerAnim()));
				dbPrint(coor);
				PLAYER_MOVED = true;
			}
			if (dbDownKey() == 1)
			{
				char* coor;
				for (int i = 1; i <= 4; i++)
				{
					movePlayerDown();
					drawPlayer();
					dbWait(50);
				}
				resetPlayerAnimation();
				coor = strcat(dbStr(getPlayerX() + 1)," : ");
				coor = strcat(coor,dbStr(getPlayerY() + 1));
				coor = strcat(coor," | " );
				coor = strcat(coor,dbStr(getPlayerAnim()));
				dbPrint(coor);
				PLAYER_MOVED = true;
			}
			if (dbRightKey() == 1)
			{
				char* coor;
				for (int i = 1; i <= 4; i++)
				{
					movePlayerRight();
					drawPlayer();
					dbWait(50);
				}
				resetPlayerAnimation();
				coor = strcat(dbStr(getPlayerX() + 1)," : ");
				coor = strcat(coor,dbStr(getPlayerY() + 1));
				coor = strcat(coor," | " );
				coor = strcat(coor,dbStr(getPlayerAnim()));
				dbPrint(coor);
				PLAYER_MOVED = true;
			}
			if (dbLeftKey() == 1)
			{
				for (int i = 1; i <= 4; i++)
				{
					movePlayerLeft();
					drawPlayer();
					dbWait(50);
				}
				resetPlayerAnimation();
				PLAYER_MOVED = true;
			}
			
			dbPasteImage(getPlayerAnim(), getPlayerX() * 8, getPlayerY() * 8);
			if (PLAYER_MOVED == true)
			{
				//dbWait(80);
			}
		}
}

void drawPlayer()
{
	dbCLS(dbRGB(0,0,0));
	//gridLines();
	char* coor;
	coor = strcat(dbStr(getPlayerX() / 4 + 1)," : ");
	coor = strcat(coor,dbStr(getPlayerY() / 4 + 1));
	coor = strcat(coor," | " );
	coor = strcat(coor,dbStr(getPlayerAnim()));
	dbPrint(coor);
	playerNextAnimation();
	dbPasteImage(getPlayerAnim(), getPlayerX() * 8, getPlayerY() * 8 - 1);
}

void gridLines()
{
	for (int q = 0; q <= 640; q += 32)
	{
		for (int r = 0; r <= 480; r += 32)
		{
			dbLine(q, r, q, r + 480);
			dbLine(q, r, q + 640, r);
		}
	}
}