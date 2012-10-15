#include "DarkGDK.h"

type_TextBox textBoxes[20];

void DarkGDK()
{
	dbSetTextFont("Courier");

	while (LoopGDK())
	{
		
	}
}

char* drawTextBox( int ID, int x, int y, int width, int height );
{
	if (ID == 0)
	{
		for (int i = 1; i <= 20, i++)
		{
			if (!textBoxes[20].isLoaded)
			{
				textBoxes[20].isLoaded = true;
				textBoxes[20].x = x;
				textBoxes[20].y = y;
				textBoxes[20].width = width;
				textBoxes[20].height = height;
				textBoxes[20].text = "";
			}
			else if (i >= 20)
			{
				//Well crap all the text boxes are loaded.... Ermmm... this is awkward.
			}
		}
	}
}

bool checkMessageBox(int id)
{
	if (dbMouseX() > textBoxes[id].x && dbMouseX() < (textBoxes[id].x + textBoxes[id].width))
	{
		if (dbMouseY() > textBoxes[id].y && dbMouseY() < (textBoxes[id].y + textBoxes[id].height))
		{
			
		}
	}
}