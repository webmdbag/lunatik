/*
** $Id: ldebug.h,v 1.27 2002/08/06 15:32:22 roberto Exp roberto $
** Auxiliary functions from Debug Interface module
** See Copyright Notice in lua.h
*/

#ifndef ldebug_h
#define ldebug_h


#include "lstate.h"


#define pcRel(pc, p)	(cast(int, (pc) - (p)->code) - 1)

#define getline(f,pc)	(((f)->lineinfo) ? (f)->lineinfo[pc] : 0)

#define resethookcount(L) \
  (L->hookcount = lua_getmaskcount(L->hookmask), L->hookcount *= L->hookcount)

#define setallowhook(L,cond)	((L->hookmask) = ((L->hookmask) & ~1) | (cond))
#define allowhook(L)		((L->hookmask) & 1)


void luaG_typeerror (lua_State *L, const TObject *o, const char *opname);
void luaG_concaterror (lua_State *L, StkId p1, StkId p2);
void luaG_aritherror (lua_State *L, StkId p1, const TObject *p2);
int luaG_ordererror (lua_State *L, const TObject *p1, const TObject *p2);
void luaG_runerror (lua_State *L, const char *fmt, ...);
void luaG_errormsg (lua_State *L, int internal);
int luaG_checkcode (const Proto *pt);


#endif
