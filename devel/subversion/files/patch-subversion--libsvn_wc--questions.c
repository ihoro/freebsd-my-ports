--- subversion/libsvn_wc/questions.c.orig	2010-03-30 22:41:18.000000000 +0300
+++ subversion/libsvn_wc/questions.c	2010-03-30 22:42:27.000000000 +0300
@@ -51,11 +51,16 @@
                 apr_pool_t *pool)
 {
   svn_node_kind_t kind;
+  svn_error_t *err;
   const char *wc_db_path = svn_path_join_many(pool, abspath, ".svn", "wc.db",
                                               NULL);
 
-  SVN_ERR(svn_io_check_path(wc_db_path, &kind, pool));
-
+  err = svn_io_check_path(wc_db_path, &kind, pool);
+  if (err)
+  {
+    svn_error_clear(err);
+    return SVN_NO_ERROR;
+  }
   if (kind == svn_node_file)
     {
       /* This value is completely bogus, but it is much higher than 1.6 will
