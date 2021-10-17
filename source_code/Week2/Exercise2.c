// Kiem tra 1 diem co thuoc duong tron khong
#include <stdio.h>
typedef struct point {
   double x;
   double y;
} point_t;
typedef struct circle {
   point_t center;
   double radius;
} circle_t;
int checkCover(point_t p, circle_t c) {
   int dist_x = p.x - c.center.x;
   int dist_y = p.y - c.center.y;
   return dist_x * dist_x + dist_y * dist_y <= c.radius * c.radius;
}
int main() {
   point_t p;
   circle_t c;
   printf("Enter point coordinates\n");
   scanf("%lf%lf", &p.x, &p.y);
   printf("Enter circle center coordinates\n");
   scanf("%lf%lf", &c.center.x, &c.center.y);
   printf("Enter circle radius\n");
   scanf("%lf", &c.radius);
   if (checkCover(p, c))
      printf("point is in circle\n");
   else
      printf("point is out of circle\n");
   return 0;
}