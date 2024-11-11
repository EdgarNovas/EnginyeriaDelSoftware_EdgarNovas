#include "AABB.h"

bool AABB::CheckOverLappingPoint(Vector2 point)
{
    bool insideX = point.x >= topLeft.x && point.x <= topLeft.x + size.x;
    bool insideY = point.y >= topLeft.y && point.y <= topLeft.y + size.y;

    return insideX && insideY;
}

bool AABB::CheckOverLappingAABB(const AABB* other)
{
    // Como podriamos encontrar si las cajas se solapan?
    // No podemos usar las arestas porque no es reliable
    // top left

    

    // a += b ---> a= a + b
    // |= b ----> a = a || b
    bool intersectionX = false;
    intersectionX |= topLeft.x > other->topLeft.x && topLeft.x <= other->topLeft.x + other->size.x;
    intersectionX |= other->topLeft.x > topLeft.x && other->topLeft.x <= topLeft.x + size.x;


    bool intersectionY = false;
    intersectionY |= topLeft.y > other->topLeft.y && topLeft.y <= other->topLeft.y + other->size.y;
    intersectionY |= other->topLeft.y > topLeft.y && other->topLeft.y <= topLeft.y + size.y;
    return intersectionX && intersectionY;
}
