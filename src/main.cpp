#include <svVoronoiCore.h>

#include "Bitmap.cpp"
#include "example.cpp"

#include <iostream>

//using namespace sv;

int main(int argc, char *argv[]) {

	//directions.emplace_back(
  MyBitmap bmp{512, 512};
  Voronoi v;
  //v.Make(&bmp, 20);

  int width = 200, height = 200;

  
	if (argc < 2) {
		std::cout << "Usage: " << argv[0] << " [Number of cells]\n";
		return 1;
	}

	int cellCount = std::stoi(argv[1]);
	auto generated_points = generatePoints(cellCount);

	sv::SphericalVoronoiCore voronoi(generated_points);


    while(!voronoi.isFinished()) {
      voronoi.step(1);
    }


  auto const &points = voronoi.getVertices();
  assert(points.size()> 0);

  int w = bmp.width(), h = bmp.height(), d;
  for (int hh = 0; hh < h; hh++) {
    for (int ww = 0; ww < w; ww++) {
      int ind = -1, dist = INT_MAX;
      for(sv::vertex_ptr v : points) {
        auto &p = v->point;
        //std::cout << p.position.x << ", " << p.position.y << " \n";
        d = DistanceSqrd(p.position.x*width, p.position.y*height , ww, hh);
        if (d < dist) {
          dist = d;
          //ind = v.index;
        }

      }
#if 0
      for (size_t it = 0; it < points.size(); it++) {
        //sv::Point const &p = points[it];//points[it];
        sv::vertex &p = *points[it];//points[it];
        d = DistanceSqrd(Point(p.x, p.y), ww, hh);
        if (d < dist) {
          dist = d;
          ind = it;
        }
      }
#endif
 
      if (ind > -1)
        bmp.SetPixel(ww, hh, 0x07, 0xff, 0x07);
      //else
      //__asm nop // should never happen!
    } 
  }

 
  std::cout << voronoi.getVertices().size() << std::endl; 

  bmp.SaveBitmap("./test.bmp");

  return 0;
};


