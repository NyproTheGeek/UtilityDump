// 14/06/16
#include "Skeleton.h"
#include <string>
#include "PosVec2f.h"
using namespace std;

/// skeleton and rootBone are created automatically before any bone
/// rootBone's parent must be set to null. 

Skeleton::Skeleton(string name, Bone &rootBone)
{
	this->name = name;
	this->rootBone = rootBone;
}


/// TODO: Managing Bones
