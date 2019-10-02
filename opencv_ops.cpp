#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

inline String GetMatShape(const Mat& mat, const string& prefix = "") {
  ostringstream oss;
  oss << "[INFO] Matrix (" << prefix << ") shape (";
  int ndims = mat.size.dims();
  for (size_t i = 0; i < ndims; i++) {
    oss << mat.size[i];
    if (i < ndims - 1) {
      oss << ", ";
    }
  }
  oss << ")" << endl;
  return oss.str();
}


int main(int argc, char const* argv[]) {
  cout << "OpenCV version : " << CV_VERSION << endl;

  Mat mat = (Mat_<float>(3,3) << 1,2,3,4,5,6,7,8,9);
  cout << "mat " << mat << endl;
  const int newsz [] = {9, 1};
  mat = mat.reshape(0, 2, newsz);
  cout << "reshaped mat " << mat << endl;
  return 0;
}
