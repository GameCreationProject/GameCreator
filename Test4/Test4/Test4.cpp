#include "DarkGDK.h"

void DarkGDK()
{
	dbSetWindowOff();

	dbSync();
	dbSyncRate(60);

	while (LoopGDK())
	{
		dbCLS(dbRGB(0,0,0));

		dbSync();

		dbInk(dbRGB(255,255,255), dbRGB(255,255,255));
		dbCircle (100,100,50); 

		if (dbMouseX() > 100 && dbMouseX() < 150)
		{
			if (dbMouseY() > 100 && dbMouseY() < 150)
			{
				if (dbMouseClick() == 1)
				{
					dbPrint("CLICK!");
				}
			}
		}

		if (dbEscapeKey() == 1)
		{
			 break;
		}
	}
}