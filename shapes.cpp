#include "shapes.h"

Triangle::Triangle(float x, float y) : Position(x, y) {
  shape = new sf::ConvexShape;
}

void Triangle::draw(sf::RenderWindow& window) const {
  if (shape) {
    auto sh = dynamic_cast<sf::ConvexShape*>(shape);
    sh->setPointCount(3);
    sh->setPoint(0, sf::Vector2f(_a + 100.f, _a + 100.f));
    sh->setPoint(1, sf::Vector2f(_b + 100.f, _b + 100.f));
    sh->setPoint(2, sf::Vector2f(_c + 100.f, _c + 100.f));
    sh->setPosition(pos_x, pos_y);
    sh->setFillColor(sf::Color::Blue);

    window.draw(*sh);

  } else {
    std::cout << "Triangle(shape) is empty." << std::endl;
  }
}

void Triangle::setSize(float a, float b, float c) {
  if (a > 0 && b > 0 && c > 0) {
    _a = a;
    _b = b;
    _c = c;
  }
}

Triangle::~Triangle() {
  if (shape) {
    delete shape;
  }
}

sf::Shape* Triangle::getShape() { return shape; }

Circle::Circle(float x, float y) : Position(x, y) {
  shape = new sf::CircleShape(_r);
}

void Circle::draw(sf::RenderWindow& window) const {
  if (shape) {
    shape->setPosition(pos_x, pos_y);
    shape->setFillColor(sf::Color::Cyan);

    window.draw(*shape);
  }
}

Circle::~Circle() {
  if (shape) {
    delete shape;
  }
}

sf::Shape* Circle::getShape() { return shape; }

Rectangle::Rectangle(float x, float y) : Position(x, y) {
  shape = new sf::RectangleShape(sf::Vector2f(_a, _b));
}

void Rectangle::draw(sf::RenderWindow& window) const {
  if (shape) {
    shape->setPosition(pos_x, pos_y);
    shape->setFillColor(sf::Color::Magenta);

    window.draw(*shape);
  }
}

sf::Shape* Rectangle::getShape() { return shape; }

Rectangle::~Rectangle() {
  if (shape) {
    delete shape;
  }
}

Square::Square(float x, float y) : Rectangle(x, y), Position(x, y) {
  shape = new sf::RectangleShape(sf::Vector2f(_a, _a));
}

void Square::draw(sf::RenderWindow& window) const {
  if (shape) {
    shape->setPosition(Position::pos_x, Position::pos_y);
    shape->setFillColor(sf::Color::Magenta);

    window.draw(*shape);
  }
}
Square::~Square() {
  if (shape) {
    delete shape;
  }
}
