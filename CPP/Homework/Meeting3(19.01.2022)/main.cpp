#include <iostream>
#include "Cube.h"

int main()
{  
  std::cout << "Entering main...\n" << std::endl;

  //Point tests
  std::cout << "\n- p(10)" << std::endl;

  Point p(10);
  std::cout << "\np.pt = " << p.getPt() << std::endl;

  std::cout << "\n\n- p2 = pt" << std::endl;

  Point p2 = p;
  std::cout << "\np2.pt = " << p2.getPt() << std::endl;

  //Square tests
  std::cout << "\n\n- s(2)" << std::endl;
  Square s(2);
  std::cout << "\ns.pt = " << s.getPt() << "\ts.x = " << s.getX() << "\t s.y = " << s.getY() << std::endl;

  std::cout << "\n\n- s2(2, 4)" << std::endl;
  Square s2(2, 4);
  std::cout << "\ns2.pt = " << s2.getPt() << "\ts2.x = " << s2.getX() << "\t s2.y = " << s2.getY() << std::endl;

  std::cout << "\n\n- s3 = s2" << std::endl;
  Square s3 = s2;
  std::cout << "\ns3.pt = " << s3.getPt() << "\ts3.x = " << s3.getX() << "\t s3.y = " << s3.getY() << std::endl;

  //Cube tests
  std::cout << "\n\n- c" << std::endl;
  Cube c(5);
  std::cout << "\nc.pt = " << c.getPt() << "\tc.x = " << c.getX() << "\t c.y = " << c.getY() << "\tc.z = " << c.getZ() << std::endl;

  std::cout << "\n\n- c2 = c" << std::endl;
  Cube c2 = c;
  std::cout << "\nc2.pt = " << c2.getPt() << "\tc2.x = " << c2.getX() << "\t c2.y = " << c2.getY() << "\tc2.z = " << c2.getZ() << std::endl;

  std::cout << "\n\nExiting main...\n" << std::endl;

  return 0;
}