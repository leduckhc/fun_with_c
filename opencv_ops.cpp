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

  Mat mat = (Mat_<int>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
  cout << "mat " << mat << endl;

  ///////////////////////////////////////////////////
  // reshaping
  Mat mat_reshape;
  const int newsz[] = {9, 1};
  mat.reshape(0, 2, newsz).copyTo(mat_reshape);
  cout << "reshaped mat =" << mat_reshape << endl;

  ///////////////////////////////////////////////////
  // binary operations
  Mat mat4 = (mat > 4);
  mat.convertTo(mat, CV_8UC1); // we must convert mat into this type
  cout << "[mat>4] = " << mat4 << endl;
  cout << "[mat&mat4] = " << (mat & mat4) << endl;

  ///////////////////////////////////////////////////
  // submatrixing
  Mat submat = Mat::zeros(Size(6, 6), CV_8UC1);
  mat.copyTo(submat(Rect(1, 1, 3, 3)));
  cout << "[submat] = " << submat << endl;


  return 0;
}
