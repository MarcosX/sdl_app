#ifndef _COLLISION_BOX_H_
#define _COLLISION_BOX_H_

class CollisionBox {
private:
  int upper_x, upper_y, lower_x, lower_y;
public:
  bool hits(CollisionBox& target){
    if(lower_x < target.upper_x) return false;
    if(upper_x > target.lower_x) return false;
    if(lower_y < target.upper_y) return false;
    if(upper_y > target.lower_y) return false;
    return true;
  };
};

#endif
