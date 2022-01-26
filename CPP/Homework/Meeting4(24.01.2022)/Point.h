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

  inline int getPt() const { return *pt; }

  static int getPtCount();

  void displayPoint();

  int getThis() const;
};

#endif //POINT_H