#pragma once
#ifndef MAIN_H
#define MAIN_H

/*OpenCV includes*/
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

/*Standard C++ includes*/
#include <iostream>
#include <vector>
#include <string>

/*Project includes*/
#include "Categories.h"
#include "Filenames.h"
#include "ObjectInstance.h"
#include "FeatureImage.h"
#include "Object_Info.h"

/*Boost includes*/
// JSON Parser to read image data in from file
#include <boost/property_tree/json_parser.hpp>
// Property Tree to hold parsed JSON
#include <boost/property_tree/ptree.hpp>

#define IM_WIDTH 640
#define IM_HEIGHT 480


std::vector<cv::Mat> read_images(std::vector<std::string>);
#endif