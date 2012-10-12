#include "DarkGDK.h"
#include "main.h"
#include "player.h"

const int PLAYER_SPRITE = 1;
bool PLAYER_MOVED = false;

void gridLines();

void DarkGDK()
{
	playerSetup();

	dbSync();
	dbSyncRate(60);

	while (LoopGDK())
	{
		PLAYER_MOVED = false;
		dbCLS(dbRGB(0,0,0));
		gridLines();
		if (!playerInMotion())
		{
			if (dbUpKey() == 1)
			{
				char* coor;
				for (int i = 1; i <= 4; i++)
				{
					movePlayerUp();
					drawPlayer();
				}
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
				}
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
				}
				coor = strcat(dbStr(getPlayerX() + 1)," : ");
				coor = strcat(coor,dbStr(getPlayerY() + 1));
				coor = strcat(coor," | " );
				coor = strcat(coor,dbStr(getPlayerAnim()));
				dbPrint(coor);
				PLAYER_MOVED = true;
			}
			if (dbLeftKey() == 1)
			{
				char* coor;
				for (int i = 1; i <= 4; i++)
				{
					movePlayerLeft();
					drawPlayer();
				}
				coor = strcat(dbStr(getPlayerX() + 1)," : ");
				coor = strcat(coor,dbStr(getPlayerY() + 1));
				coor = strcat(coor," | " );
				coor = strcat(coor,dbStr(getPlayerAnim()));
				dbPrint(coor);
				PLAYER_MOVED = true;
			}
			
			//dbPasteImage(getPlayerAnim(), getPlayerX() * 8, getPlayerY() * 8);
			if (PLAYER_MOVED == true)
			{
				dbWait(80);
			}
		}
	}
}

void drawPlayer()
{
	dbPasteImage(getPlayerAnim(), getPlayerX() * 8, getPlayerY() * 8 - 2);
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