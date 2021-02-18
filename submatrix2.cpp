#include <opencv2/opencv.hpp>
#include <iostream> // std::cout
#include <sstream> // std::ostringstream
#include <string> // std::string

using namespace std;
using namespace cv;

template <class _Tp>
int GetProduct(vector<_Tp> sizes) {
  _Tp prod = 1;
  for (auto sz : sizes)
    prod *= sz;
  return prod;
}

template <class _Tp>
vector<_Tp> GetCumProduct(vector<_Tp> array) {
  vector<_Tp> cumpro(array.size());
  cumpro[0] = array[0];
  for (int i = 1; i < array.size(); i++) {
    cumpro[i] = cumpro[i - 1] * array[i];
  }
  return cumpro;
}

String GetSize(const Mat& mat) {
  ostringstream oss;
  oss << "[INFO] Matrix shape ";
  int ndims = mat.size.dims();
  for (size_t i = 0; i < ndims; i++)
    oss << mat.size[i] << ", ";
  oss << endl;
  return oss.str();
}

String GetString(const Mat& mat, vector<int> sizes) {
  ostringstream oss;
  oss << "[INFO] Matrix values :" << endl;
  int count = 0;
  auto it = mat.begin<float>();
  while (it != mat.end<float>()) {
    oss << *it << ", ";
    it++;
    count++;
    if (count % sizes[1] == 0)
      oss << endl;
    if (count % (sizes[1] * sizes[2]) == 0)
      oss << endl;
  }
  return oss.str();
}

int main(int argc, char** argv) {
  cout << "OpenCV version : " << CV_VERSION << endl;
  cout << "Major version : " << CV_MAJOR_VERSION << endl;
  cout << "Minor version : " << CV_MINOR_VERSION << endl;
  cout << "Subminor version : " << CV_SUBMINOR_VERSION << endl;

  vector<int> sizes{3, 4, 4};
  vector<float> values;
  for (size_t i = 0; i < GetProduct<int>(sizes); i++)
    values.push_back(float(i));

  Mat m(values, CV_32FC1);
  m = m.reshape(0, 3, &sizes[0]);
  cout << GetSize(m);
  cout << GetString(m, sizes) << endl;

  float* mijk =
      (float*)(m.data + m.step[0] * 1 + m.step[1] * 1 + m.step[2] * 2);
  cout << "m[1, 1, 2]=" << *mijk << endl;
}
