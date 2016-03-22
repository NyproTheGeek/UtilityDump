// 14/06/16
#ifndef BONETRANSFORM_H
#define BONETRANSFORM_H

class BoneTransform
{
public:
	Vec2f rotateScale; // compex rotation has scale property, but it cannot translate
	Vec2f translate;

	BoneTransform(Vec2f rotate, Vec2f translate, Vec2f scale);
	BoneTransform(float rotateX, float rotateY, float translateX, float translateY, float scaleX, float scaleY);
};
#endif // BONETRANSFORM_H
