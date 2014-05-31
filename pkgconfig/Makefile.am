pcfiles = libascenario.pc

all-local: $(pcfiles)

%.pc: %.pc
	cp $< $@

pkgconfigdir= $(libdir)/pkgconfig
pkgconfig_DATA= $(pcfiles)

CLEANFILES= $(pcfiles)

pcinfiles= libascenario.pc.in

EXTRA_DIST= $(pcinfiles)

