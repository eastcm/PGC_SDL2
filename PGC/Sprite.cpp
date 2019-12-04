#include "Sprite.h"
Sprite::Sprite(SDL_Surface *new_image, int x, int y) {
	SetImage(new_image);
	SetPos(x, y);
}
void Sprite::SetImage(SDL_Surface *new_image) {
	image = new_image;
}
void Sprite::SetPos(int x, int y) {
	rect.x = x;
	rect.y = y;
}
void Sprite::Move(int move_x, int move_y) {
	rect.x += move_x;
	rect.y += move_y;
}
SDL_Rect *Sprite::GetRect(void) {
	return &rect;
}
void Sprite::Draw(SDL_Surface *target) {
	SDL_BlitSurface(image, NULL, target, &rect);
}