// TODO DEBUGGING
#define DWG_TYPE DWG_TYPE_ALDIMOBJECTCONTEXTDATA
#include "common.c"

void
api_process (dwg_object *obj)
{
  int error, isnew;
  BITCODE_BS class_version; /*!< r2010+ =4 */
  BITCODE_B has_file;
  BITCODE_B defaultflag;
  BITCODE_H scale;
  BITCODE_T name;
  BITCODE_2RD def_pt;
  BITCODE_B b293;
  BITCODE_B b294;
  BITCODE_BD bd140;
  BITCODE_B b298;
  BITCODE_B b291;
  BITCODE_BS flag;
  BITCODE_B b292;
  BITCODE_BS bs71;
  BITCODE_B b280;
  BITCODE_B b295;
  BITCODE_B b296;
  BITCODE_B b297;
  // AcDbAlignedDimensionObjectContextData
  BITCODE_3BD _11pt;

  Dwg_Version_Type dwg_version = obj->parent->header.version;
#ifdef DEBUG_CLASSES
  dwg_obj_aldimobjectcontextdata *_obj = dwg_object_to_ALDIMOBJECTCONTEXTDATA (obj);

  CHK_ENTITY_TYPE (_obj, ALDIMOBJECTCONTEXTDATA, class_version, BL, class_version);
  //CHK_ENTITY_TYPE (_obj, ALDIMOBJECTCONTEXTDATA, has_file, B, has_file);
  CHK_ENTITY_TYPE (_obj, ALDIMOBJECTCONTEXTDATA, defaultflag, B, defaultflag);
  CHK_ENTITY_H (_obj, ALDIMOBJECTCONTEXTDATA, scale, scale);
  CHK_ENTITY_UTF8TEXT (_obj, ALDIMOBJECTCONTEXTDATA, name, name);
  CHK_ENTITY_2RD (_obj, ALDIMOBJECTCONTEXTDATA, def_pt, def_pt);
  CHK_ENTITY_TYPE (_obj, ALDIMOBJECTCONTEXTDATA, b293, B, b293);
  CHK_ENTITY_TYPE (_obj, ALDIMOBJECTCONTEXTDATA, b294, B, b294);
  CHK_ENTITY_TYPE (_obj, ALDIMOBJECTCONTEXTDATA, bd140, BD, bd140);
  CHK_ENTITY_TYPE (_obj, ALDIMOBJECTCONTEXTDATA, b298, B, b298);
  CHK_ENTITY_TYPE (_obj, ALDIMOBJECTCONTEXTDATA, b291, B, b291);
  CHK_ENTITY_TYPE (_obj, ALDIMOBJECTCONTEXTDATA, flag, BS, flag);
  CHK_ENTITY_TYPE (_obj, ALDIMOBJECTCONTEXTDATA, b292, B, b292);
  CHK_ENTITY_TYPE (_obj, ALDIMOBJECTCONTEXTDATA, bs71, BS, bs71);
  CHK_ENTITY_TYPE (_obj, ALDIMOBJECTCONTEXTDATA, b280, B, b280);
  CHK_ENTITY_TYPE (_obj, ALDIMOBJECTCONTEXTDATA, b295, B, b295);
  CHK_ENTITY_TYPE (_obj, ALDIMOBJECTCONTEXTDATA, b296, B, b296);
  CHK_ENTITY_TYPE (_obj, ALDIMOBJECTCONTEXTDATA, b297, B, b297);
  CHK_ENTITY_3RD (_obj, ALDIMOBJECTCONTEXTDATA, _11pt, _11pt);
#endif
}
