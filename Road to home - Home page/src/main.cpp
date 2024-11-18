#include <raylib.h>
#include <iostream>
#include "Button.hpp"

int main(){
    
    InitWindow(800,548,"Home page"); // Initialisation of the raylib window

    SetTargetFPS(60); //run the program in hight fps

    Texture2D background = LoadTexture("Graphics/background2.png"); //load background from Graphics folder
    button startbutton("Graphics/start.png",{320,150}, 1); //call of button class to create a start button
    button exitbutton("Graphics/exit.png", {327,280},0.9); //call of button class to create a start button
    
    bool exit = false; //Boolean argument initilised with false 
    
    //Game Loop
    while(WindowShouldClose() == false && exit == false){ //function to check if escape key is pressed and exit boolean is false
        
        Vector2 mousePos = GetMousePosition(); //create a mouse posotion from Vector2 structure and stock the dimensions of the mouse with this function
        bool mousePres = IsMouseButtonPressed(MOUSE_BUTTON_LEFT); //check if left mouse button is pressed by this function

        if(startbutton.isPressed(mousePos , mousePres)){ //check if the start button is pressed
           std::cout<<"Start button is pressed"<<std::endl; //test the method
        }
        
        if(exitbutton.isPressed(mousePos , mousePres)){ //check if the exit button is pressed
           exit = true; //change the value of exit to close the raylib window
        }
        
        //Drawing
        BeginDrawing();
       
        ClearBackground(BLACK); //Default Color of background
        DrawTexture(background, 0 , 0 , WHITE); //Draw background on the raylib window
       
        startbutton.Draw(); //Draw the start button on the raylib window
        exitbutton.Draw(); //Draw the exit button on the raylib window
        
        EndDrawing();
    }


    CloseWindow();

 return 0;
}
