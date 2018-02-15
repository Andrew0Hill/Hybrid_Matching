#pragma once
#ifndef FEATURE_IMAGE_H
#define FEATURE_IMAGE_H
#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/features2d.hpp>
#include "ObjectInstance.h"
class ObjectInstance;
class FeatureImage
{
public:
	// Pointer to image
	cv::Ptr<cv::Mat> image;
	// Keypoints for this FeatureImage
	std::vector<cv::KeyPoint> kps;
	// Descriptors for this FeatureImage
	std::vector<cv::Mat> descs;
	// Type of feature. Can be used to look up the feature name string in the category_map
	int feat_type;
	// Pointer to parent ObjectInstance
	ObjectInstance* parent = 0;

	FeatureImage();
	~FeatureImage();
};
#endif
