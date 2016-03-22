// 14/06/16
#ifndef SKELETON_H
#define SKELETON_H
using namespace std;

class Skeleton
{
private:
	string name;
	Bone &rootBone;
	Bone *bones;
	bool rootBoneAttached;

public:
	Skeleton(string name, Bone &rootBone);
};

#endif // SKELETON_H
