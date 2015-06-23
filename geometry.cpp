#include "geometry.h"

#define EPSILON 1e-6f

//from wikipedia
std::pair <bool, float> triangle::intersect(ray r)
{
  float3 e0, e1;
  float3 p, q, t;
  float det, inv_det, u, v;
  float d;

  e0 = v1 - v0;
  e1 = v2 - v0;

  p = r.direction.cross(e1);

  det = e0.dot(p);

  if(det > -EPSILON && det < EPSILON)
    return std::make_pair(false, 0.0f);

  inv_det = 1.0f / det;

  t = r.origin - v0;

  u = t.dot(p) * inv_det;

  if(u < 0.0f || u > 1.0f)
    return std::make_pair(false, 1.0f);

  q = t.cross(e0);

  v = r.direction.dot(q) * inv_det;

  if(v < 0.0f || u + v  > 1.0f)
    return std::make_pair(false, 2.0f);

  d = e1.dot(q) * inv_det;

  if(d > EPSILON)
    return std::make_pair(true, d);

  return std::make_pair(false, 3.0f);
}
