--- driver/dpms.c.orig	2011-01-10 03:41:44.000000000 +0200
+++ driver/dpms.c	2011-05-11 22:29:21.000000000 +0300
@@ -219,15 +219,18 @@
 void
 monitor_power_on (saver_info *si, Bool on_p)
 {
+  BOOL onoff = False;
+  CARD16 state;
+
   if ((!!on_p) != monitor_powered_on_p (si))
     {
       int event_number, error_number;
       if (!DPMSQueryExtension(si->dpy, &event_number, &error_number) ||
-          !DPMSCapable(si->dpy))
+          !DPMSCapable(si->dpy) || !(DPMSInfo(si->dpy, &state, &onoff) && onoff))
         {
           if (si->prefs.verbose_p)
             fprintf (stderr,
-                     "%s: unable to power %s monitor: no DPMS extension.\n",
+                     "%s: unable to power %s monitor: no DPMS extension or it's disabled.\n",
                      blurb(), (on_p ? "on" : "off"));
           return;
         }
