#include "common.c"
#include <dejagnu.h>
void
output_process(dwg_object *obj);

void
output_object(dwg_object* obj){
  if (!obj)
    {
      printf("object is NULL\n");
      return;
    }

  if (dwg_get_type(obj)== DWG_TYPE_POINT)
    {
      output_process(obj);
    }
}

void
low_level_process(dwg_object *obj)
{
  // casts object to point entity
  dwg_ent_point *point = dwg_object_to_POINT(obj);

  // prints point of point
  printf("points of point : x = %f, y = %f, z = %f\t\n", 
          point->x, point->y, point->z);

  // prints extrusion of point
  printf("extrusion of point : x = %f, y = %f, z = %f\t\n",
          point->extrusion.x, point->extrusion.y, point->extrusion.z);

  // prints thickness
  printf("thickness of point : %f\t\n", point->thickness);
}

void
api_process(dwg_object *obj)
{
  int pt_error, ext_error, thickness_error;
  float thickness;
  dwg_point_3d ext, points;
  dwg_ent_point *point = dwg_object_to_POINT(obj);
 
  // returns point values
  dwg_ent_point_get_point(point, &points, &pt_error);
  if(pt_error == 0 && point->x == points.x && point->y == points.y && point->z == points.z ) // error check
    {
      pass("Working Properly");
    }
  else
    {
      fail("error in reading point");
    }

  // returns extrusion
  dwg_ent_point_get_extrusion(point, &ext, &ext_error);
  if(ext_error == 0 && ext.x == point->extrusion.x && ext.y == point->extrusion.y && ext.z == point->extrusion.z) // error checking
    {
      pass("Working Properly");
    }
  else
    {
      fail("error in reading extrusion");
    }

  // returns thickness
  thickness = dwg_ent_point_get_thickness(point, &thickness_error);
  if(thickness_error == 0 && thickness == point->thickness) // error check
    {
      pass("Working Properly");
    }
  else
    {
      fail("error in reading thickness");
    }
}
