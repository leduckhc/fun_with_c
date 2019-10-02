#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char const* argv[]) {
  cout << "Hello World from C++ (author: Milan Le @ Quantasoft)" << endl;
  cout << "OpenCV " << CV_VERSION << endl << endl;

  vector<float> values;
  for (size_t i = 0; i < 3 * 4 * 4; i++) {
    values.push_back(static_cast<float>(i));
  }
  int sz[3] = {3, 4, 4};
  Mat m(3, sz, CV_32F, (void*)values.data());
  MatConstIterator_<float> it = m.begin<float>();
  int count = 0;
  while (it != m.end<float>()) {
    cout << *it << ", ";
    it++;
    count++;
    if (count % 4 == 0)
      cout << endl;
    if (count % 16 == 0)
      cout << endl;
  }
  cout << endl;

  cout << "Submatrixes " << endl;
  Range ranges[] = {Range(1, 2), Range::all(), Range::all()};
  Mat subMat = m(ranges).clone();
  // print out
  it = subMat.begin<float>();
  count = 0;
  while (it != subMat.end<float>()) {
    cout << *it << ", ";
    it++;
    count++;
    if (count % 4 == 0)
      cout << endl;
    if (count % 16 == 0)
      cout << endl;
  }

  return 0;
}
