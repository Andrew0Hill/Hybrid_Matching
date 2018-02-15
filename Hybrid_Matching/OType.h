#pragma once
#ifndef O_TYPE_H
#define O_TYPE_H
#include "ObjectInstance.h"
#include "FeatureImage.h"
#include <vector>
#include <boost\unordered_map.hpp>
#include <iostream>
#include "Categories.h"

#define NN_THRESH 0.75f
#define INLIERS_THRESH 12
class OType
{
public:
	// ID to uniquely identify this type of object.
	int id; 
	// ID to allocate unique IDs to each object in this OType.
	int a_id;
	// List of ObjectInstances in this OType.
	std::vector<ObjectInstance> objects;
	// List of FeatureImages in this OType.
	std::vector<FeatureImage> images;
	// List of Descriptors in this OType.
	std::vector<cv::Mat> descs; 
	// List of Keypoints in this OType.
	std::vector<cv::KeyPoint> kps;
	// Map of ObjectInstance index to FeatureImage index. TODO: Maybe make this less weird since we're not in Python anymore?
	boost::unordered_map<int, int> desc_map;
	// Feature Matcher for matching features in the OType.
	cv::FlannBasedMatcher matcher;
	
	OType(int tid);
	~OType();

	int alloc_id() { return a_id++; }
	// Adds a new ObjectInstance, with this FeatureImage as the first child.
	void add_new_obj(FeatureImage feat_image);

	// Matches this FeatureImage against other FeatureImages of this OType.
	// TODO: Implement this.
	void match(FeatureImage	feat_image);
};

#endif