#ifndef _GAMEENGINE_H_
#define _GAMEENGINE_H_

class GameEngine
{
private:
	static GameEngine engine; 

	void Run(); 
	
public:
	bool isRunning; 
	void Process(); 
	void Update();
	void Render(); 
	static void Start(); 
	static void Stop(); 
};


#endif