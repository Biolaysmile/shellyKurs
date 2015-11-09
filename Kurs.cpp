/* 
_________________Задание:_________________


*/

#include <iostream>
#include <math.h>

//Метка : А если не создавать 2 массива. 1 с x y , а второй с x y z, А все координаты ввести с клавиатуры, на свой выбор и потом сравнивать координаты?
//У которых Z = значению > 0 с теми, у которых Z = 0.

using namespace std;

struct Point //Наша точка, координаты x,y,z
{
	int x, y, z;
};

struct LINE //Сторона квадрата из 2ух точек
{
	Point p1, p2; // Точки p1.x, p1.y/ p2.x,p2.y
};

//Функция,  растояния между точками
double distance1(Point tl, Point tr)
{
	double l = sqrt(double(tr.x - tl.x)*(tr.x - tl.x) + (tr.y - tl.y)*(tr.y - tl.y)); // Проработать структуры LINE , Point
	return l; //Возвращаем длину
};

//Альтернативная функция проверка на квадрат
/*
bool issquare_alt(Point tl, Point bl, Point br, Point tr)
{
	double d12 = Distance1(tl, bl);
	double d13 = Distance1(tl, br);
	double d14 = Distance1(tl, tr);
	double d23 = Distance1(bl, br);
	double d24 = Distance1(bl, tr);
	double d34 = Distance1(br, tr);

	return d12 == d23 && d23 == d34 && d34 == d14 && d13 == d24  // 1-2-3-4
		|| d13 == d23 && d23 == d24 && d24 == d14 && d12 == d34  // 1-3-2-4
		|| d12 == d24 && d24 == d34 && d34 == d13 && d14 == d23; // 1-2-4-3
}
*/

// Функция провекри квадрата и его сторон
bool isquare(Point tl, Point bl, Point br, Point tr)
{
	if (tl.x != tr.x && bl.x != br.x) return false;
	if (tl.y != bl.y && tr.y != br.y) return false;
	if (distance1(tl, tr) != distance1(tl, bl)) return false;
	return true;
};

/*
//Функция проверки пересечения точки диагонали квадрата и координаты точки в плоскости Z на проекцию.
bool z_to_diagonal(точка пересечения диагоналей, координата z) {
	//Воодим точки 
	cout << "Введите точки в плоскости X Y Z: \n";
	cout << "X =";
	cin >> tl.x;
	cout << "Y =";
	cin >> tl.y;
	cout << "Z =";
	cin >> tl.z;
	/////////////

    


}

//Функция высчитывающая высоту
int height_piramid(сторона квадрата) {

	double h = 

}

//Функция вычисляющая объем правильной четырехугольной пирамиды
double vol_piramid(Point tl, Point tr) {

	double vol;
	vol = (height_piramid(storona, diagonal) / 3) * (distance1(tl,tr) * distance1(tl, tr));
	return vol;
}
*/

//Функция поиска квадратов

void search_square(int n, Point tl, Point bl, Point br, Point tr) {

	int j, k, l, i;


	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			for (k = j + 1; k < n; k++) {
				for (l = k + 1; k < n; k++) {
					isquare(tl, bl, br, tr);
				}
			}
		}
	}
}

//Функция ввода точек

void input_points(Point& tl, int i) {

	cout << "Координата № " << i + 1 << "\n";
	cout << "X=";
	cin >> tl.x;
	cout << "Y=";
	cin >> tl.y;
	cout << "\n";
	
}


//Oсновная функция
int main() {
	setlocale(LC_ALL, "Russian");
	LINE line;
	Point tl, tr, bl, br; // tl -TopLeft, tr - TopRight, bl - BotLeft, br - BotRight -  точки
	int n, i = 0;

	/////////////////////////////////////////
	cout << "Введите количество точек:";
	cin >> n;

		input_points(tl, i);
		input_points(tr, i);
		input_points(br, i);
		input_points(bl, i);
		search_square(1, tl, bl, br, tr);

	
	
	cout << "Первая координата :" << "(" << tl.x << ":" << tl.y << ")" << endl
		<< "Вторая координата :" << "(" << bl.x << ":" << bl.y << ")" << endl
		<< "Третья координата :" << "(" << br.x << ":" << br.y << ")" << endl
		<< "Четвертая координата" << "(" << tr.x << ":" << tr.y << ")" << endl;

	system("pause");
	return 0;
}
	

