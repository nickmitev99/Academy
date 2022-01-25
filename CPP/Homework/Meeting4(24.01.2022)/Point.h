#ifndef POINT_H
#define POINT_H

class Point
{
  protected:
  int *pt;
  static int ptCounter;

  public:
  Point(int p = 0);
  Point(const Point &pRef);
  Point(Point &&rRef) noexcept;
  ~Point();

  inline int getPt() { return *pt; }
  inline int getPtCount() { return ptCounter; }

  const int getThis();
};

void displayPoint(Point &pt);

#endif //POINT_H