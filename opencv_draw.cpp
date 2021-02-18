#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>


int main(int argc, char const* argv[])
{   
    std::vector<float> data; 
    for (int i = 0; i < 28 * 28; i++) {
        data.push_back(float(i));
    }

    cv::Mat m(data);
    m = m.reshape(0, 28);
    std::cout << m << std::endl;

    return 0;

}
