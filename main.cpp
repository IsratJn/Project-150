#include "SFML/Graphics.hpp"

int main(int argc, char ** argv){
    int counterWalking=0;
  sf::RenderWindow renderWindow(sf::VideoMode(1600, 800), "Demo Game");

  sf::Event event;
  sf::Texture texture;
  texture.loadFromFile("santa.png");

  sf::Sprite sprite(texture);
  sprite.setPosition(0,100);
  sprite.setTextureRect(sf::IntRect(0,0,200,197));


  while (renderWindow.isOpen()){
    while (renderWindow.pollEvent(event)){
      if (event.type == sf::Event::EventType::Closed)
        renderWindow.close();
    }


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
       sprite.move(1,0) ;
       sprite.setTextureRect(sf::IntRect(counterWalking*200,0,200,197));
    }
    counterWalking++;
    if(counterWalking==10){
        counterWalking=0;
    }




    renderWindow.clear();
    renderWindow.draw(sprite);
    renderWindow.display();
  }
}
