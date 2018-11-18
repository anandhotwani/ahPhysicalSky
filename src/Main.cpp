#include "Renderer.h"

int main()
{
	Renderer render;

	// Options
	render.Width = 1080;
	render.Height = 1080;
	render.Colorspace = ACEScg;
	render.SunSize = 0.27f;
	render.Turbidity = 4.0f;
	render.SunTint = Vector3f(1);
	render.SkyTint = Vector3f(1);
	render.GroundAlbedo = Vector3f(0.18);
	render.SunColor = Vector3f(20000);
	render.bEnableSun = 1;
	render.Samples = 128;
	
	std::cout<<">>> Rendering Colorspaces, 0 - XYZ, 1 - sRGB, 2 - ACEScg, 3 = ACES 2065-1 "<<std::endl;
	std::cout<<">>> Rendering with colorspace : "<<render.Colorspace<<std::endl;

	for (unsigned i = 0; i < render.Samples; ++i) {
		char filename[1080 * 3];
		sprintf(filename, "./skydome.1%03d.exr", i);
		float angle = i / float(render.Samples - 1.0f) * M_PI * -0.6f;
		fprintf(stderr, ">>> Rendering Hosek-Wilkie Sky Model image %d. Angle = %0.2f\n", i, angle * 180.0f / M_PI);

		render.RenderSkyDome(Vector3f(0, cos(angle), -sin(angle)),
			filename,
			render.Width,
			render.Height,
			render.SunSize,
			render.SunColor,
			render.GroundAlbedo,
			render.Turbidity,
			render.SkyTint,
			render.SunTint,
			render.bEnableSun,
			render.Colorspace);

	}

	return EXIT_SUCCESS;
}