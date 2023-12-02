#include <SFML/Graphics.hpp>
#include <iostream>

class myShape {
 public:
  myShape() {}

  virtual void draw(sf::RenderWindow& window) const = 0;
  virtual void setSize() = 0;

  virtual ~myShape() = default;

  sf::Shape* shape = nullptr;
};

class Position {
 public:
  Position(float x, float y) : pos_x(x), pos_y(y) {}
  Position() = default;
  float pos_x = 400;
  float pos_y = 400;

  virtual ~Position() = default;
};

class Triangle final : public myShape, public Position {
 public:
  Triangle(float x, float y);

  void draw(sf::RenderWindow& window) const override;

  void setSize(float a, float b, float c);

  sf::Shape* getShape();

  ~Triangle();

 private:
  float _a = 0.f;
  float _b = 0.f;
  float _c = 0.f;
  bool mark = true;
};

class Circle final : public myShape, public Position {
 public:
  Circle(float x, float y);

  void draw(sf::RenderWindow& window) const override;

  ~Circle();

  sf::Shape* getShape();

 private:
  float _r = 50.f;
  bool mark = true;
};

class Rectangle : public myShape, public Position {
 public:
  Rectangle(float x, float y);

  virtual void draw(sf::RenderWindow& window) const override;

  sf::Shape* getShape();

  virtual ~Rectangle();

 private:
  float _a = 100.f;
  float _b = 50.f;
  bool mark = true;
};

class Square final : public Rectangle, public Position {
 public:
  Square(float x, float y);

  void draw(sf::RenderWindow& window) const override;

  ~Square();

 private:
  float _a = 100;
  bool mark = true;
};
