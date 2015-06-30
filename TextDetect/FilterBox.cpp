#include "Stdafx.h"
#include "FilterBox.h"

bool FilterBox::Keep(Mat& Image)
{
	Rows = Mat::zeros(1, SampleDion, CV_32FC1);
	Mat floatImage = Mat(Image.rows, Image.cols, CV_32FC1);
	cvtColor(Image, Image, CV_BGR2GRAY);
	Image.convertTo(floatImage, CV_32F, 1.0 / 255);
	dct(floatImage, floatImage);
	for (int rowIndex = 0; rowIndex < 60; rowIndex++)
		for (int colIndex = 0; colIndex < 200; colIndex++)
			Rows.at<float>(0, (rowIndex / 3) * 50 + colIndex / 4) += floatImage.at<float>(rowIndex, colIndex);
	Mat m = LDA::subspaceProject(pEigVecs, pMean, Rows);
	float labelpre = rtrees->predict(m.row(0));
	return (labelpre > 0.5);
}

FilterBox::FilterBox()
{
	rtrees = Algorithm::load<RTrees>("./resource/TextLineClassifier");

	SampleReduceDion = 30;
	SampleDion = 1000;
	pMean = Mat(1, SampleDion, CV_32FC1);
	ifstream fin("./resource/pMeanFFT");
	for (int i = 0; i < SampleDion; i++)
		fin >> pMean.at<float>(0, i);
	fin.close(); fin.clear();
	fin.open("./resource/pEigVecsFFT");
	pEigVecs = Mat(SampleDion, SampleReduceDion, CV_32FC1);
	for (int i = 0; i < SampleDion; i++)
		for (int j = 0; j < SampleReduceDion; j++)
			fin >> pEigVecs.at<float>(i, j);
}