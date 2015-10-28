#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "texture.h"

class Character
{
	public:
		static const int PLAYER_WIDTH= 32;
		static const int PLAYER_HEIGHT= 32;

		static const int PLAYER_VEL = 5;
		//default ctor
		Character();

		//Moving
		void handleEvent(SDL_Event & e);

		//Moves the character
		void move();

		//Move with animation
		void move(int * frame);

		//adjust the camera
		void setCam(SDL_Rect & cam);

		//accessors
		SDL_Rect getmCollide()
		{return mCollider;}
		int getPosX()
		{return mPosX;}
		int getPosY()
		{return mPosY;}

		//set stuff
		void setPos(int x, int y)
		{mPosX=x; mPosY=y;}

		//ANIMATION TO BE PUT IN LATER


	private:
		int mPosX, mPosY;

		int mVelX, mVelY;

		
		
};//end class character


Character()
{
	mPosX= LEVEL_W/2;
	mPosY= LEVEL_H/2;
	
	mVelX=0;
	mVelY=0;
}	

void Character::handleEvent(SDL_Event & e)
{
	if(e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		switch(e.key.keysym.sym)
		{
			case SDLK_LEFT: mVelX-= PLAYER_VEL; break;
			case SDLK_RIGHT: mVelX+= PLAYER_VEL; break;
			case SDLK_SPACE: mVelY+=10; break;
		}
	}
	else if(e.type == SDL_KEYUP && e.key.repeat ==0)
	{
		switch(e.key.keysym.sym)
		{
			case SDLK_LEFT: mVelX+= PLAYER_VEL; break;
			case SDLK_RIGHT: mVelX-= PLAYER_VEL; break;
			case SDLK_SPACE: mVelY-= 20; break;	 
		}
	}
}
#endif
