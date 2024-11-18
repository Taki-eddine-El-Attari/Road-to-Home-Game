#include "Button.hpp"


button::button(const char *imagepath, Vector2 imageposition , float scale)
{
    Image image = LoadImage(imagepath); //load image from the path entered in arguments with Image structure
    
    int originalwidth = image.width; //return image width
    int originalheight = image.height; //return image height

    int newWidth = static_cast<int> (originalwidth * scale); //adjust our image width with scale argument , static_cast used if the scale entered is float the operator convert it to integer type
    int newHeight = static_cast<int> (originalheight * scale); //adjust our image height with scale argument
    
    ImageResize(&image, newWidth , newHeight); //function of raylib to resize our image
    texture = LoadTextureFromImage(image); //load texture from the new image resized
    
    UnloadImage(image); // free up the memory from the image because we've saved his texture in memory
    position = imageposition; //assign imageposition to position attribute of button class
}

button::~button()
{
    UnloadTexture(texture); // to free up the memory from the constructor
}
void button::Draw()
{
     DrawTextureV(texture , position , WHITE); //function to draw the button on the raylib window
}

bool button::isPressed(Vector2 mousePosition, bool mousePressed)
{
    //create a rectangle from Rectangle structure that encloses the button
    Rectangle rect = {position.x , position.y , static_cast<float>(texture.width), static_cast<float>(texture.height)}; // width and height are integers in the Texture2D structure
    
    if(CheckCollisionPointRec(mousePosition , rect) && mousePressed){ //if the mouse is over the button and left mouse is pressed
         return true;
    }
    return false;
}
