/*  GIMP header image file format (RGB): D:\Gregory\Pictures\Androtchi_sprite.h  */

static unsigned int width = 16;
static unsigned int height = 16;

/*  Call this macro repeatedly.  After each use, the pixel data can be extracted  */

#define HEADER_PIXEL(data,pixel) {\
pixel[0] = (((data[0] - 33) << 2) | ((data[1] - 33) >> 4)); \
pixel[1] = ((((data[1] - 33) & 0xF) << 4) | ((data[2] - 33) >> 2)); \
pixel[2] = ((((data[2] - 33) & 0x3) << 6) | ((data[3] - 33))); \
data += 4; \
}
static char *robot_normal =
	"%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1!!!!!!!!!!!!%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1"
	"%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1!!!!U+!!!!!!%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1"
	"%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1!!!!!!!!!!!!%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1"
	"%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1!!!!%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1"
	"%\"!1%\"!1%\"!1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!%\"!1%\"!1%\"!1%\"!1"
	"%\"!1%\"!1%\"!1!!!!S-D)S-D)S-D)S-D)S-D)!!!!S-D)!!!!%\"!1!!!!!!!!%\"!1"
	"%\"!1%\"!1%\"!1!!!!S-D)!!!!S-D)S-D)S-D)S-D)S-D)!!!!%\"!1!!!!%\"!1%\"!1"
	"!!!!!!!!%\"!1!!!!S-D)S-D)!!!!!!!!!!!!S-D)S-D)!!!!!!!!!!!!!!!!%\"!1"
	"%\"!1!!!!!!!!!!!!S-D)S-D)S-D)S-D)S-D)S-D)S-D)!!!!%\"!1%\"!1%\"!1%\"!1"
	"!!!!!!!!%\"!1!!!!S-D)S-D)!!!!!!!!!!!!S-D)S-D)!!!!%\"!1%\"!1%\"!1%\"!1"
	"%\"!1%\"!1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!%\"!1%\"!1%\"!1"
	"%\"!1%\"!1!!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!!!!!%\"!1%\"!1%\"!1"
	"%\"!1%\"!1!!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!!!!!%\"!1%\"!1%\"!1"
	"%\"!1%\"!1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!%\"!1%\"!1%\"!1"
	"%\"!1%\"!1%\"!1!!!!AI+#!!!!%\"!1%\"!1%\"!1!!!!AI+#!!!!%\"!1%\"!1%\"!1%\"!1"
	"%\"!1%\"!1%\"!1%\"!1!!!!%\"!1%\"!1%\"!1%\"!1%\"!1!!!!%\"!1%\"!1%\"!1%\"!1%\"!1"
	"";

static char *robot_mad =
	"%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1$AY/$Q]0%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1"
	"%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1!!!!!!!!!!!!%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1"
	"!!!!%\"!1!!!!%\"!1%\"!1%\"!1!!!!U+!!!!!!%\"!1%\"!1%\"!1!!!!%\"!1!!!!%\"!1"
	"!!!!!!!!!!!!%\"!1%\"!1%\"!1!!!!!!!!!!!!%\"!1%\"!1%\"!1!!!!!!!!!!!!%\"!1"
	"%\"!1!!!!%\"!1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!%\"!1!!!!%\"!1%\"!1"
	"%\"!1!!!!%\"!1!!!!S-D)!!!!S-D)S-D)S-D)!!!!S-D)!!!!%\"!1!!!!%\"!1%\"!1"
	"%\"!1%\"!1!!!!!!!!S-D)!!!!!!!!S-D)!!!!!!!!S-D)!!!!!!!!%\"!1%\"!1%\"!1"
	"%\"!1%\"!1%\"!1!!!!S-D)S-D)S-D)S-D)S-D)S-D)S-D)!!!!%\"!1%\"!1%\"!1%\"!1"
	"%\"!1%\"!1%\"!1!!!!S-D)S-D)!!!!!!!!!!!!S-D)S-D)!!!!%\"!1%\"!1%\"!1%\"!1"
	"%\"!1%\"!1%\"!1!!!!S-D)!!!!!!!!!!!!!!!!!!!!S-D)!!!!%\"!1%\"!1%\"!1%\"!1"
	"%\"!1%\"!1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!%\"!1%\"!1%\"!1"
	"%\"!1%\"!1!!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!!!!!%\"!1%\"!1%\"!1"
	"%\"!1%\"!1!!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!!!!!%\"!1%\"!1%\"!1"
	"%\"!1%\"!1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!%\"!1%\"!1%\"!1"
	"%\"!1%\"!1!!!!%\"!1!!!!%\"!1%\"!1%\"!1%\"!1%\"!1!!!!%\"!1!!!!%\"!1%\"!1%\"!1"
	"%\"!1%\"!1%\"!1!!!!%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1!!!!%\"!1%\"!1%\"!1%\"!1"
	"";