#ifndef CENTS_H
#define CENTS_H

class Cents
{
  int m_cents;

public:
  Cents(int c = 0) : m_cents(c) {}

  inline int getCents() const { return m_cents; }

  Cents operator+(int v) { return m_cents + v; }

  bool operator<(const Cents &cRef);
  bool operator<=(const Cents &cRef);
};

#endif //CENTS_H