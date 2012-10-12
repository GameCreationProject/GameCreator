/*int playerExactX = 5 * 32;
int playerExactY = 5 * 32;

int getPlayerExactX()
{
	return playerExactX;
}

int getPlayerExactY()
{
	return playerExactY;
}

void updatePlayerPosition()
{
	playerExactX = playerRelX * 32;
	playerExactY = playerRelY * 32;
	setPlayerRelativePosition();
}

void setPlayerRelativePosition()
{
	if (inMotion)
	{
		switch (playerDir)
		{
			case 0:
				switch (relativePosition)
				{
					case 1:
						playerExactY = playerExactY - 8;
						relativePosition = 2;
						break;
					case 2:
						playerExactY = playerExactY - 16;
						relativePosition = 0;
						break;
					default:
						playerExactY -= 32;
						relativePosition = 1;
						break;
				}
				break;
			case 1:
				switch (relativePosition)
				{
					case 1:
						playerExactX = playerExactX + 8;
						relativePosition = 2;
						break;
					case 2:
						playerExactX = playerExactX + 16;
						relativePosition = 0;
						break;
					default:
						playerExactX += 32;
						relativePosition = 1;
						break;
				}
				break;
			case 2:
				switch (relativePosition)
				{
					case 1:
						playerExactY = playerExactY + 8;
						relativePosition = 2;
						break;
					case 2:
						playerExactY = playerExactY + 16;
						relativePosition = 0;
						break;
					default:
						playerExactY += 32;
						relativePosition = 1;
						break;
				}
				break;
			case 3:
				switch (relativePosition)
				{
					case 1:
						playerExactX = playerExactX - 8;
						relativePosition = 2;
						break;
					case 2:
						playerExactX = playerExactX - 16;
						relativePosition = 0;
						break;
					default:
						playerExactX -= 32;
						relativePosition = 1;
						break;
				}
				break;
			default:
				break;
		}
	}*/