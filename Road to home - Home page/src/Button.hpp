#pragma once
#include <raylib.h>

class button
{
public:
 button(const char* imagepath , Vector2 imageposition ,float scale); //create a button with a path, position and scale arguments
 ~button(); //destructor of button to free up memory
 void Draw(); //To draw the button
 bool isPressed( Vector2 mousePosition , bool mousePressed); //to check if the button is pressed

private:
Texture2D texture; // create a texture with height and width attributes from Texture2D structure
Vector2 position; // create a position with x,y dimension with Vector2 structure
};
