--- src/gource.cpp.orig	2009-11-25 21:35:08.000000000 +0200
+++ src/gource.cpp	2009-11-25 21:35:49.000000000 +0200
@@ -402,7 +402,7 @@
         char datestr[256];
 
         // TODO: memory leak ??
-        struct tm* timeinfo = localtime ( &(commit.timestamp) );
+        struct tm* timeinfo = localtime ( (const time_t *) &(commit.timestamp) );
         strftime(datestr, 256, "%A, %d %B, %Y", timeinfo);
 
         date = std::string(datestr);
@@ -1224,7 +1224,7 @@
     //display date
     char datestr[256];
     char timestr[256];
-    struct tm* timeinfo = localtime ( &currtime );
+    struct tm* timeinfo = localtime ( (const time_t *) &currtime );
 
     strftime(datestr, 256, gGourceDateFormat.c_str(), timeinfo);
     displaydate = datestr;
