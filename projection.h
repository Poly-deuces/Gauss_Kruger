#pragma once
#include<iostream>  
#include<cmath> 
#define M_PI 3.14159265358979323846
using namespace std;

class gauss_kruger
{
public:
	void set_coordinates()
	{
		to_radius();
	}
	void transformation()
	{
		calculation();
	}
private:
	double B; double L; double l; double B_rad;
	void to_radius()
	{
		cout << "Enter latitude and longitude: ";
		cin >> B >> L;
		B_rad = B * M_PI / 180.0;
		double L0 = 6 * (int((L + 3) / 6)) - 3;
		l = (L - L0) * M_PI / 180;
	}

	void calculation()
	{
		double a = 6378137.0;
		double b = 6356752.31414;
		double a_2 = a * a;
		double b_2 = b * b;
		double e1 = sqrt((a_2 - b_2) / a_2);
		double e2 = sqrt((a_2 - b_2) / b_2);
		double e2_2 = e2 * e2;
		double e1_2 = e1 * e1;
		double e1_4 = e1 * e1 * e1 * e1;
		double e1_6 = e1 * e1 * e1* e1* e1* e1;
		double e1_8 = e1 * e1 * e1 * e1 * e1 * e1 * e1 * e1;
		double A0 = 1 + 3 / 4 * e1_2 + 45 / 64 * e1_4 + 350 / 512 * e1_6 + 11025 / 16384 * e1_8;
		double A2 = -1 / 2 * (3 / 4 * e1_2 + 60 / 64 * e1_4 + 525 / 512 * e1_6 + 17640 / 16384 * e1_8);
		double A4 = -1 / 4 * (15 / 64 * e1_4 + 210 / 512 * e1_6 + 8820 / 16384 * e1_8);
		double A6 = -1 / 6 * (35 / 512 * e1_6 + 2520 / 16384 * e1_8);
		double A8 = 1 / 8 * (315 / 16384 * e1_8);
		double x1 = a * (1 - e1_4) * (A0 * B_rad + A2 * sin(2 * B_rad) + A4 * sin(4 * B_rad) + A6 * sin(6 * B_rad) + A8 * sin(8 * B_rad));
		double l_2 = l * l;
		double l_4 = l_2 * l_2;
		double tanB_2 = tan(B_rad) * tan(B_rad);
		double tanB_4 = tan(B_rad) * tan(B_rad)*tan(B_rad) * tan(B_rad);
		double cosB_2 = cos(B_rad) * cos(B_rad);
		double cosB_3 = cos(B_rad) * cos(B_rad) * cos(B_rad);
		double cosB_4 = cos(B_rad) * cos(B_rad) * cos(B_rad) * cos(B_rad);
		double cosB_5 = cos(B_rad) * cos(B_rad) * cos(B_rad) * cos(B_rad) * cos(B_rad);
		double eta_2 = cosB_4 * e2_2;
		double eta_4 = eta_2 * eta_2;
		double N = a / sqrt(1 - e1_2 * sin(B_rad) * sin(B_rad));
		double x = x1 + (N * tan(B_rad) * cosB_2 * l_2) / 2 + (N * tan(B_rad) * (5 - tanB_2 + 9 * eta_2 + 4 * eta_4) * cosB_4 * l_4) / 24 + (N * tan(B_rad) * (61 - 58 * tanB_2 + tanB_4) * cosB_4 * cosB_2) / 720;
		double y = N * cos(B_rad) * l + (N * (1 - tanB_2 + eta_2) * cosB_3 * l_2 * l) / 6 + (N * (5 - 18 * tanB_2 + tanB_4 + 14 * eta_2 - 58 * eta_2 * tanB_2) * cosB_5 * l_4 * l) / 120;
		cout << "x=" << x << "\n" << "y=" << y<<"\n" << endl;
	}
};