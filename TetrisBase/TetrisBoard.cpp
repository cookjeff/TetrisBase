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
		renderSquare.x = xpos * 0.375 * screen_width;
		renderSquare.y = ypos * 1.0 / 20.0 * screen_width;
		renderSquare.w = (0.375 * screen_width) / 10.0;
		renderSquare.h = 0.05 * 
	}

};

// The class for a tetris board, implemented as a singleton pattern
class TetrisBoard {
	
	TetrisBoard() {
		for (int i = 0; i < 10; i++) {
			for (int k = 0; k < 20; k++)
				gridSquares[i][k].init();
		}
	}
	
private: 
	GridSquare gridSquares[10][20];




};

