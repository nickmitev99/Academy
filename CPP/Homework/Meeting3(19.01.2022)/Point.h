#ifndef POINT_H
#define POINT_H

class Point
{
  protected:
  int pt;

  public:
  Point(int p = 0);
  Point(const Point &pRef);
  ~Point();

  inline int getPt() { return pt; }
};


#endif //POINT_H