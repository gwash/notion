/*
 * ion/ioncore/mplex.h
 *
 * Copyright (c) Tuomo Valkonen 1999-2003. 
 * See the included file LICENSE for details.
 */

#ifndef ION_IONCORE_MPLEX_H
#define ION_IONCORE_MPLEX_H

#include "common.h"
#include "window.h"
#include "attach.h"
#include "extl.h"

#define WMPLEX_ADD_TO_END 0x0001
#define WMPLEX_MANAGED_UNVIEWABLE 0x0002

INTROBJ(WMPlex);

DECLOBJ(WMPlex){
	WWindow win;
	int flags;
	int managed_count;
	WRegion *managed_list;
	WRegion *current_sub;
	WRegion *current_input;
};


/* Create/destroy */
extern bool mplex_init(WMPlex *mplex, WWindow *parent,
					   Window win, WRectangle geom);
extern void mplex_deinit(WMPlex *mplex);

/* Resize and reparent */
extern bool mplex_reparent(WMPlex *mplex, WWindow *parent,
						   WRectangle geom);
extern void mplex_fit(WMPlex *mplex, WRectangle geom);

/* Mapping */
extern void mplex_map(WMPlex *mplex);
extern void mplex_unmap(WMPlex *mplex);

/* Attach */
extern WRegion *mplex_add_input(WMPlex *mplex, WRegionAddFn *fn,
								void *fnp);
extern void mplex_remove_managed(WMPlex *mplex, WRegion *reg);
extern void mplex_fit_managed(WMPlex *mplex);
extern void mplex_attach_tagged(WMPlex *mplex);

/* Switch */
extern bool mplex_display_managed(WMPlex *mplex, WRegion *sub);
extern void mplex_switch_nth(WMPlex *mplex, uint n);
extern void mplex_switch_next(WMPlex *mplex);
extern void mplex_switch_prev(WMPlex *mplex);

/* Focus */
extern void mplex_focus(WMPlex *mplex, bool warp);

/* Misc */
extern WRegion *mplex_nth_managed(WMPlex *mplex, uint n);
extern int mplex_managed_count(WMPlex *mplex);
extern ExtlTab mplex_managed_list(WMPlex *mplex);
extern WRegion *mplex_current(WMPlex *mplex);
extern WRegion *mplex_current_input(WMPlex *mplex);
extern void mplex_move_current_right(WMPlex *mplex);
extern void mplex_move_current_left(WMPlex *mplex);

/* Dynfuns */
DYNFUN void mplex_managed_geom(const WMPlex *mplex, WRectangle *geom);
DYNFUN void mplex_size_changed(WMPlex *mplex, bool wchg, bool hchg);
DYNFUN void mplex_managed_changed(WMPlex *mplex, bool sw);
DYNFUN void mplex_managed_added(WMPlex *mplex, WRegion *nreg, bool sw);
DYNFUN void mplex_managed_removed(WMPlex *mplex, WRegion *oreg, bool sw);

#endif /* ION_IONCORE_MPLEX_H */