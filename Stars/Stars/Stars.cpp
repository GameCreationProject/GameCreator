#include "DarkGDK.h"
#include "Stars.h"

struct typeStar
{
	int x;
	int y;
	int radius;
	int direction;
	int moving;
	int speed;
};

typeStar stars[50];

void drawStars();
void loadStars();
void dbFillCircle( int, int, int );
int randomNumber( int );

void DarkGDK()
{
	dbSetWindowOff();

	dbSync();
	dbSyncRate(60);
	loadStars();

	while (LoopGDK())
	{
		dbCLS(dbRGB(0,0,0));

		dbSync();

		dbInk(dbRGB(255,255,255), dbRGB(255,255,255));
		drawStars();

		if (dbEscapeKey() == 1)
		{
			break;
		}
	}
}

void drawStars()
{
	 for ( int i = 1; i <= 50; i++)
	 {
		 if (stars[i].moving)
		 {
			switch (stars[i].direction)
			{
				case 0:
					stars[i].y -= stars[i].speed;
					break;
				case 1:
					stars[i].x += stars[i].speed;
					break;
				case 2:
					stars[i].y += stars[i].speed;
					break;
				case 3:
					stars[i].x -= stars[i].speed;
					break;
			}
		}
		/*if (i == 1 || i == 2 || i == 3)
		{
			char* coor;
			coor = dbStr(stars[i].x);
			coor = strcat(coor, " : ");
			coor = strcat(coor, dbStr(stars[i].y));
			coor = strcat(coor, " | ");
			coor = strcat(coor, dbStr(stars[i].speed));
			coor = strcat(coor, " | ");
			coor = strcat(coor, dbStr(stars[i].direction));
			coor = strcat(coor, " | ");
			coor = strcat(coor, dbStr(stars[i].radius));
			dbPrint(coor);
		}*/
		dbBox( stars[i].x, stars[i].y, stars[i].x + stars[i].radius, stars[i].y + stars[i].radius );

	 }
}

void loadStars()
{
	for ( int i = 1; i <= 50; i++ )
	{
		stars[i].x = randomNumber( dbScreenWidth() );
		stars[i].y = randomNumber( dbScreenHeight() );
		stars[i].direction = randomNumber( 3 );
		stars[i].radius = randomNumber( 5 );
		stars[i].moving = randomNumber( 1 );
		stars[i].speed = randomNumber( 10 );
	}
}

void dbFillCircle(int centerX, int centerY, int radius)
{
	for (int x = 1; x <= radius; x += 1)
	{
		dbEllipse(centerX, centerY, x, x);
	}
}

int randomNumber( int maximum )
{
	dbRandomize( dbTimer() );
	return dbRnd( maximum );
}