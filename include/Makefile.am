alsaincludedir = ${includedir}/alsa

alsainclude_HEADERS = ascenario.h

DISTCLEANFILES = stamp-vh version.h

version.h: stamp-vh alsa
	@:

stamp-vh: $(top_builddir)/configure.in
	@echo "/*" > ver.tmp
	@echo " *  version.h" >> ver.tmp
	@echo " */" >> ver.tmp
	@echo "" >> ver.tmp
	@echo "#define SND_LIB_MAJOR		$(SND_LIB_MAJOR) /**< major number of library version */" >> ver.tmp
	@echo "#define SND_LIB_MINOR		$(SND_LIB_MINOR) /**< minor number of library version */" >> ver.tmp
	@echo "#define SND_LIB_SUBMINOR	$(SND_LIB_SUBMINOR) /**< subminor number of library version */" >> ver.tmp
	@echo "#define SND_LIB_EXTRAVER	$(SND_LIB_EXTRAVER) /**< extra version number, used mainly for betas */" >> ver.tmp
	@echo "/** library version */" >> ver.tmp
	@echo "#define SND_LIB_VERSION		((SND_LIB_MAJOR<<16)|\\" >> ver.tmp
	@echo "				 (SND_LIB_MINOR<<8)|\\" >> ver.tmp
	@echo "				  SND_LIB_SUBMINOR)" >> ver.tmp
	@echo "/** library version (string) */" >> ver.tmp
	@echo "#define SND_LIB_VERSION_STR	\"$(SND_LIB_VERSION)\"" >> ver.tmp
	@echo >> ver.tmp
	@cmp -s version.h ver.tmp \
          || (echo "Updating version.h"; \
              cp ver.tmp version.h; \
              echo timestamp > stamp-vh)
	-@rm -f ver.tmp

INCLUDES=-I$(top_srcdir)/include

