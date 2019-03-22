#ifndef _GAME_H_
#define _GAME_H_

#include <vector>
#include "Idiom.h"
using std::vector;

class Game
{
	private:
		vector<Idiom> idiom;
	public:
		Game();
	   ~Game();
	    void Screen();
	    bool GetData();
	    void Play();
};
	    
	    
#endif
