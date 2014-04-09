#include "stdafx.h"

#ifdef WRAPPERS_INCLUDE

static void gluaL_register(IntPtr LPtr, System::String ^STR_libname, const luaL_Reg *l) {
	CSTR(libname);
	luaL_register(ToLuaState(LPtr), libname, l);
	DSTR(libname);
}

#define GLUAOPEN_E(N) static void gluaopen_##N (IntPtr LPtr){ luaopen_##N (ToLuaState(LPtr)); }
#define GLUAOPEN(M) GLUAOPEN_E(M)

GLUAOPEN(base)
GLUAOPEN(debug)
//GLUAOPEN(io)		// Y U NO EXIST
GLUAOPEN(math)
GLUAOPEN(os)
GLUAOPEN(package)
GLUAOPEN(string)
GLUAOPEN(table)

static int gluaL_getmetafield(IntPtr LPtr, int obj, System::String ^STR_e) {
	CSTR(e);
	auto RET = luaL_getmetafield(ToLuaState(LPtr), obj, e);
	DSTR(e);
	return RET;
}

static int gluaL_callmeta(IntPtr LPtr, int obj, System::String ^STR_e) {
	CSTR(e);
	auto RET = luaL_callmeta(ToLuaState(LPtr), obj, e);
	DSTR(e);
	return RET;
}

static int gluaL_typerror(IntPtr LPtr, int narg, System::String ^STR_tname) {
	CSTR(tname);
	auto RET = luaL_typerror(ToLuaState(LPtr), narg, tname);
	DSTR(tname);
	return RET;
}

static int gluaL_argerror(IntPtr LPtr, int numarg, System::String ^STR_extramsg) {
	CSTR(extramsg);
	auto RET = luaL_argerror(ToLuaState(LPtr), numarg, extramsg);
	DSTR(extramsg);
	return RET;
}

static System::String ^gluaL_checklstring(IntPtr LPtr, int numArg, size_t *l) {
	return RSTR(luaL_checklstring(ToLuaState(LPtr), numArg, l));
}

static System::String ^gluaL_optlstring(IntPtr LPtr, int numArg, System::String ^STR_def, size_t *l) {
	CSTR(def);
	const char* RET = luaL_optlstring(ToLuaState(LPtr), numArg, def, l);
	DSTR(def);
	return RSTR(RET);
}

static lua_Number gluaL_checknumber(IntPtr LPtr, int numArg) {
	return luaL_checknumber(ToLuaState(LPtr), numArg);
}

static lua_Number gluaL_optnumber(IntPtr LPtr, int nArg, lua_Number def) {
	return luaL_optnumber(ToLuaState(LPtr), nArg, def);
}

static lua_Integer gluaL_checkinteger(IntPtr LPtr, int numArg) {
	return luaL_checkinteger(ToLuaState(LPtr), numArg);
}

static lua_Integer gluaL_optinteger(IntPtr LPtr, int nArg, lua_Integer def) {
	return luaL_optinteger(ToLuaState(LPtr), nArg, def);
}

static void gluaL_checkstack(IntPtr LPtr, int sz, System::String ^STR_msg) {
	CSTR(msg);
	luaL_checkstack(ToLuaState(LPtr), sz, msg);
	DSTR(msg);
}

static void gluaL_checktype(IntPtr LPtr, int narg, int t) {
	return luaL_checktype(ToLuaState(LPtr), narg, t);
}

static void gluaL_checkany(IntPtr LPtr, int narg) {
	return luaL_checkany(ToLuaState(LPtr), narg);
}

static int gluaL_newmetatable(IntPtr LPtr, System::String ^STR_tname) {
	CSTR(tname);
	auto RET = luaL_newmetatable(ToLuaState(LPtr), tname);
	DSTR(tname);
	return RET;
}

static void *gluaL_checkudata(IntPtr LPtr, int ud, System::String ^STR_tname) {
	CSTR(tname);
	void* RET = luaL_checkudata(ToLuaState(LPtr), ud, tname);
	DSTR(tname);
	return RET;
}

static void gluaL_where(IntPtr LPtr, int lvl) {
	return luaL_where(ToLuaState(LPtr), lvl);
}

static int gluaL_error(IntPtr LPtr, System::String ^STR_str) {
	CSTR(str);
	int R = luaL_error(ToLuaState(LPtr), "%s", str);
	return R;
}

// FUNCTION gluaL_checkoption EXPUNGED

static int gluaL_ref(IntPtr LPtr, int t) {
	return luaL_ref(ToLuaState(LPtr), t);
}

static void gluaL_unref(IntPtr LPtr, int t, int ref) {
	return luaL_unref(ToLuaState(LPtr), t, ref);
}

static int gluaL_loadfile(IntPtr LPtr, System::String ^STR_filename) {
	CSTR(filename);
	auto RET = luaL_loadfile(ToLuaState(LPtr), filename);
	DSTR(filename);
	return RET;
}

static int gluaL_loadbuffer(IntPtr LPtr, System::String ^STR_buff, size_t sz, System::String ^STR_name) {
	CSTR(buff); CSTR(name);
	auto RET = luaL_loadbuffer(ToLuaState(LPtr), buff, sz, name);
	DSTR(buff); DSTR(name);
	return RET;
}

static int gluaL_loadstring(IntPtr LPtr, System::String ^STR_s) {
	CSTR(s);
	auto RET = luaL_loadstring(ToLuaState(LPtr), s);
	DSTR(s);
	return RET;
}

static lua_State* gluaL_newstate() {
	return luaL_newstate();
}

static System::String ^gluaL_gsub(IntPtr LPtr, System::String ^STR_s, System::String ^STR_p, System::String ^STR_r) {
	CSTR(s); CSTR(p); CSTR(r);
	const char* RET = luaL_gsub(ToLuaState(LPtr), s, p, r);
	DSTR(s); DSTR(p); DSTR(r);
	return RSTR(RET);
}

static System::String ^gluaL_findtable(IntPtr LPtr, int idx, System::String ^STR_fname, int szhint) {
	CSTR(fname);
	const char* RET =  luaL_findtable(ToLuaState(LPtr), idx, fname, szhint);
	DSTR(fname);
	return RSTR(RET);
}

static void gluaL_buffinit(IntPtr LPtr, luaL_Buffer *B) {
	return luaL_buffinit(ToLuaState(LPtr), B);
}

static char *gluaL_prepbuffer(luaL_Buffer *B) {
	return luaL_prepbuffer(B);
}

static void gluaL_addlstring(luaL_Buffer *B, System::String ^STR_s, size_t l) {
	CSTR(s);
	luaL_addlstring(B, s, l);
	DSTR(s);
}

static void gluaL_addstring(luaL_Buffer *B, System::String ^STR_s) {
	CSTR(s);
	luaL_addstring(B, s);
	DSTR(s);
}

static void gluaL_addvalue(luaL_Buffer *B) {
	return luaL_addvalue(B);
}

static void gluaL_pushresult(luaL_Buffer *B) {
	return luaL_pushresult(B);
}

static lua_State* glua_newstate(lua_Alloc f, void *ud) {
	return lua_newstate(f, ud);
}

static void glua_close(IntPtr LPtr) {
	return lua_close(ToLuaState(LPtr));
}

static lua_State* glua_newthread(IntPtr LPtr) {
	return lua_newthread(ToLuaState(LPtr));
}

static lua_CFunction glua_atpanic(IntPtr LPtr, lua_CFunction panicf) {
	return lua_atpanic(ToLuaState(LPtr), panicf);
}

static int glua_gettop(IntPtr LPtr) {
	return lua_gettop(ToLuaState(LPtr));
}

static void glua_settop(IntPtr LPtr, int idx) {
	return lua_settop(ToLuaState(LPtr), idx);
}

static void glua_pushvalue(IntPtr LPtr, int idx) {
	return lua_pushvalue(ToLuaState(LPtr), idx);
}

static void glua_remove(IntPtr LPtr, int idx) {
	return lua_remove(ToLuaState(LPtr), idx);
}

static void glua_insert(IntPtr LPtr, int idx) {
	return lua_insert(ToLuaState(LPtr), idx);
}

static void glua_replace(IntPtr LPtr, int idx) {
	return lua_replace(ToLuaState(LPtr), idx);
}

static int glua_checkstack(IntPtr LPtr, int sz) {
	return lua_checkstack(ToLuaState(LPtr), sz);
}

static void glua_xmove(lua_State* from, lua_State* to, int n) {
	return lua_xmove(from, to, n);
}

static int glua_isnumber(IntPtr LPtr, int idx) {
	return lua_isnumber(ToLuaState(LPtr), idx);
}

static int glua_isstring(IntPtr LPtr, int idx) {
	return lua_isstring(ToLuaState(LPtr), idx);
}

static int glua_iscfunction(IntPtr LPtr, int idx) {
	return lua_iscfunction(ToLuaState(LPtr), idx);
}

static int glua_isuserdata(IntPtr LPtr, int idx) {
	return lua_isuserdata(ToLuaState(LPtr), idx);
}

static int glua_type(IntPtr LPtr, int idx) {
	return lua_type(ToLuaState(LPtr), idx);
}

static System::String ^glua_typename(IntPtr LPtr, int tp) {
	return RSTR(lua_typename(ToLuaState(LPtr), tp));
}

static int glua_equal(IntPtr LPtr, int idx1, int idx2) {
	return lua_equal(ToLuaState(LPtr), idx1, idx2);
}

static int glua_rawequal(IntPtr LPtr, int idx1, int idx2) {
	return lua_rawequal(ToLuaState(LPtr), idx1, idx2);
}

static int glua_lessthan(IntPtr LPtr, int idx1, int idx2) {
	return lua_lessthan(ToLuaState(LPtr), idx1, idx2);
}

static lua_Number glua_tonumber(IntPtr LPtr, int idx) {
	return lua_tonumber(ToLuaState(LPtr), idx);
}

static System::String ^glua_tostring(IntPtr LPtr, int idx) {
	return RSTR(lua_tostring(ToLuaState(LPtr), idx));
}

static lua_Integer glua_tointeger(IntPtr LPtr, int idx) {
	return lua_tointeger(ToLuaState(LPtr), idx);
}

static int glua_toboolean(IntPtr LPtr, int idx) {
	return lua_toboolean(ToLuaState(LPtr), idx);
}

static System::String ^glua_tolstring(IntPtr LPtr, int idx, size_t *len) {
	return RSTR(lua_tolstring(ToLuaState(LPtr), idx, len));
}

static size_t glua_objlen(IntPtr LPtr, int idx) {
	return lua_objlen(ToLuaState(LPtr), idx);
}

static lua_CFunction glua_tocfunction(IntPtr LPtr, int idx) {
	return lua_tocfunction(ToLuaState(LPtr), idx);
}

static void *glua_touserdata(IntPtr LPtr, int idx) {
	return lua_touserdata(ToLuaState(LPtr), idx);
}

static lua_State* glua_tothread(IntPtr LPtr, int idx) {
	return lua_tothread(ToLuaState(LPtr), idx);
}

static const void *glua_topointer(IntPtr LPtr, int idx) {
	return lua_topointer(ToLuaState(LPtr), idx);
}

static void glua_pushnil(IntPtr LPtr) {
	return lua_pushnil(ToLuaState(LPtr));
}

static void glua_pushnumber(IntPtr LPtr, lua_Number n) {
	return lua_pushnumber(ToLuaState(LPtr), n);
}

static void glua_pushinteger(IntPtr LPtr, lua_Integer n) {
	return lua_pushinteger(ToLuaState(LPtr), n);
}

static void glua_pushlstring(IntPtr LPtr, System::String ^STR_s, size_t l) {
	CSTR(s);
	lua_pushlstring(ToLuaState(LPtr), s, l);
	DSTR(s);
}

static void glua_pushstring(IntPtr LPtr, System::String ^STR_s) {
	CSTR(s);
	lua_pushstring(ToLuaState(LPtr), s);
	DSTR(s);
}

static System::String ^glua_pushvfstring(IntPtr LPtr, System::String ^STR_fmt, va_list argp) {
	CSTR(fmt);
	auto RET = lua_pushvfstring(ToLuaState(LPtr), fmt, argp);
	DSTR(fmt);
	return RSTR(RET);
}

static void glua_pushfstring(IntPtr LPtr, System::String ^STR_fmt, params array<System::Object^> ^Args) {
	System::String ^STR_format = System::String::Format(STR_fmt, Args);
	CSTR(format);
	lua_pushstring(ToLuaState(LPtr), format);
	DSTR(format);
}

static void glua_pushcclosure(IntPtr LPtr, lua_CFunction fn, int n) {
	return lua_pushcclosure(ToLuaState(LPtr), fn, n);
}

static void glua_pushboolean(IntPtr LPtr, int b) {
	return lua_pushboolean(ToLuaState(LPtr), b);
}

static void glua_pushlightuserdata(IntPtr LPtr, void *p) {
	return lua_pushlightuserdata(ToLuaState(LPtr), p);
}

static int glua_pushthread(IntPtr LPtr) {
	return lua_pushthread(ToLuaState(LPtr));
}

static void glua_gettable(IntPtr LPtr, int idx) {
	return lua_gettable(ToLuaState(LPtr), idx);
}

static void glua_getfield(IntPtr LPtr, int idx, System::String ^STR_k) {
	CSTR(k);
	lua_getfield(ToLuaState(LPtr), idx, k);
	DSTR(k);
}

static void glua_rawget(IntPtr LPtr, int idx) {
	return lua_rawget(ToLuaState(LPtr), idx);
}

static void glua_rawgeti(IntPtr LPtr, int idx, int n) {
	return lua_rawgeti(ToLuaState(LPtr), idx, n);
}

static void glua_createtable(IntPtr LPtr, int narr, int nrec) {
	return lua_createtable(ToLuaState(LPtr), narr, nrec);
}

static void *glua_newuserdata(IntPtr LPtr, size_t sz) {
	return lua_newuserdata(ToLuaState(LPtr), sz);
}

static int glua_getmetatable(IntPtr LPtr, int objindex) {
	return lua_getmetatable(ToLuaState(LPtr), objindex);
}

static void glua_getfenv(IntPtr LPtr, int idx) {
	return lua_getfenv(ToLuaState(LPtr), idx);
}

static void glua_settable(IntPtr LPtr, int idx) {
	return lua_settable(ToLuaState(LPtr), idx);
}

static void glua_setfield(IntPtr LPtr, int idx, System::String ^STR_k) {
	CSTR(k);
	lua_setfield(ToLuaState(LPtr), idx, k);
	DSTR(k);
}

static void glua_rawset(IntPtr LPtr, int idx) {
	return lua_rawset(ToLuaState(LPtr), idx);
}

static void glua_rawseti(IntPtr LPtr, int idx, int n) {
	return lua_rawseti(ToLuaState(LPtr), idx, n);
}

static int glua_setmetatable(IntPtr LPtr, int objindex) {
	return lua_setmetatable(ToLuaState(LPtr), objindex);
}

static int glua_setfenv(IntPtr LPtr, int idx) {
	return lua_setfenv(ToLuaState(LPtr), idx);
}

static void glua_call(IntPtr LPtr, int nargs, int nresults) {
	return lua_call(ToLuaState(LPtr), nargs, nresults);
}

static int glua_pcall(IntPtr LPtr, int nargs, int nresults, int errfunc) {
	return lua_pcall(ToLuaState(LPtr), nargs, nresults, errfunc);
}

static int glua_cpcall(IntPtr LPtr, lua_CFunction func, void *ud) {
	return lua_cpcall(ToLuaState(LPtr), func, ud);
}

static int glua_load(IntPtr LPtr, lua_Reader reader, void *dt, System::String ^STR_chunkname) {
	CSTR(chunkname);
	auto RET = lua_load(ToLuaState(LPtr), reader, dt, chunkname);
	DSTR(chunkname);
	return RET;
}

static int glua_dump(IntPtr LPtr, lua_Writer writer, void *data) {
	return lua_dump(ToLuaState(LPtr), writer, data);
}

static int glua_yield(IntPtr LPtr, int nresults) {
	return lua_yield(ToLuaState(LPtr), nresults);
}

/* // FUNCTION glua_resume EXPUNGED
static int glua_resume(IntPtr LPtr, int narg) {
	return lua_resume(ToLuaState(LPtr), narg);
}
*/

static int glua_status(IntPtr LPtr) {
	return lua_status(ToLuaState(LPtr));
}

static int glua_gc(IntPtr LPtr, int what, int data) {
	return lua_gc(ToLuaState(LPtr), what, data);
}

static int glua_error(IntPtr LPtr) {
	return lua_error(ToLuaState(LPtr));
}

static int glua_next(IntPtr LPtr, int idx) {
	return lua_next(ToLuaState(LPtr), idx);
}

static void glua_concat(IntPtr LPtr, int n) {
	return lua_concat(ToLuaState(LPtr), n);
}

static lua_Alloc glua_getallocf(IntPtr LPtr, void **ud) {
	return lua_getallocf(ToLuaState(LPtr), ud);
}

static void glua_setallocf(IntPtr LPtr, lua_Alloc f, void *ud) {
	return lua_setallocf(ToLuaState(LPtr), f, ud);
}

/* // FUNCTION glua_setlevel EXPUNGED
static void glua_setlevel(lua_State* from, lua_State* to) {
	return lua_setlevel(from, to);
}
*/

static int glua_getstack(IntPtr LPtr, int level, lua_Debug *ar) {
	return lua_getstack(ToLuaState(LPtr), level, ar);
}

static int glua_getinfo(IntPtr LPtr, System::String ^STR_what, lua_Debug *ar) {
	CSTR(what);
	auto RET = lua_getinfo(ToLuaState(LPtr), what, ar);
	DSTR(what);
	return RET;
}

static System::String ^glua_getlocal(IntPtr LPtr, const lua_Debug *ar, int n) {
	return RSTR(lua_getlocal(ToLuaState(LPtr), ar, n));
}

static System::String ^glua_setlocal(IntPtr LPtr, const lua_Debug *ar, int n) {
	return RSTR(lua_setlocal(ToLuaState(LPtr), ar, n));
}

static System::String ^glua_getupvalue(IntPtr LPtr, int funcindex, int n) {
	return RSTR(lua_getupvalue(ToLuaState(LPtr), funcindex, n));
}

static System::String ^glua_setupvalue(IntPtr LPtr, int funcindex, int n) {
	return RSTR(lua_setupvalue(ToLuaState(LPtr), funcindex, n));
}

static int glua_sethook(IntPtr LPtr, lua_Hook func, int mask, int count) {
	return lua_sethook(ToLuaState(LPtr), func, mask, count);
}

static lua_Hook glua_gethook(IntPtr LPtr) {
	return lua_gethook(ToLuaState(LPtr));
}

static int glua_gethookmask(IntPtr LPtr) {
	return lua_gethookmask(ToLuaState(LPtr));
}

static int glua_gethookcount(IntPtr LPtr) {
	return lua_gethookcount(ToLuaState(LPtr));
}

#endif