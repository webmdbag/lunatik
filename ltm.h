/*
** $Id: ltm.h,v 1.15 2000/09/05 19:33:32 roberto Exp roberto $
** Tag methods
** See Copyright Notice in lua.h
*/

#ifndef ltm_h
#define ltm_h


#include "lobject.h"
#include "lstate.h"

/*
* WARNING: if you change the order of this enumeration,
* grep "ORDER IM"
*/
typedef enum {
  IM_GETTABLE = 0,
  IM_SETTABLE,
  IM_INDEX,
  IM_GETGLOBAL,
  IM_SETGLOBAL,
  IM_ADD,
  IM_SUB,
  IM_MUL,
  IM_DIV,
  IM_POW,
  IM_UNM,
  IM_LT,
  IM_CONCAT,
  IM_GC,
  IM_FUNCTION,
  IM_N		/* number of elements in the enum */
} IMS;


struct IM {
  TObject int_method[IM_N];
  TString *collected;  /* list of G. collected udata with this tag */
};


#define luaT_getim(L,tag,event) (&L->IMtable[tag].int_method[event])
#define luaT_getimbyObj(L,o,e)  (&luaT_gettagmethods((L),(o))[e])

extern const char *const luaT_eventname[];


void luaT_init (lua_State *L);
void luaT_realtag (lua_State *L, int tag);
const TObject *luaT_gettagmethods (lua_State *L, const TObject *o);
int luaT_validevent (int t, int e);  /* used by compatibility module */


#endif
