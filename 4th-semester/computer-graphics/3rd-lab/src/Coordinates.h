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

	float dodecahedron[]{
		// 1st pentagon
		(1.0f / ratio), 0.0f, ratio,	 0.851f, 0.0f, 0.526f,
		1.0f, -1.0f, 1.0f,				 0.851f, 0.0f, 0.526f,
		ratio, -(1.0f / ratio), 0.0f,	 0.851f, 0.0f, 0.526f,

		(1.0f / ratio), 0.0f, ratio,     0.851f, 0.0f, 0.526f,
		1.0f, 1.0f, 1.0f,				 0.851f, 0.0f, 0.526f,
		ratio, (1.0f / ratio), 0.0f,	 0.851f, 0.0f, 0.526f,

		(1.0f / ratio), 0.0f, ratio,	 0.851f, 0.0f, 0.526f,
		ratio, (1.0f / ratio), 0.0f,	 0.851f, 0.0f, 0.526f,
		ratio, -(1.0f / ratio), 0.0f,	 0.851f, 0.0f, 0.526f,

		// 2nd pentagon
		(1.0f / ratio), 0.0f, ratio,	 0.0f, -0.526f, 0.851f,
		1.0f, -1.0f, 1.0f,				 0.0f, -0.526f, 0.851f,
		0.0f, -ratio, (1.0f / ratio),	 0.0f, -0.526f, 0.851f,

		-(1.0f / ratio), 0.0f, ratio,	 0.0f, -0.526f, 0.851f,
		-1.0f, -1.0f, 1.0f,				 0.0f, -0.526f, 0.851f,
		0.0f, -ratio, (1.0f / ratio),	 0.0f, -0.526f, 0.851f,

		-(1.0f / ratio), 0.0f, ratio,	 0.0f, -0.526f, 0.851f,
		(1.0f / ratio), 0.0f, ratio,	 0.0f, -0.526f, 0.851f,
		0.0f, -ratio, (1.0f / ratio),	 0.0f, -0.526f, 0.851f,

		// 3rd pentagon
		(1.0f / ratio), 0.0f, ratio,	 0.0f, 0.526f, 0.851f,
		1.0f, 1.0f, 1.0f,				 0.0f, 0.526f, 0.851f,
		0.0f, ratio, (1.0f / ratio),	 0.0f, 0.526f, 0.851f,

		-(1.0f / ratio), 0.0f, ratio,	 0.0f, 0.526f, 0.851f,
		-1.0f, 1.0f, 1.0f,				 0.0f, 0.526f, 0.851f,
		0.0f, ratio, (1.0f / ratio),	 0.0f, 0.526f, 0.851f,

		0.0f, ratio, (1.0f / ratio),	 0.0f, 0.526f, 0.851f,
		(1.0f / ratio), 0.0f, ratio,	 0.0f, 0.526f, 0.851f,
		-(1.0f / ratio), 0.0f, ratio,	 0.0f, 0.526f, 0.851f,

		// 4th pentagon
		-(1.0f / ratio), 0.0f, ratio,	-0.851f, 0.0f, 0.526f,
		-1.0f, -1.0f, 1.0f,				-0.851f, 0.0f, 0.526f,
		-ratio, -(1.0f / ratio), 0.0f,	-0.851f, 0.0f, 0.526f,

		-(1.0f / ratio), 0.0f, ratio,	-0.851f, 0.0f, 0.526f,
		-1.0f, 1.0f, 1.0f,				-0.851f, 0.0f, 0.526f,
		-ratio, (1.0f / ratio), 0.0f,	-0.851f, 0.0f, 0.526f,

		-(1.0f / ratio), 0.0f, ratio,	-0.851f, 0.0f, 0.526f,
		-ratio, -(1.0f / ratio), 0.0f,	-0.851f, 0.0f, 0.526f,
		-ratio, (1.0f / ratio), 0.0f,	-0.851f, 0.0f, 0.526f,

		// 5th pentagon
		1.0f, -1.0f, 1.0f,				 0.526f, -0.851f, 0.0f,
		0.0f, -ratio, (1.0f / ratio),	 0.526f, -0.851f, 0.0f,
		0.0f, -ratio, -(1.0f / ratio),	 0.526f, -0.851f, 0.0f,

		1.0f, -1.0f, 1.0f,				 0.526f, -0.851f, 0.0f,
		ratio, -(1.0f / ratio), 0.0f,	 0.526f, -0.851f, 0.0f,
		1.0f, -1.0f, -1.0f,				 0.526f, -0.851f, 0.0f,

		0.0f, -ratio, -(1.0f / ratio),	 0.526f, -0.851f, 0.0f,
		1.0f, -1.0f, 1.0f,				 0.526f, -0.851f, 0.0f,
		1.0f, -1.0f, -1.0f,				 0.526f, -0.851f, 0.0f,

		// 6th pentagon
		-1.0f, -1.0f, 1.0f,				-0.526f, -0.851f, 0.0f,
		0.0f, -ratio, (1.0f / ratio),	-0.526f, -0.851f, 0.0f,
		0.0f, -ratio, -(1.0f / ratio),	-0.526f, -0.851f, 0.0f,

		-1.0f, -1.0f, 1.0f,				-0.526f, -0.851f, 0.0f,
		-ratio, -(1.0f / ratio), 0.0f,	-0.526f, -0.851f, 0.0f,
		-1.0f, -1.0f, -1.0f,			-0.526f, -0.851f, 0.0f,
		
		-1.0f, -1.0f, -1.0f,			-0.526f, -0.851f, 0.0f,
		-1.0f, -1.0f, 1.0f,				-0.526f, -0.851f, 0.0f,
		0.0f, -ratio, -(1.0f / ratio),	-0.526f, -0.851f, 0.0f,

		// 7th pentagon
		-1.0f, 1.0f, 1.0f,				-0.526f, 0.851f, 0.0f,
		-ratio, (1.0f / ratio), 0.0f,	-0.526f, 0.851f, 0.0f,
		-1.0f, 1.0f, -1.0f,				-0.526f, 0.851f, 0.0f,

		-1.0f, 1.0f, 1.0f,				-0.526f, 0.851f, 0.0f,
		0.0f, ratio, (1.0f / ratio),	-0.526f, 0.851f, 0.0f,
		0.0f, ratio, -(1.0f / ratio),	-0.526f, 0.851f, 0.0f,

		-1.0f, 1.0f, -1.0f,				-0.526f, 0.851f, 0.0f,
		-1.0f, 1.0f, 1.0f,				-0.526f, 0.851f, 0.0f,
		0.0f, ratio, -(1.0f / ratio),	-0.526f, 0.851f, 0.0f,

		// 8th pentagon
		1.0f, 1.0f, 1.0f,				 0.526f, 0.851f, 0.0f,
		ratio, (1.0f / ratio), 0.0f,	 0.526f, 0.851f, 0.0f,
		1.0f, 1.0f, -1.0f,				 0.526f, 0.851f, 0.0f,

		1.0f, 1.0f, 1.0f,				 0.526f, 0.851f, 0.0f,
		0.0f, ratio, (1.0f / ratio),	 0.526f, 0.851f, 0.0f,
		0.0f, ratio, -(1.0f / ratio),	 0.526f, 0.851f, 0.0f,

		0.0f, ratio, -(1.0f / ratio),	 0.526f, 0.851f, 0.0f,
		1.0f, 1.0f, -1.0f,				 0.526f, 0.851f, 0.0f,
		1.0f, 1.0f, 1.0f,				 0.526f, 0.851f, 0.0f,

		// 9th pentagon
		ratio, -(1.0f / ratio), 0.0f,	 0.851f, 0.0f, -0.526f,
		1.0f, -1.0f, -1.0f,				 0.851f, 0.0f, -0.526f,
		(1.0f / ratio), 0.0f, -ratio,	 0.851f, 0.0f, -0.526f,

		ratio, -(1.0f / ratio), 0.0f,	 0.851f, 0.0f, -0.526f,
		ratio, (1.0f / ratio), 0.0f,	 0.851f, 0.0f, -0.526f,
		1.0f, 1.0f, -1.0f,				 0.851f, 0.0f, -0.526f,

		(1.0f / ratio), 0.0f, -ratio,	 0.851f, 0.0f, -0.526f,
		ratio, -(1.0f / ratio), 0.0f,	 0.851f, 0.0f, -0.526f,
		1.0f, 1.0f, -1.0f,				 0.851f, 0.0f, -0.526f,

		// 10th pentagon
		-ratio, (1.0f / ratio), 0.0f,	-0.851f, 0.0f, -0.526f,
		-ratio, -(1.0f / ratio), 0.0f,	-0.851f, 0.0f, -0.526f,
		-1.0f, -1.0f, -1.0f,			-0.851f, 0.0f, -0.526f,

		-ratio, (1.0f / ratio), 0.0f,	-0.851f, 0.0f, -0.526f,
		-1.0f, 1.0f, -1.0f,				-0.851f, 0.0f, -0.526f,
		-(1.0f / ratio), 0.0f, -ratio,	-0.851f, 0.0f, -0.526f,

		-ratio, (1.0f / ratio), 0.0f,	-0.851f, 0.0f, -0.526f,
		-1.0f, -1.0f, -1.0f,			-0.851f, 0.0f, -0.526f,
		-(1.0f / ratio), 0.0f, -ratio,	-0.851f, 0.0f, -0.526f,

		// 11th pentagon
		0.0f, -ratio, -(1.0f / ratio),	 0.0f, -0.526f, -0.851f,
		-1.0f, -1.0f, -1.0f,			 0.0f, -0.526f, -0.851f,
		-(1.0f / ratio), 0.0f, -ratio,	 0.0f, -0.526f, -0.851f,

		0.0f, -ratio, -(1.0f / ratio),	 0.0f, -0.526f, -0.851f,
		1.0f, -1.0f, -1.0f,				 0.0f, -0.526f, -0.851f,
		(1.0f / ratio), 0.0f, -ratio,    0.0f, -0.526f, -0.851f,

		-(1.0f / ratio), 0.0f, -ratio,	 0.0f, -0.526f, -0.851f,
		0.0f, -ratio, -(1.0f / ratio),	 0.0f, -0.526f, -0.851f,
		(1.0f / ratio), 0.0f, -ratio,	 0.0f, -0.526f, -0.851f,

		// 12th pentagon
		0.0f, ratio, -(1.0f / ratio),	 0.0f, 0.526f, -0.851f,
		-1.0f, 1.0f, -1.0f,				 0.0f, 0.526f, -0.851f,
		-(1.0f / ratio), 0.0f, -ratio,	 0.0f, 0.526f, -0.851f,

		0.0f, ratio, -(1.0f / ratio),	 0.0f, 0.526f, -0.851f,
		1.0f, 1.0f, -1.0f,				 0.0f, 0.526f, -0.851f,
		(1.0f / ratio), 0.0f, -ratio,	 0.0f, 0.526f, -0.851f,

		0.0f, ratio, -(1.0f / ratio),	 0.0f, 0.526f, -0.851f,
		-(1.0f / ratio), 0.0f, -ratio,	 0.0f, 0.526f, -0.851f,
		(1.0f / ratio), 0.0f, -ratio,	 0.0f, 0.526f, -0.851f
	};
}

#endif
