#include "stdafx.h"
#include"TextDetection.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;
using namespace cv;

int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> gtset; 
	string line;
	Mat image = imread("./resource/demo.jpg");
	ifstream fin("./resource/gt_demo");
	while (getline(fin, line))
	{
		gtset.push_back(line);
	}
	TextDetection td;
	cout << td.detectText(image, gtset) << endl;
	waitKey();
	return 0;
}