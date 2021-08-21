#include <iostream>
#include "opencv2\imgproc.hpp"
#include "opencv2\imgproc.hpp"
#include "opencv2\core\core.hpp"
#include "opencv2\core.hpp"
#include "opencv2\face.hpp"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\objdetect\objdetect.hpp"
#include "opencv2\opencv.hpp"
#include<direct.h>
#include <vector>
using namespace std;
using namespace cv;
using namespace cv::face;
int k, c = 0, a, d, e, f, g, h, i, j, abc, l, m, n, o, p, r, s, t, u, v;
float ab,ac,ad,af,ag,ah,ai,aj,ak,al,am,an,degisken;
vector<vector<int>> newPoints;
vector<vector<int>>renkler
{
	{d, e, f, g, h, i},
	{ j, k, l, m, n, o },
	{ p, r, s, t, u, v }
};
vector<Scalar> boyanacakrenkler{
	{ab,ac,ad},
	{af,ag,ah},
	{ai,aj,ak},
	{al,am,an}
};
Point contourbul(Mat image) {
	Mat img2;
		vector<vector<Point>> contours;
		vector<Vec4i> hierarchy;
		if (image.channels() == 3) {
			cvtColor(image, img2, COLOR_BGR2GRAY);
		}
		else if (image.channels() == 4) {
			cvtColor(image, img2, COLOR_BGR2GRAY);
		}
		else {

			img2 = image;
		}
		GaussianBlur(img2, img2, Size(7,7),5.0);
		Canny(img2, img2, 20, 20);
		findContours(img2, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
		vector<vector<Point>> conPoly(contours.size());
		vector<Rect> boundRect(contours.size());
		Point myPoint(0, 0);
		for (int i = 0; i < contours.size(); i++)
		{
			double area = contourArea(contours[i]);
			cout << area << endl;
				double peri = arcLength(contours[i], true);
				approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

				cout << conPoly[i].size() << endl;
				boundRect[i] = boundingRect(conPoly[i]);
				myPoint.x = boundRect[i].x + boundRect[i].width / 2;
				myPoint.y = boundRect[i].y;

				drawContours(image, conPoly, i, Scalar(255, 0, 255), 2);
				rectangle(image, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
				imshow("goster",image);
				waitKey(0);
		}
		return myPoint;
	}
void rengitanýt() {
	VideoCapture cap(0);
	Mat imghsv,masked;
	Mat imgj;
	int hmin = 0, smin = 0, vmin = 0, hmax = 255, smax = 255, vmax = 255;
	namedWindow("Trackbars", (640, 200));
	createTrackbar("Hue min", "Trackbars", &hmin, 179);
	createTrackbar("Hue max", "Trackbars", &hmax, 179);
	createTrackbar("Sat min", "Trackbars", &smin, 255);
	createTrackbar("Vmin", "Trackbars", &vmin, 255);
	createTrackbar("sat max", "Trackbars", &smax, 255);
	createTrackbar("Vmax ", "Trackbars", &vmax, 255);
	while (true) {
		cap.read(imgj);
		resize(imgj, imgj, Size(1920, 1080));
		cvtColor(imgj, imghsv, COLOR_BGR2HSV);
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imghsv, lower, upper, masked);
		putText(masked, "Sadece belirleyeceginiz renk beyaz kalana kadar duzenleme yapiniz", Point(300, 900),0.1,FONT_HERSHEY_PLAIN,Scalar(0,255,0),2);
		imshow("Kalemin tanýtýlacaðý ekran", masked);
		int fps = 27;
		int k = waitKey(fps);
		if (k == 27) {
			c++;
			if (c == 1) {
				d = hmin;
				e = smin;
				f = vmin;
				g = hmax;
				h = smax;
				i = vmax;
			}
			if (c == 2) {
				j = hmin;
				abc = smin;
				l = vmin;
				m = hmax;
				n = smax;
				o = vmax;
			}
			if (c == 3) {
				p = hmin;
				r = smin;
				s = vmin;
				t = hmax;
				u = smax;
				v = vmax;
				cv::destroyWindow("Kalemin tanýtýlacaðý ekran");
				destroyWindow("Trackbars");
				break;
			}
		}
	}
	cout << "Ilk kalemle yapaginiz boya rengini seciniz" << endl;
	cout << "Kirmizi icin 1'e basiniz" << endl;
	cout << "Yesil icin 2'ye basiniz" << endl;
	cout << "Mavi icin 3 e basiniz" << endl;
	cout << "Siyah icin 4'e basiniz" << endl;
	cin >> degisken;
	if (degisken == 1) {
		ab = 255;
		ac = 0;
		ad = 0;
	}
	if (degisken == 2) {
		ab = 0;
		ac = 255;
		ad = 0;
	}
	if (degisken == 3) {
		ab = 0;
		ac = 0;
		ad = 255;
	}
	if (degisken == 4) {
		ab = 0; ac = 0; ad = 0;
	}
	cout << "Ikinci kalemle yapaðýnýz boya rengini seçiniz" << endl;
	cout << "Kirmizi icin 1'e basiniz" << endl;
	cout << "Yesil icin 2'ye basiniz" << endl;
	cout << "Mavi icin 3 e basiniz" << endl;
	cout << "Siyah icin 4'e basiniz" << endl;
	cin >> degisken;
	if (degisken == 1) {
		af = 255;
		ag = 0;
		ah = 0;
	}
	if (degisken == 2) {
		af = 0;
		ag = 255;
		ah = 0;
	}
	if (degisken == 3) {
		af = 0;
		ag = 0;
		ah = 255;
	}
	if (degisken == 4) {
		af = 0; ag = 0; ah = 0;
	}
	cout << "Ucuncu kalemle yapaðýnýz boya rengini seçiniz" << endl;
	cout << "Kirmizi icin 1'e basiniz" << endl;
	cout << "Yesil icin 2'ye basiniz" << endl;
	cout << "Mavi icin 3 e basiniz" << endl;
	cout << "Siyah icin 4'e basiniz" << endl;
	cin >> degisken;
	if (degisken == 1) {
		ab = 255;
		ac = 0;
		ad = 0;
	}
	if (degisken == 2) {
		al = 0;
		am = 255;
		an = 0;
	}
	if (degisken == 3) {
		al = 0;
		am = 0;
		an = 255;
	}
	if (degisken == 4) {
		al = 0; am = 0; an = 0;
	}
	}

vector<vector<int>> noktayýbul(Mat resim) {
	Mat imghsv;
	while (true) {
		cvtColor(resim, imghsv, COLOR_BGR2HSV);
		for (int i = 0; i < renkler.size(); i++) {
			Scalar lower(renkler[i][0], renkler[i][1], renkler[i][2]);
			Scalar upper(renkler[i][3], renkler[i][4], renkler[i][5]);
			Mat mask;
			inRange(imghsv, lower, upper, mask);
			Point mypoint = contourbul(mask);
			if (mypoint.x != 0) {
				newPoints.push_back({ mypoint.x, mypoint.y, i });
			}
		}
		return newPoints;
	}
}

void drawOnCanvas(vector<vector<int>> newPoints, vector<Scalar> myColorValues,Mat resim)
{

	for (int i = 0; i < newPoints.size(); i++)
	{
		circle(resim, Point(newPoints[i][0], newPoints[i][1]), 10, myColorValues[newPoints[i][2]], FILLED);
	}
}


int main() {

	Mat resim;
		rengitanýt();
		VideoCapture cap(0);
	   while(true){
		   cap.read(resim);
			newPoints = noktayýbul(resim);
	drawOnCanvas(newPoints, boyanacakrenkler,resim);
	imshow("Image", resim);
	waitKey(1);
}

}
		
	