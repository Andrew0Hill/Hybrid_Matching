#include "Main.h"

int main(int argc, char** argv)
{	
	std::vector<cv::Mat> image_list = read_images(FILENAMES);



	cv::namedWindow("Test Window", CV_WINDOW_AUTOSIZE);
	cv::imshow("Test Window", image_list[0]);
	cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
}

/* Read images in from a file. 
 * Accepts: A std::vector of filname strings
 * Returns: A std::vector of cv::Mat (the read in images)
 */
std::vector<cv::Mat> read_images(std::vector<std::string> filenames) {
	std::vector<cv::Mat> image_list;
	// Read in images from file
	for (std::vector<std::string>::const_iterator it = filenames.begin(); it != filenames.end(); it++) {
		cv::Mat img = cv::imread(*it, cv::IMREAD_COLOR);
		if (!img.data)
			std::cout << "Could not read '" << *it << "' from file. Exiting.\n";
		image_list.push_back(cv::imread(*it, cv::IMREAD_COLOR));
	}
	std::cout << "Succesfully read " << image_list.size() << " images from file.";
	return image_list;
}

/* TODO: Parse JSON file into vector? 
*/


