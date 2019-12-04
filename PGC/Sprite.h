#ifndef __SPRITE_H__
#define __SPRITE_H__
#include <SDL.h>
class Sprite
{
public:
	Sprite(SDL_Surface *new_image, int x, int y);
	void SetImage(SDL_Surface *new_image);
	void SetPos(int x, int y);
	void Move(int move_x, int move_y);
	SDL_Rect *GetRect(void);
	void Draw(SDL_Surface *target);
protected:
	SDL_Surface *image;
	SDL_Rect rect;
};
#endif