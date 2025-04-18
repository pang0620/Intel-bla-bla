#include <stdio.h>
#include "line.h"
#include "point.h"

int main() 
{
    Line a = {{1, 2}, {5, 6}};

    // center of line? needs point
    Point center = {(a.first.x + a.second.x / 2),
                    (a.first.y + a.second.y / 2)};

    printf("center of the line: %d, %d\n", center.x, center.y);

    return 0;
}
