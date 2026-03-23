#include <iostream>
#include <SFML/Graphics.hpp>
#include "bat.h"
#include <sstream>

using namespace sf;


int main(){
   VideoMode vm(1600,900);
   RenderWindow window(vm,"Pong",Style::Fullscreen);
   
   int score=0;
   int lives=3;
   
   
   //bat to be placed as bottom center of the screen

   bat b(1600/2 - 50, 900 - 40);
   
   Text hud;
   Font font;
   font.loadFromFile("font/KOMIKAP_.ttf");
   hud.setFont(font);
   hud.setFillColor(Color::White);
   hud.setCharacterSize(75);
   hud.setPosition(20,20);
   
   Clock clock;
   while (window.isOpen()){
     //handle player action
     Event event;
     while(window.pollEvent(event)){
       if(event.type==Event::Closed){
          window.close();
       
       }
       
       }
       
       if(Keyboard::isKeyPressed(Keyboard::Escape)){
           window.close();
           }
           if(Keyboard::isKeyPressed(Keyboard::Left)){
              b.moveLeft();
            }
            else{
               b.stopLeft();
                 
     }
     if(Keyboard::isKeyPressed(Keyboard::Right)){
        b.moveRight();
        }
        else{
        b.stopRight();
        }
     //update bat,ball and hud      
         Time dt=clock.restart();
         b.update(dt);
         
         std::stringstream ss;
         ss << "Score: " << score << " Lives: " << lives;
         hud.setString(ss.str());
         
   //draw and display
   
       window.clear();
       window.draw(hud);
       window.draw(b.getShape());
       window.display();
       
   
   
   }
   }
   
