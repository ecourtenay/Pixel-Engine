#include "PixGL.h"

PixGL void SetValues(float pw_, float ph_, float sw_, float sh_, float ww_, float wh_)
{
	pw = pw_;
	ph = ph_;
	sw = sw_;
	sh = sh_;
	ww = ww_;
	wh = wh_;
}

PixGL void RenderUnitPixels(int width, int height, const Pixel* pixels)
{
	glBegin(GL_POINTS);
	for (int i = 0; i < width; i++)
	{
		float nx = (float)i / width;
		float px = nx * 2 - 1;

		for (int j = 0; j < height; j++)
		{
			Pixel p = pixels[j * width + i];

			float ny = (float)j / height;
			float py = ny * 2 - 1;

			glColor3ub(p.r, p.g, p.b);
			glVertex2f(px, -py);
		}
	}
	glEnd();
}

PixGL void RenderPixels(int width, int height, int pixW, int pixH, const Pixel* pixels)
{
	glBegin(GL_QUADS);
	for (int i = 0; i < width; i++)
	{
		float x1 = (float)i / width;
		float x2 = (float)(i + 1) / width;

		float nx1 = x1 * 2 - 1;
		float nx2 = x2 * 2 - 1;

		for (int j = 0; j < height; j++)
		{
			Pixel p = pixels[j * width + i];

			float y1 = (float)j / height;
			float y2 = (float)(j + 1) / height;

			float ny1 = y1 * 2 - 1;
			float ny2 = y2 * 2 - 1;

			glColor3ub(p.r, p.g, p.b);
			
			glVertex2f(nx1, -ny1);
			glVertex2f(nx1, -ny2);
			glVertex2f(nx2, -ny2);
			glVertex2f(nx2, -ny1);
		}
	}
	glEnd();
}

PixGL void RenderText(int width, int height, const Pixel* pixels)
{
	glBegin(GL_POINTS);

	for (int i = 0; i < width; i++)
	{
		float nx = (float)i / width;
		float kx = nx * 2 - 1;

		for (int j = 0; j < height; j++)
		{
			Pixel p = pixels[j * width + i];

			if (p.a == 0)
				continue;

			float ny = (float)j / height;
			float ky = ny * 2 - 1;

			glColor3ub(p.r, p.g, p.b);
			glVertex2f(kx, -ky);
		}
	}
	glEnd();
}