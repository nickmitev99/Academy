#include "Cents.h"

bool Cents::operator<(const Cents &cRef)
{
  return m_cents < cRef.m_cents;
}

bool Cents::operator<=(const Cents &cRef)
{
  return m_cents <= cRef.m_cents;
}