#ifndef COORDINATES_H
#define COORDINATES_H

#include <numbers>

namespace coords
{
	const float ratio{ std::numbers::phi_v<float> };

	float icosahedron[]{
		// vertices              normal vectors
		0.0f, ratio, -1.0f,		 0.357f, 0.934f, 0.0f,
		0.0f, ratio, 1.0f,		 0.357f, 0.934f, 0.0f,
		ratio, 1.0f, 0.0f,		 0.357f, 0.934f, 0.0f,

		0.0f, ratio, -1.0f,		-0.357f, 0.934f, 0.0f,
		0.0f, ratio, 1.0f,		-0.357f, 0.934f, 0.0f,
		-ratio, 1.0f, 0.0f,		-0.357f, 0.934f, 0.0f,

		0.0f, ratio, -1.0f,		 0.0f, 0.357f, -0.934f,
		-1.0f, 0.0f, -ratio,	 0.0f, 0.357f, -0.934f,
		1.0f, 0.0f, -ratio,		 0.0f, 0.357f, -0.934f,

		0.0f, ratio, 1.0f,		 0.0f, 0.357f, 0.934f,
		1.0f, 0.0f, ratio,		 0.0f, 0.357f, 0.934f,
		-1.0f, 0.0f, ratio,		 0.0f, 0.357f, 0.934f,

		0.0f, ratio, -1.0f,		-0.577f, 0.577f, -0.577f,
		-1.0f, 0.0f, -ratio,	-0.577f, 0.577f, -0.577f,
		-ratio, 1.0f, 0.0f,		-0.577f, 0.577f, -0.577f,

		0.0f, ratio, -1.0f,		 0.577f, 0.577f, -0.577f,
		1.0f, 0.0f, -ratio,		 0.577f, 0.577f, -0.577f,
		ratio, 1.0f, 0.0f,		 0.577f, 0.577f, -0.577f,

		0.0f, ratio, 1.0f,		 0.577f, 0.577f, 0.577f,
		1.0f, 0.0f, ratio,		 0.577f, 0.577f, 0.577f,
		ratio, 1.0f, 0.0f,		 0.577f, 0.577f, 0.577f,

		0.0f, ratio, 1.0f,		-0.577f, 0.577f, 0.577f,
		-1.0f, 0.0f, ratio,		-0.577f, 0.577f, 0.577f,
		-ratio, 1.0f, 0.0f,		-0.577f, 0.577f, 0.577f,

		ratio, 1.0f, 0.0f,		 0.934f, 0.0f, 0.357f,
		ratio, -1.0f, 0.0f,		 0.934f, 0.0f, 0.357f,
		1.0f, 0.0f, ratio,		 0.934f, 0.0f, 0.357f,

		ratio, 1.0f, 0.0f,		 0.934f, 0.0f, -0.357f,
		ratio, -1.0f, 0.0f,		 0.934f, 0.0f, -0.357f,
		1.0f, 0.0f, -ratio,		 0.934f, 0.0f, -0.357f,

		-ratio, -1.0f, 0.0f,	-0.934f, 0.0f, 0.357f,
		-ratio, 1.0f, 0.0f,		-0.934f, 0.0f, 0.357f,
		-1.0f, 0.0f, ratio,		-0.934f, 0.0f, 0.357f,

		-ratio, -1.0f, 0.0f,	-0.934f, 0.0f, -0.357f,
		-ratio, 1.0f, 0.0f,		-0.934f, 0.0f, -0.357f,
		-1.0f, 0.0f, -ratio,	-0.934f, 0.0f, -0.357f,

		1.0f, 0.0f, ratio,		 0.0f, -0.357f, 0.934f,
		0.0f, -ratio, 1.0f,		 0.0f, -0.357f, 0.934f,
		-1.0f, 0.0f, ratio,		 0.0f, -0.357f, 0.934f,

		1.0f, 0.0f, -ratio,		 0.0f, -0.357f, -0.934f,
		0.0f, -ratio, -1.0f,	 0.0f, -0.357f, -0.934f,
		-1.0f, 0.0f, -ratio,	 0.0f, -0.357f, -0.934f,

		0.0f, -ratio, 1.0f,		 0.577f, -0.577f, 0.577f,
		1.0f, 0.0f, ratio,		 0.577f, -0.577f, 0.577f,
		ratio, -1.0f, 0.0f,		 0.577f, -0.577f, 0.577f,

		0.0f, -ratio, 1.0f,		-0.577f, -0.577f, 0.577f,
		-1.0f, 0.0f, ratio,		-0.577f, -0.577f, 0.577f,
		-ratio, -1.0f, 0.0f,	-0.577f, -0.577f, 0.577f,

		0.0f, -ratio, -1.0f,	 0.577f, -0.577f, -0.577f,
		1.0f, 0.0f, -ratio,		 0.577f, -0.577f, -0.577f,
		ratio, -1.0f, 0.0f,		 0.577f, -0.577f, -0.577f,

		0.0f, -ratio, -1.0f,	-0.577f, -0.577f, -0.577f,
		-1.0f, 0.0f, -ratio,	-0.577f, -0.577f, -0.577f,
		-ratio, -1.0f, 0.0f,	-0.577f, -0.577f, -0.577f,

		0.0f, -ratio, -1.0f,	 0.357f, -0.934f, 0.0f,
		0.0f, -ratio, 1.0f,		 0.357f, -0.934f, 0.0f,
		ratio, -1.0f, 0.0f,		 0.357f, -0.934f, 0.0f,

		0.0f, -ratio, -1.0f,	-0.357f, -0.934f, 0.0f,
		0.0f, -ratio, 1.0f,		-0.357f, -0.934f, 0.0f,
		-ratio, -1.0f, 0.0f,	-0.357f, -0.934f, 0.0f
	};
}

#endif
