#include <thread>
#include <vector>

#include "shapes.h"

int main() {
  sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML Shapes");

  std::vector<myShape*> shapes;

  myShape* tr = new Triangle(100.f, 200.f);
  myShape* cq = new Circle(200.f, 300.f);
  myShape* rq = new Rectangle(400.f, 400.f);
  myShape* sq = new Square(300.f, 300.f);

  shapes.push_back(tr);
  shapes.push_back(cq);
  shapes.push_back(rq);
  shapes.push_back(sq);

  while (window.isOpen()) {
    window.clear();
    for (auto& shape : shapes) {
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
      shape->draw(window);
      // std::this_thread::sleep_for(std::chrono::seconds(3));
    }
    window.display();
  }
}
