#include <iostream>

using namespace std;

int main ()
{
  int ax, ay, az;
  int bx, by, bz;
  int cx, cy, cz;
  
  scanf("%d %d %d", &ax, &ay, &az);
  scanf("%d %d %d", &cx, &cy, &cz);
  
  printf("%d %d %d", (cx - az), (cy / ay), (cz - ax));

  return 0;
}