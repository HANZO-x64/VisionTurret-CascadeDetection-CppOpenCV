#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
using namespace cv;
using namespace std;

////////// Version 2.0 //////////

void main() {
	setlocale(LC_ALL, "Ru");

	VideoCapture cap(0);
	Mat img;
	CascadeClassifier bodyCascade;
	bodyCascade.load("Resources/haarcascade_fullbody.xml");

	while (true) {
		bool success = cap.read(img);
		if (!success || img.empty()) {
			cout << "Пустой кадр или ошибка захвата" << endl;
			break;
		}

		vector<Rect> bodies;
		bodyCascade.detectMultiScale(img, bodies, 1.1, 4);

		for (int i = 0; i < bodies.size(); i++) {
			rectangle(img, bodies[i].tl(), bodies[i].br(), Scalar(255, 0, 255), 3);
		}


		imshow("Image", img);
		waitKey(1);
	}
}