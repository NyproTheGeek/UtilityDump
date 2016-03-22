// 13/03/16
#ifndef BONE_H
#define BONE_H
#include <string>
#include "Vec2f.h"
#include "PosVec2f.h"
#include "Slot.h"
using namespace std;

class Bone
{
private:
    string name; // cannot be null
    Bone &parent; // cannot be this, cannot be null except for rootBone
	Bone *children;
	Skeleton &skeleton; // cannot be null
	PosVec2f positionVector; // cannot be null // This vector has position, angle and scale properties // Position r7elative to root
	float scaleX, scaleY; // cannot be null  // scale needs to be stored separately for lookup
    Slot *slots;

public:
	Bone(string name, Bone &parent, Vec2f positionA, Vec2f positionB, Vec2f scale);
	Bone(string name, Bone &parent, Vec2f positionA, Vec2f positionB, float scaleX, float scaleY);
	Bone(string name, Bone &parent, float postionAX, float positonAY, float postionBX, float postionBY, float scaleX, float scaleY);
};

#endif // BONE_H

