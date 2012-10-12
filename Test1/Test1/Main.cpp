#include "DarkGDK.h"
#include "main.h"
#include "player.h"

void gridLines();

void DarkGDK()
{

	playerSetup();

	dbSync();
	dbSyncRate(60);

	char* coor;

	while (LoopGDK())
	{
		dbCLS(dbRGB(0,0,0));
		gridLines();
		if (!playerInMotion())
		{
			if (dbUpKey() == 1)
			{
				movePlayerUp();
				coor = strcat(dbStr(getPlayerX() + 1)," : ");
				coor = strcat(coor,dbStr(getPlayerY() + 1));
				coor = strcat(coor," | " );
				coor = strcat(coor,dbStr(getPlayerAnim()));
				dbPrint(coor);
				dbPasteImage(getPlayerAnim(), getPlayerX() * 32, getPlayerY() * 32);
				dbWait(100);
			}
			if (dbDownKey() == 1)
			{
				movePlayerDown();
				coor = strcat(dbStr(getPlayerX() + 1)," : ");
				coor = strcat(coor,dbStr(getPlayerY() + 1));
				coor = strcat(coor," | " );
				coor = strcat(coor,dbStr(getPlayerAnim()));
				dbPrint(coor);
				dbPasteImage(getPlayerAnim(), getPlayerX() * 32, getPlayerY() * 32);
				dbWait(100);
			}
			if (dbRightKey() == 1)
			{
				movePlayerRight();
				coor = strcat(dbStr(getPlayerX() + 1)," : ");
				coor = strcat(coor,dbStr(getPlayerY() + 1));
				coor = strcat(coor," | " );
				coor = strcat(coor,dbStr(getPlayerAnim()));
				dbPrint(coor);
				dbPasteImage(getPlayerAnim(), getPlayerX() * 32, getPlayerY() * 32);
				dbWait(100);
			}
			if (dbLeftKey() == 1)
			{
				movePlayerLeft();
				coor = strcat(dbStr(getPlayerX() + 1)," : ");
				coor = strcat(coor,dbStr(getPlayerY() + 1));
				coor = strcat(coor," | " );
				coor = strcat(coor,dbStr(getPlayerAnim()));
				dbPrint(coor);
				dbPasteImage(getPlayerAnim(), getPlayerX() * 32, getPlayerY() * 32);
				dbWait(100);
			}
		}
		dbPasteImage(getPlayerAnim(), getPlayerX() * 32, getPlayerY() * 32);
	}
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