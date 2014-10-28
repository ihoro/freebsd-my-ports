--- X11/xf_win.c.orig	2011-11-21 22:51:29.000000000 +0200
+++ X11/xf_win.c	2011-11-21 23:02:51.000000000 +0200
@@ -1058,6 +1058,12 @@
 		snprintf(win_title, sizeof(win_title), "%s:%d - freerdp", xfi->settings->server, xfi->settings->tcp_port_rdp);
 	XStoreName(xfi->display, xfi->wnd, win_title);
 
+	XClassHint* class_hint = XAllocClassHint();
+	class_hint->res_name = "xfreerdp";
+	class_hint->res_class = "XFreeRDP";
+	XSetClassHint(xfi->display, xfi->wnd, class_hint);
+	XFree(class_hint);
+
 	input_mask =
 		KeyPressMask | KeyReleaseMask | ButtonPressMask | ButtonReleaseMask |
 		VisibilityChangeMask | FocusChangeMask | StructureNotifyMask |
