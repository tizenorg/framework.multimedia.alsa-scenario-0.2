noinst_PROGRAMS = \
        scndump \
        alsascn

scndump_SOURCES = \
        dump.c

alsascn_SOURCES = \
	alsa-scn.c

INCLUDES = \
         -Wall -I$(top_srcdir)/src

scndump_LDADD = \
        ../src/libascenario.la -lasound
        
alsascn_LDADD = \
        ../src/libascenario.la -lasound
