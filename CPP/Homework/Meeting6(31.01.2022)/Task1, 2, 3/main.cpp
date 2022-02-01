// Упражнение 1. Създайте функция draw(), която не е член на клас и има един
// аргумент от тип Shape*. Начертайте окръжност, правоъгълен триъгълник и правоъгълник .

// Упражнение 2. Дефинирайте функция reSize(), която не е член на клас и има
// аргумент от тип Shape& (необходим е и втори аргумент за размера). Изпълнете draw(),
// reSize() и отново draw() за окръжност, равностранен триъгълник и квадрат .

// Упражнение 3. Създайте виртуална функция save(), която описва обект от
// йерархията на геометричните фигури на екрана и виртуална функция restore(), която
// прочита информацията , изведена от save().

#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"

int main(void)
{
  Shape *sh = new Shape;
  Triangle *t = new Triangle;
  Rectangle *r = new Rectangle;

  //Task1

  draw(sh, 2, 3);
  draw(t, 4, 5);
  draw(r, 10, 20);

  std::cout << "Shape: " << sh->area() << std::endl;
  std::cout << "Triangle: " << t->area() << std::endl;
  std::cout << "Rectangle: " << r->area() << std::endl;

  //Task2
  reSize(*sh, 10, 10);
  reSize(*t, 20, 20);
  reSize(*r, 30, 30);

  std::cout << "Shape: " << sh->area() << std::endl;
  std::cout << "Triangle: " << t->area() << std::endl;
  std::cout << "Rectangle: " << r->area() << std::endl;

  //Task3

  sh->save();
  t->save();
  r->save();

  sh->restore();
  t->restore();
  r->restore();

  delete sh;
  delete t;
  delete r;

  return 0;
}

void draw(Shape *pSh, int w, int h)
{
  pSh->width = w;
  pSh->height = h;
}

void reSize(Shape &pSh, int w, int h)
{
  pSh.width = w;
  pSh.height = h;
}