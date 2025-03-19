#pragma warning(disable:4996)
#pragma comment( lib, "shell32.lib")
#include <iostream>
#include <cmath>
#include "pngwriter.h"
using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
//All The fuctions used
// 1)Arrow() 2)bezier() 3)bezier_blend() 4)boundary_fill() 5)filledsquare_blend() 6)circle() 7)filledcircle_blend() 8)cross() 9)diamond() 10)filledarrow()
// 11)dread() 12)dreadHSV() 13)filledcircle() 14)filleddiamond() 15)filledsquare() 16)filledtriangle() 17)flood_fill() 18)flood_fill_blend() 19)line() 20)line_blend()
// 21)maltesecross() 22)plot() 23)plot_blend() 24)plot_text() 25)plotCMYK() 26)plotHSV() 27)polygon() 28)read() 29)readCMYK() 30)readHSV()
// 31)setcompressionLevel() 32)setgama,() 33)settext() 34)triange() 35)filledtriangle_blend() 36)getgama() 

//Student ID#: 400009491 
//Student Name: Kyle Cox
//Art Theme: My Childhood drawing

//Description  
//Back when I was younger, I used to draw this picture over and over again because, 
//to me, it was the best thing I could create at the time.
//Anytime someone asked me to draw something, I’d always sketch this exact scene.
//Now that I’ve grown up and have the skills now to turn it into a digital PNG image, 
//I wanted to recreate my childhood drawing and bring it to life in a new way.

int main()
{// Creating the PNG image
	pngwriter* image = new pngwriter(600, 600, 0.2, "400009491.png");

	//Metadata
  image->settext("The View of the Town", "Kyle Cox","A stunning digital rendering capturing the essence of a bustling town.", "");

	//set gamma and get
	image->setgamma(0.4);
	double gama = image->getgamma();
	
	cout << "The gama is " << gama;
	//set compression Level
	image->setcompressionlevel(0);

	// Place in the Blue Background for the sky
	image->flood_fill(600, 600, 0, 35000, 55000);

	// Creating the sun
	image->filledcircle(1, 600, 100, 55000, 60000, 10000);

	// Adding sun rays
	int centerX = 1;
	int centerY = 600;
	int radius = 100;
	int rayLength = 50; 
	int numRays = 32; 

	for (int i = 0; i < numRays; i++) {
		double angle = (2 * M_PI * i) / numRays;
		int startX = centerX + (int)(radius * cos(angle));
		int startY = centerY + (int)(radius * sin(angle));
		int endX = centerX + (int)((radius + rayLength) * cos(angle));
		int endY = centerY + (int)((radius + rayLength) * sin(angle));
		image->line(startX, startY, endX, endY, 55000, 60000, 10000); 
	}

	//Creating clouds
	//Cloud top right
	image->filledcircle(560, 540, 50, 65535, 65535, 65535);
	image->filledcircle(500, 540, 45, 65535, 65535, 65535);
	image->filledcircle(540, 520, 35, 65535, 65535, 65535);
	image->filledcircle(580, 550, 40, 65535, 65535, 65535);
	image->filledcircle(490, 560, 30, 65535, 65535, 65535);
	image->filledcircle(530, 570, 45, 65535, 65535, 65535);
	image->bezier_blend(470, 560, 480, 565, 490, 560, 480, 565, 0.4, 54103, 54103, 54103);
	image->bezier_blend(490, 560, 500, 565, 510, 560, 500, 565, 0.4, 54103, 54103, 54103);
	image->bezier_blend(500, 520, 510, 525, 520, 520, 510, 525, 0.4, 54103, 54103, 54103);
	image->bezier_blend(520, 520, 530, 525, 540, 520, 530, 525, 0.4, 54103, 54103, 54103);
	image->bezier_blend(560, 550, 570, 555, 580, 550, 570, 555, 0.4, 54103, 54103, 54103);
	image->bezier_blend(580, 550, 590, 555, 600, 550, 590, 555, 0.4, 54103, 54103, 54103);
	
	int white = image->read(530, 570, 1);
	//cloud left
	image->filledcircle(180, 500, 30, white, white, white);
	image->filledcircle(210, 490, 35, white, white, white);
	image->filledcircle(160, 480, 28, white, white, white);
	image->filledcircle(190, 470, 40, white, white, white);
	image->filledcircle(210, 460, 32, white, white, white);
	image->bezier_blend(150, 500, 160, 505, 170, 500, 160, 505, 0.6, 54103, 54103, 54103);
	image->bezier_blend(170, 500, 180, 505, 190, 500, 180, 505, 0.6, 54103, 54103, 54103);
	image->bezier_blend(200, 460, 210, 465, 220, 460, 210, 465, 0.6, 54103, 54103, 54103);
	image->bezier_blend(220, 460, 230, 465, 240, 460, 230, 465, 0.6, 54103, 54103, 54103);
	
	//cloud bottom right
	image->filledcircle(480, 350, 30, white, white, white);
	image->filledcircle(510, 340, 40, white, white, white);
	image->filledcircle(460, 330, 28, white, white, white);
	image->filledcircle(500, 320, 35, white, white, white);
	image->filledcircle(550, 340, 42, white, white, white);
	image->filledcircle(570, 350, 30, white, white, white);
	image->bezier_blend(480,350,490,355,500,350, 490, 355 ,0.6, 54103, 54103, 54103);
	image->bezier_blend(500, 350, 510, 355, 520, 350, 510, 355, 0.6, 54103, 54103, 54103);
	image->bezier_blend(550, 360, 560, 365, 570, 360, 560, 365, 0.6, 54103, 54103, 54103);
	image->bezier_blend(570, 360, 580, 365, 590, 360, 580, 365, 0.6, 54103, 54103, 54103);
	image->bezier_blend(530, 320, 540, 325, 550, 320, 540, 325, 0.6, 54103, 54103, 54103);
	image->bezier_blend(550, 320, 560, 325, 570, 320, 560, 325, 0.6, 54103, 54103, 54103);

	
	//Creating the plane frame
	image->square(150, 350, 400, 400, 1, 1, 1);
	image->triangle(100, 350, 150, 400,150,350, 1, 1, 1);
	image->line(400, 350, 500, 450, 1, 1, 1);
	image->line(400, 400, 450, 450, 1, 1, 1);
	image->line(500, 450, 550, 450, 1, 1, 1);
	image->line(450, 450, 400, 450, 1, 1, 1);
	image->line(550, 450, 550, 475, 1, 1, 1);
	image->line(400, 450, 400, 475, 1, 1, 1);
	image->line(400, 475, 550, 475, 1, 1, 1);

	//Creating the plane wings
	//Up wing
	image->line(200, 400, 300, 500, 1, 1, 2);
	image->line(250, 400, 350, 500, 1, 1, 2);
	image->line(300, 500, 350, 500, 1, 1, 2);
	image->diamond(320, 470, 20,20, 1, 1, 1);
	image->diamond(280, 430, 20, 20, 1, 1, 1);
	image->arrow(340, 470, 370, 470, 5, 10.0, white, white, white);
	image->filledarrow(300, 430, 330, 430, 5, 10.0, white, white, white);

	//Bottom wing
	image->line(200, 350, 300, 250, 1, 1, 2);
	image->line(250, 350, 350, 250, 1, 1, 2);
	image->line(300, 250, 350, 250, 1, 1, 2);
	image->diamond(280, 320, 20, 20, 1, 1, 1);
	image->diamond(320, 280, 20, 20, 1, 1, 1);
	image->arrow(300, 320, 330, 320, 5, 10.0, white, white, white);
	image->filledarrow(340, 280, 380, 280, 5, 10.0, white, white, white);
	

	//Creating plane windows
	image->circle(225, 375, 5, 5000, 60000, 100);
	image->circle(275, 375, 5, 64000, 4000, 100);
	image->circle(325, 375, 5, 57000, 40000, 1000);
	image->flood_fill(275, 360, 65535, 0, 0);

	//Plane pattern and colour
	image->line(225, 350, 260, 400, 1, 1, 1);
	image->line(320, 400, 285, 350, 1, 1, 1);
	image->bezier(150, 400, 170, 380, 100, 350, 170, 360,1,1,1);
	image->bezier(149, 401, 170, 380, 99, 350, 170, 360, 1, 1, 1);
	
	//Hide lines
	image->line(150, 351, 150, 399, 0, 35000, 55000);
	image->line(400, 351, 400, 399, 0, 35000, 55000);
	
	//plane colour
	//color plane engine
	image->boundary_fill(280, 321,1, 1, 1, 12850, 0, 23130);
	image->boundary_fill(280, 431, 1, 1, 1, 12850, 0, 23130);
	image->boundary_fill(320, 471, 1, 1, 1, 12850, 0, 23130);
	image->boundary_fill(320, 281, 1, 1, 1, 12850, 0, 23130);


	image->flood_fill(355, 375, 32768, 32768, 32768);
	image->flood_fill(175, 375, 32768, 32768, 32768);
	image->flood_fill(300, 475, 32768, 32768, 32768);
	image->flood_fill(300, 280, 32768, 32768, 32768);
	image->flood_fill(355, 375, 32768, 32768, 32768);
	image->flood_fill(450, 410, 32768, 32768, 32768);
	image->flood_fill(120, 360, 65535, 0, 0);
	image->filledtriangle(120, 351, 150, 362, 150, 351, 32768, 32768, 32768);
	
	//Plane logo
	char* label = (char*)("Boeing 747");
	char* fontPath = (char*)("Mayonice.ttf");
	image->plot_text(fontPath, 10, 410, 378, 44.80, label, 1, 1, 1);

	//Creating the House1
	//roof
	image->filledtriangle_blend(100, 150, 175, 250, 250, 150, 0.7,13000, 500, 1);
	//chimney
	image->filledsquare(210, 180, 220, 220, 600, 500, 300);
	image->filleddiamond(215, 230, 10, 10, 23000, 30000, 30000);
	image->filleddiamond(215, 243, 10, 10, 23000, 30000, 30000);
	image->filleddiamond(215, 256, 10, 10, 23000, 30000, 30000);
	image->filleddiamond(215, 256, 10, 10, 23000, 30000, 30000);


	//house frame
	image->square(100, 1,250,150, 1, 1, 1);
	//house door
	image->square(160, 1, 190, 70, 1, 1, 1);
	double doorknobs = image->dread(295, 30, 1);
	image->filledcircle(165, 30, 3.0, doorknobs, doorknobs, doorknobs);
	//Window left
	image->filledsquare(110, 110, 140, 140, 2000, 3000, 55000);
	image->cross(125,125,30,30, 1, 1, 1);
	image->filledsquare_blend(105, 105, 145, 110, 1.0, 10100, 10100, 10100);
	image->line_blend(110, 109, 140, 109,0.6, 1, 1, 1);
	image->line_blend(110, 108, 140, 108, 0.4, 1, 1, 1);
	image->line(114, 128, 118, 138, white, white, white);
	image->line(118, 128, 122, 136, white, white, white);
	image->line(130, 112, 138, 122, white, white, white);
	image->line(130, 118, 134, 122, white, white, white);
	
	//Window right
	image->filledsquare(210, 110, 240, 140, 2000, 3000, 55000);
	image->cross(225, 125, 30, 30, 1, 1, 1);
	image->filledsquare_blend(205, 105, 245, 110, 1.0, 10100, 10100, 10100);
	image->line_blend(210, 109, 240, 109, 0.6, 1, 1, 1);
	image->line_blend(210, 108, 240, 108, 0.4, 1, 1, 1);

	image->line(214, 128, 218, 138, white, white, white);
	image->line(218, 128, 222, 136, white, white, white);
	image->line(230, 112, 238, 122, white, white, white);
	image->line(230, 118, 234, 122, white, white, white);
	
	//print house
	image->flood_fill(150, 50, 64000, 50333, 30000);
	//print door
	image->flood_fill(175, 50, 66000, 62000, 500);
	
	
	//Creating the House2
	//house frame
	image->square(350, 1,500 , 150, 1, 1, 1);
	//house door
	image->square(410, 1, 440, 70, 1, 1, 1);
	image->filledcircle(418, 30, 3, 1, 1, 1);
	//roof
	image->filledtriangle(350, 150, 425, 250, 500, 150, 30000, 30, 60);
	//Window left
	image->filledsquare(360, 110, 390, 140, 51400, 59082, 65535);
	image->maltesecross(375,125, 30, 30,30,30, 1, 1, 1);
	image->filledsquare_blend(355, 105 ,395, 110, 1.0, 30000, 300, 600);
	image->line_blend(360, 109, 390, 109, 0.6, 1, 1, 1);
	image->line_blend(360, 108, 390, 108, 0.4, 1, 1, 1);
	image->line(380, 112, 388, 122, white, white, white);
	image->line(380, 118, 384, 122, white, white, white);
	image->line(368, 128, 372, 134, white, white, white);
	image->line(364, 127, 370, 138, white, white, white);
	//Window right
	image->filledsquare(460, 110, 490, 140, 51400, 59082, 65535);
	image->maltesecross(475, 125, 30, 30, 30, 30, 1, 1, 1);
	image->filledsquare_blend(455, 105, 495, 110, 1.0, 30000, 30, 60);
	image->line_blend(460, 109, 490, 109, 0.6, 1, 1, 1);
	image->line_blend(460, 108, 490, 108, 0.4, 1, 1, 1);
	image->line(480, 112, 488, 122, white, white, white);
	image->line(480, 118, 484, 122, white, white, white);
	image->line(468, 128, 472, 134, white, white, white);
	image->line(464, 127, 470, 138, white, white, white);
	//Center window
	image->filledcircle(425, 100, 15, 51400, 59082, 65535);
	image->cross(425, 100, 25, 25, 1, 1, 1);

	//print house
	image->flood_fill_blend(370, 50,0.9, 40000, 10000, 40000);
	//print door
	image->flood_fill(420, 55, 63232, 1000, 10000);
	
	
	//Creating the grass
	image->line(1,50,100,50, 1, 1, 1);
	image->line(1, 51, 100, 51, 1, 1, 1);
	image->line(250, 50, 350, 50, 1, 1, 1);
	image->line(250, 51, 350, 51, 1, 1, 1);
	image->line(500, 50, 600, 50, 1, 1, 1);
	image->line(500, 51, 600, 51, 1, 1, 1);
	image->flood_fill(30, 30, 10000, 65000, 0);
	image->flood_fill(310, 30, 10000, 65000, 0);
	image->flood_fill(510, 30, 10000, 65000, 0);
    
	//Creating tree1 center
	image->filledsquare(290, 25, 300, 90, 139, 69, 19);  
	int points[14] = {
		280,  90,  
		270, 100,  
		283, 140,  
		310, 140,  
		320, 100,  
		310, 90,
		280,  90,
	};
	image->polygon(points, 7, 34, 139, 34);  
	image->flood_fill(300,100, 30000, 65000, 0);
	
	//Creating friut
	// Orange fruit (Top-left)
	image->plotCMYK(285, 105, 0.0, 1.0, 1.0, 0.0);
	double redColorforOrangeFriut = image->readCMYK(285, 105, 1); 
	double greenColorOrangeFriut = image->readCMYK(285, 105, 2);
	double blueColorforOrangeFriut = image->readCMYK(285, 105, 3);


	image->plotCMYK(286, 105, 0.0, redColorforOrangeFriut, greenColorOrangeFriut, blueColorforOrangeFriut);
	image->plotCMYK(284, 105, 0.0, redColorforOrangeFriut, greenColorOrangeFriut, blueColorforOrangeFriut);
	image->plotCMYK(285, 106, 0.0, redColorforOrangeFriut, greenColorOrangeFriut, blueColorforOrangeFriut);
	image->plotCMYK(285, 104, 0.0, redColorforOrangeFriut, greenColorOrangeFriut, blueColorforOrangeFriut);
	image->plotCMYK(286, 106, 0.0, redColorforOrangeFriut, greenColorOrangeFriut, blueColorforOrangeFriut);
	image->plotCMYK(284, 104, 0.0, redColorforOrangeFriut, greenColorOrangeFriut, blueColorforOrangeFriut);

	// Red fruit (Top-right)
	image->plotCMYK(310, 105, 0.0, 1.0, 0.0, 0.0);
	image->plotCMYK(311, 105, 0.0, 1.0, 0.0, 0.0);
	image->plotCMYK(309, 105, 0.0, 1.0, 0.0, 0.0);
	image->plotCMYK(310, 106, 0.0, 1.0, 0.0, 0.0);
	image->plotCMYK(310, 104, 0.0, 1.0, 0.0, 0.0);
	image->plotCMYK(311, 106, 0.0, 1.0, 0.0, 0.0);
	image->plotCMYK(309, 104, 0.0, 1.0, 0.0, 0.0);

	// Yellow fruit (Bottom-left)
	image->plotCMYK(285, 130, 0.2, 0.0, 1.0, 0.0);
	image->plotCMYK(286, 130, 0.2, 0.0, 1.0, 0.0);
	image->plotCMYK(284, 130, 0.2, 0.0, 1.0, 0.0);
	image->plotCMYK(285, 131, 0.2, 0.0, 1.0, 0.0);
	image->plotCMYK(285, 129, 0.2, 0.0, 1.0, 0.0);
	image->plotCMYK(286, 131, 0.2, 0.0, 1.0, 0.0);
	image->plotCMYK(284, 129, 0.2, 0.0, 1.0, 0.0);

	// Peach-colored fruit (Center)
	image->plotCMYK(295, 115, 0.0, 0.5, 1.0, 0.0);
	image->plotCMYK(296, 115, 0.0, 0.5, 1.0, 0.0);
	image->plotCMYK(294, 115, 0.0, 0.5, 1.0, 0.0);
	image->plotCMYK(295, 116, 0.0, 0.5, 1.0, 0.0);
	image->plotCMYK(295, 114, 0.0, 0.5, 1.0, 0.0);
	image->plotCMYK(296, 116, 0.0, 0.5, 1.0, 0.0);
	image->plotCMYK(294, 114, 0.0, 0.5, 1.0, 0.0);

	// Dark red fruit (Bottom-right)
	image->plotCMYK(310, 130, 0.4, 1.0, 0.0, 0.0);
	image->plotCMYK(311, 130, 0.4, 1.0, 0.0, 0.0);
	image->plotCMYK(309, 130, 0.4, 1.0, 0.0, 0.0);
	image->plotCMYK(310, 131, 0.4, 1.0, 0.0, 0.0);
	image->plotCMYK(310, 129, 0.4, 1.0, 0.0, 0.0);
	image->plotCMYK(311, 131, 0.4, 1.0, 0.0, 0.0);
	image->plotCMYK(309, 129, 0.4, 1.0, 0.0, 0.0);

	
	//Createing Tree2 right
	image->filledsquare(550, 10, 560, 80, 139, 69, 25);
	int points1[16] = {
		530,  80,
		509, 90,
		 530, 120,
		550, 140,
		580, 120,
		590, 91,
		580,  80,
		530,80
	};
	image->polygon(points1, 8, 34, 139, 34);
	image->flood_fill(549, 93, 35000, 62000, 0);
	//Places friuts 
	// Orange fruit
	image->plotCMYK(540, 110, 0.0, 1.0, 1.0, 0.0);
	image->plotCMYK(541, 110, 0.0, 1.0, 1.0, 0.0);
	image->plotCMYK(539, 110, 0.0, 1.0, 1.0, 0.0);
	image->plotCMYK(540, 111, 0.0, 1.0, 1.0, 0.0);
	image->plotCMYK(540, 109, 0.0, 1.0, 1.0, 0.0);
	image->plotCMYK(541, 111, 0.0, 1.0, 1.0, 0.0);
	image->plotCMYK(539, 109, 0.0, 1.0, 1.0, 0.0);

	// Red fruit
	image->plotCMYK(560, 115, 0.0, 1.0, 0.0, 0.0);
	image->plotCMYK(561, 115, 0.0, 1.0, 0.0, 0.0);
	image->plotCMYK(559, 115, 0.0, 1.0, 0.0, 0.0);
	image->plotCMYK(560, 116, 0.0, 1.0, 0.0, 0.0);
	image->plotCMYK(560, 114, 0.0, 1.0, 0.0, 0.0);
	image->plotCMYK(561, 116, 0.0, 1.0, 0.0, 0.0);
	image->plotCMYK(559, 114, 0.0, 1.0, 0.0, 0.0);

	// Yellow fruit
	image->plotCMYK(520, 100, 0.2, 0.0, 1.0, 0.0);
	image->plotCMYK(521, 100, 0.2, 0.0, 1.0, 0.0);
	image->plotCMYK(519, 100, 0.2, 0.0, 1.0, 0.0);
	image->plotCMYK(520, 101, 0.2, 0.0, 1.0, 0.0);
	image->plotCMYK(520, 99, 0.2, 0.0, 1.0, 0.0);
	image->plotCMYK(521, 101, 0.2, 0.0, 1.0, 0.0);
	image->plotCMYK(519, 99, 0.2, 0.0, 1.0, 0.0);

	// Peach-colored fruit
	image->plotCMYK(545, 125, 0.0, 0.5, 1.0, 0.0);
	image->plotCMYK(546, 125, 0.0, 0.5, 1.0, 0.0);
	image->plotCMYK(544, 125, 0.0, 0.5, 1.0, 0.0);
	image->plotCMYK(545, 126, 0.0, 0.5, 1.0, 0.0);
	image->plotCMYK(545, 124, 0.0, 0.5, 1.0, 0.0);
	image->plotCMYK(546, 126, 0.0, 0.5, 1.0, 0.0);
	image->plotCMYK(544, 124, 0.0, 0.5, 1.0, 0.0);

	// Dark red fruit
	image->plotCMYK(570, 105, 0.4, 1.0, 0.0, 0.0);
	image->plotCMYK(571, 105, 0.4, 1.0, 0.0, 0.0);
	image->plotCMYK(569, 105, 0.4, 1.0, 0.0, 0.0);
	image->plotCMYK(570, 106, 0.4, 1.0, 0.0, 0.0);
	image->plotCMYK(570, 104, 0.4, 1.0, 0.0, 0.0);
	image->plotCMYK(571, 106, 0.4, 1.0, 0.0, 0.0);
	image->plotCMYK(569, 104, 0.4, 1.0, 0.0, 0.0);

	//car
	image->filledtriangle(30,65,50,75,60,65,63000,63000,640000);
	image->line_blend(50, 75, 50, 54,9.0 ,1, 1, 1);
	image->filledsquare(20,53, 70, 65, 4000, 10333, 5300);
	image->filledcircle(30, 53, 5, 1, 1, 1);
	image->filledcircle(60, 53, 5, 1, 1, 1);
	image->plot(23, 60, white, white, white);
	//rear lights
	image->plotHSV(68, 60, 1, 1, 1);
	double redlightHSV = image->readHSV(68, 60, 1);
	double greenLightHSV = image->readHSV(68, 60, 2);
	double blueLightHSV = image->readHSV(68, 60, 3);
	image->plotHSV(67, 60, redlightHSV, greenLightHSV, blueLightHSV);
	//car doorknob
	double cardoorKnob = image->dreadHSV(67, 60, 3);
	image->plot_blend(48, 60, 0.7, cardoorKnob, cardoorKnob, cardoorKnob);
	image->plot_blend(47, 60, 0.7, cardoorKnob, cardoorKnob, cardoorKnob);
	image->plot_blend(46, 60, 0.7, cardoorKnob, cardoorKnob, cardoorKnob);
	image->plot_blend(45, 60, 0.7, cardoorKnob, cardoorKnob, cardoorKnob);
	//car muffer smoke
	image->filledcircle_blend(77, 56, 2, 0.80, 23000, 30000, 30000);
	image->filledcircle_blend(83, 59, 2, 0.80, 23000, 30000, 30000);

	
	//person 1
	image->line(97, 10, 90, 20, 1, 1, 1);
	image->line(83, 10, 90, 20, 1, 1, 1);
	image->line(90, 20, 90, 45, 1, 1, 1);
	image->line(90, 30, 80, 35, 1, 1, 1);
	image->line(90,30,100,35, 1, 1, 1);
	image->filledcircle(90, 46, 4, 1, 1, 1);
	
	//person 2
	image->line(523,10,530,20, 1, 1, 1);
	image->line(537, 10, 530, 20, 1, 1, 1);
	image->line(530, 20, 530, 45, 1, 1, 1);
	image->line(530, 30, 540, 20, 1, 1, 1);
	image->line(530, 30, 523, 40, 1, 1, 1);
	image->filledcircle(530, 46, 4, 1, 1, 1);
	 
	//birds
	//bird1
	image->bezier(300, 590, 320, 590, 320, 570, 320, 580, 1, 1, 1);
	image->bezier(350, 590, 320, 590, 320, 570, 320, 580, 1, 1, 1);
	//bird2
	image->bezier_blend(70, 300, 70, 310, 50, 330, 70, 330, 0.1,1, 1, 1);
	image->bezier_blend(70, 300, 70, 310, 100, 330, 70, 330,0.1, 1, 1, 1);
	

	//creating hot air bollon
	image->square(30,100,70,120,1,1,1);
	image->line(30, 120, 20, 150, 1, 1, 1);
	image->line(70, 120, 80, 150, 1, 1, 1);
	image->line(50, 120, 50, 150, 1, 1, 1);
	image->line(20, 150, 80, 150, 1, 1, 1);

	int points2[18] = {
	80,150,
	20,150,
	-20,200,
	-20,240,
	20,270,
	80,270,
	110,240,
	110,200,
	80,150,
	};
	image->polygon(points2, 9, 1,1,1);
	image->line(50, 150, 50, 270, 1, 1, 1);
	image->bezier(40, 150, 10, 190, 40, 270, 10, 210, 1, 1, 1);
	image->bezier(60, 150, 90, 190, 60, 270, 90, 210, 1, 1, 1);
	//print
	image->flood_fill(50, 101, 65355, 26889, 46138);
	image->flood_fill(100, 200, 65535, 400, 0);
	image->flood_fill(60, 200, 600, 65535, 50);
	image->flood_fill(40, 200, 32768, 0, 32768);
	image->flood_fill(2, 200, 65535, 65535, 0);
	

	char* fontPath1 = (char*)("Arial.ttf");
	char* label1 = (char*)("Student ID# 400009491");
	char* label2 = (char*)("Student Name Kyle Cox");
	char* label3 = (char*)("Theme: My Childhood drawing");
	image->plot_text(fontPath1, 6, 480, 240,0.0, label1, 1, 1, 1);
	image->plot_text(fontPath1, 6, 480, 230, 0.0, label2, 1, 1, 1);
	image->plot_text(fontPath1, 5, 470, 220, 0.0, label3, 1, 1, 1);

	// table
	image->line(310, 20, 330, 20, 40000, 10000, 8000);
	image->line(310, 21, 330,21, 40000, 10000, 8000);
	image->line(300, 3, 315,20, 40000, 10000, 8000);
	image->line(340, 3, 325, 20, 40000, 10000, 8000);
	image->line(300, 11, 304, 11, 40000, 10000, 8000);
	image->line(340, 11, 337, 11, 40000, 10000, 8000);
	image->line(300, 10, 340, 10, 40000, 10000, 8000);
	image->close();
	return 0;
} 