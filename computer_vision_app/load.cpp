/*
http://benjithian.sg/2012/12/load-image-from-memoryweb-using-opencv-and-libcurl/
I just started playing around with OpenCV and wanted it to display images directly from memory loaded from  a website URL.
Below is the C++ codes to load an image directly from a website without it being written to the hard disk.
Library used were OpenCV and Libcurl. Do tell me if there is a more efficient way to do it.
*/
#include <stdio.h>
#include <curl/curl.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

//curl writefunction to be passed as a parameter
size_t write_data(char *ptr, size_t size, size_t nmemb, void *userdata) {
    std::ostringstream *stream = (std::ostringstream*)userdata;
    size_t count = size * nmemb;
    stream->write(ptr, count);
    return count;
}

//function to retrieve the image as Cv::Mat data type
cv::Mat curlImg()
{
    CURL *curl;
    CURLcode res;
    std::ostringstream stream;
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, "http://via.placeholder.com/1000.jpg"); //the img url
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data); // pass the writefunction
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &stream); // pass the stream ptr when the writefunction is called
    res = curl_easy_perform(curl); // start curl
    std::string output = stream.str(); // convert the stream into a string
    curl_easy_cleanup(curl); // cleanup
    std::vector<char> data = std::vector<char>( output.begin(), output.end() ); //convert string into a vector
    cv::Mat data_mat = cv::Mat(data); // create the cv::Mat datatype from the vector
    cv::Mat image = cv::imdecode(data_mat,1); //read an image from memory buffer
    return image;
}
int main(void)
{
    cv::Mat image = curlImg();
    cv::namedWindow( "Image output", cv::WINDOW_AUTOSIZE );
    cv::imshow("Image output",image); //display image
    cv::waitKey(0); // press any key to exit
    cv::destroyWindow("Image output");
}
