#include <SDL.h>

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern SDL_Surface * gHelloWorld;
extern SDL_Surface * gScreenSurface; 

class GridSquare {
	

public: 

	SDL_Surface *  gridTile;
	SDL_Rect renderSquare;
	bool isOccupied;
	int tileType;
	const int width = (int)((SCREEN_WIDTH * 0.375) / 10);
	const int height = (int)(SCREEN_HEIGHT / 20);
	const int offset = (int) ((1 - 0.375) / 2.0 * SCREEN_WIDTH);
	/*
	void init(int xpos, int ypos) {
		// The board starts empty, so this will be false
		isOccupied = false;
		// Create it's "renderSquare" that defines its x and y
		// position and height, relative to the screen size
		renderSquare.x = (int)(xpos * 0.375 * SCREEN_WIDTH);
		renderSquare.y = (int)(ypos * 0.05 * SCREEN_HEIGHT);
		renderSquare.w = (int)((0.375 * SCREEN_WIDTH) / 10.0);
		renderSquare.h = (int)(0.05 * SCREEN_HEIGHT);
	}*/
	void init(int xpos, int ypos, SDL_Surface * image) {
		// The board starts empty, so this will be false
		isOccupied = false;
		// Create it's "renderSquare" that defines its x and y
		// position and height, relative to the screen size
//		renderSquare.x = (int)(0 + xpos*(SCREEN_WIDTH / 10));
//		renderSquare.y = (int)(0 + ypos*(SCREEN_HEIGHT/20));
		renderSquare.w = width;
		renderSquare.h = height;
		renderSquare.x = (int)(offset + xpos*((0.375*SCREEN_WIDTH) / 10));
		renderSquare.y = (int)(0 + ypos*(SCREEN_HEIGHT / 20));
//		renderSquare.w = 64;
//		renderSquare.h = 24;
		gridTile = image;
	}

};

// The class for a tetris board, implemented as a singleton pattern
class TetrisBoard {
	
public:
	SDL_Surface * boardSurface;

	// The backbone of the tetris board: a grid of gridsquares, each of which
	// handles it's own x and y position for blitting and it's width and height
	// calculated dynamically upon initialization based on the screen size :D
	GridSquare gridSquares[10][20];

	// The constructor
	TetrisBoard(SDL_Surface * surfaceToRenderTo) {
		// Initialize each grid square
		for (int i = 0; i < 10; i++) {
			for (int k = 0; k < 20; k++)
				gridSquares[i][k].init(i,k,gHelloWorld);
		}
		// Point at the surface we want to render to each time
		boardSurface = surfaceToRenderTo;
	}

	// Render the WHOLE BOARD to a surface
	void Render() {
		for (int i = 0; i < 10; i++) {
			for (int k = 0; k < 20; k++) {
				SDL_BlitScaled(gridSquares[i][k].gridTile, NULL, gScreenSurface, & gridSquares[i][k].renderSquare);
			}
		}
	}

	
private: 
	




};

