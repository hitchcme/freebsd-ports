diff --git a/libpkg/pkg_elf.c b/libpkg/pkg_elf.c
index 7c75606..165b65d 100644
--- libpkg/pkg_elf.c
+++ libpkg/pkg_elf.c
@@ -636,6 +636,11 @@
 	int ret = EPKG_OK;
 	int i;
 	const char *arch, *abi, *endian_corres_str, *wordsize_corres_str, *fpu;
+	const char *path;
+
+	path = getenv("ABI_FILE");
+	if (path == NULL)
+		path = _PATH_BSHELL;
 
 	if (elf_version(EV_CURRENT) == EV_NONE) {
 		pkg_emit_error("ELF library initialization failed: %s",
@@ -643,7 +648,7 @@
 		return (EPKG_FATAL);
 	}
 
-	if ((fd = open(_PATH_BSHELL, O_RDONLY)) < 0) {
+	if ((fd = open(path, O_RDONLY)) < 0) {
 		pkg_emit_errno("open", _PATH_BSHELL);
 		snprintf(dest, sz, "%s", "unknown");
 		return (EPKG_FATAL);
