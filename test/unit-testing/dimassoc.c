// TODO unstable
#define DWG_TYPE DWG_TYPE_DIMASSOC
#include "common.c"

void
api_process (dwg_object *obj)
{
  int error, isnew;
  BITCODE_BL associativity;
  BITCODE_RC trans_space_flag;
  Dwg_DIMASSOC_Ref *ref;
  BITCODE_BS num_mainobjs;
  BITCODE_H *mainobjs;
  BITCODE_BL intsect_gsmarker;
  BITCODE_H dimensionobj;
  BITCODE_H xrefobj;
  BITCODE_H intsectxrefobj;

  Dwg_Version_Type dwg_version = obj->parent->header.version;
  dwg_obj_dimassoc *dimassoc = dwg_object_to_DIMASSOC (obj);

  if (obj->fixedtype == DWG_TYPE_UNKNOWN_OBJ)
    return;

  CHK_ENTITY_TYPE (dimassoc, DIMASSOC, associativity, BLx, associativity);
  CHK_ENTITY_MAX (dimassoc, DIMASSOC, associativity, BL, 15);
  CHK_ENTITY_TYPE (dimassoc, DIMASSOC, trans_space_flag, RCd, trans_space_flag);
  CHK_ENTITY_MAX (dimassoc, DIMASSOC, trans_space_flag, RCd, 1);
  if (!dwg_dynapi_entity_value (dimassoc, "DIMASSOC", "ref", &ref, NULL))
    fail ("DIMASSOC.ref");
  for (int i = 0; i < 4; i++)
    {
      // 0 1 2 3 => 1 2 4 8. skip unset bits
      if (!(associativity & (1<<i)))
        continue;
      CHK_SUBCLASS_TYPE (ref[i], DIMASSOC_Ref, has_lastpt_ref, B);
      CHK_SUBCLASS_UTF8TEXT (ref[i], DIMASSOC_Ref, classname); // "AcDbOsnapPointRef"
      CHK_SUBCLASS_TYPE (ref[i], DIMASSOC_Ref, osnap_type, RC);
      CHK_SUBCLASS_MAX (ref[i], DIMASSOC_Ref, osnap_type, RC, 13);
      CHK_SUBCLASS_TYPE (ref[i], DIMASSOC_Ref, main_subent_type, BS);
      CHK_SUBCLASS_TYPE (ref[i], DIMASSOC_Ref, main_gsmarker, BL);
      CHK_SUBCLASS_TYPE (ref[i], DIMASSOC_Ref, intsect_subent_type, BS);
      CHK_SUBCLASS_MAX (ref[i], DIMASSOC_Ref, intsect_subent_type, BS, 2);
      CHK_SUBCLASS_TYPE (ref[i], DIMASSOC_Ref, osnap_dist, BD);
      CHK_SUBCLASS_3RD (ref[i], DIMASSOC_Ref, osnap_pt);
      CHK_SUBCLASS_TYPE (ref[i], DIMASSOC_Ref, num_mainobjs, BS);
      CHK_SUBCLASS_MAX (ref[i], DIMASSOC_Ref, num_mainobjs, BS, 100);
      //CHK_SUBCLASS_HV (ref[i], DIMASSOC_Ref, mainobjs);
      if (!dwg_dynapi_subclass_value (&ref[i], "DIMASSOC_Ref", "mainobjs",
                                      &mainobjs, NULL))
        fail ("DIMASSOC_Ref.mainobjs");
      else if (!mainobjs)
        pass ();
      for (BITCODE_BS j = 0; j < ref[i].num_mainobjs; j++)
        {
          BITCODE_H _hdl = mainobjs[j];
          char *_hdlname = dwg_dynapi_handle_name (obj->parent, _hdl);
          if (_hdl == ref[i].mainobjs[j])
            {
              if (g_counter > g_countmax)
                pass ();
              else
                {
                  if (_hdl)
                    ok ("DIMASSOC_Ref[%d].mainobjs[%u]: %s " FORMAT_REF, i, j,
                        _hdl && _hdlname ? _hdlname : "", ARGS_REF (_hdl));
                  else
                    ok ("DIMASSOC_Ref[%d].mainobjs[%u]: NULL", i, j);
                }
            }
          else
            {
              if (_hdl)
                fail ("DIMASSOC_Ref[%d].mainobjs[%u]: %s " FORMAT_REF, i, j,
                      _hdlname ? _hdlname : "", ARGS_REF (_hdl));
              else
                fail ("DIMASSOC_Ref[%d].mainobjs[%u]: NULL", i, j);
            }
          if (dwg_version >= R_2007)
            free (_hdlname);
        }
      CHK_SUBCLASS_H (ref[i], DIMASSOC_Ref, intsectobj);
    }
  CHK_ENTITY_TYPE (dimassoc, DIMASSOC, intsect_gsmarker, BL, intsect_gsmarker);
  CHK_ENTITY_H (dimassoc, DIMASSOC, dimensionobj, dimensionobj);
  CHK_ENTITY_H (dimassoc, DIMASSOC, xrefobj, xrefobj);
  CHK_ENTITY_H (dimassoc, DIMASSOC, intsectxrefobj, intsectxrefobj);
}
