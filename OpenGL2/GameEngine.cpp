#include "GameEngine.h"


void GameEngine::Run()
{
	isRunning = true; 

	while(isRunning)
	{
		Process(); 
		Update(); 
		Render(); 
	}
}