--- ./third_party/webrtc/modules/desktop_capture/desktop_capture.gypi.orig	2014-04-24 22:37:06.000000000 +0200
+++ ./third_party/webrtc/modules/desktop_capture/desktop_capture.gypi	2014-04-24 23:23:48.000000000 +0200
@@ -99,6 +99,11 @@
             ],
           },
         }],
+        ['os_bsd==1', {
+          'include_dirs': [
+            '<(prefix_dir)/include',
+          ],
+        }],
         ['OS!="win" and OS!="mac" and use_x11==0', {
           'sources': [
             "mouse_cursor_monitor_null.cc",
