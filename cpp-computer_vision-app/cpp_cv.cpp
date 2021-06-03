#include <cpp_cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <map>
#include <iostream>

using namespace std;
using namespace cv;

void startAnalyse(map <string,string> SettingsMap)
{
    for (auto it = SettingsMap.begin(); it != SettingsMap.end(); ++it)
    {
        cout << it->first << " : " << it->second << endl;
    }
    cout << SettingsMap["alias cam"] << endl;
    // read an image
    Mat image = imread("C:\\Project\\Github_Projects\\cpp-app\\ComputerVision\\1.jpg", 1);
    // create image window named "My Image"
    namedWindow("My Image");
    // show the image on window
    imshow("My Image", image);
}
