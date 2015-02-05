#include <SDL.h>

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

class GridSquare {
	SDL_Surface *  gridTile;
	SDL_Rect renderSquare; 
	bool isOccupied;
	int tileType; 

public: 
	void init(int xpos, int ypos) {
		// The board starts empty, so this will be false
		isOccupied = false;
		// Create it's "renderSquare" that defines its x and y
		// position and height, relative to the screen size
		renderSquare.x = (int)(xpos * 0.375 * SCREEN_WIDTH);
		renderSquare.y = (int)(ypos * 0.05 * SCREEN_HEIGHT);
		renderSquare.w = (int)((0.375 * SCREEN_WIDTH) / 10.0);
		renderSquare.h = (int)(0.05 * SCREEN_HEIGHT);
	}

};

// The class for a tetris board, implemented as a singleton pattern
class TetrisBoard {
	
	TetrisBoard() {
		for (int i = 0; i < 10; i++) {
			for (int k = 0; k < 20; k++)
				gridSquares[i][k].init(i,k);
		}
	}
	
private: 
	GridSquare gridSquares[10][20];




};

