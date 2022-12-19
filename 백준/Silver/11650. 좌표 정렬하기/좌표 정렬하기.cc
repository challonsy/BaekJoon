#include <iostream>
#include<algorithm>
using namespace std;

class Point {
public:
	int x;
	int y;
};

bool comp(Point point1, Point point2){
	if (point1.x == point2.x)
		return point1.y < point2.y;
	else
		return point1.x < point2.x;
}

int main() {
	int numOfPoint;
	Point* points;
	cin >> numOfPoint;
	points = new Point[numOfPoint];
	
	for (int i = 0; i < numOfPoint; i++)
		cin >> points[i].x >> points[i].y;

	sort(points, points + numOfPoint, comp);

	for (int i = 0; i < numOfPoint; i++)
		cout << points[i].x <<" "<< points[i].y<<"\n";
}
