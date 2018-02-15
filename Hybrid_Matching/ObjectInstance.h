#pragma once
#ifndef OBJECT_INSTANCE_H
#define OBJECT_INSTANCE_H
#include <vector>
#include "FeatureImage.h"
class FeatureImage;
class ObjectInstance
{
public:
	// Unique ID for this ObjectInstance
	int id; 
	// Vector of FeatureImage objects for this ObjectInstance
	std::vector<FeatureImage> images;

	ObjectInstance(int oid, FeatureImage feat_image);
	~ObjectInstance();
};
#endif

