
VPATH=$(srcdir) $(builddir)

lib_LTLIBRARIES = libnfctag.la

libnfctag_la_CXXFLAGS = 				\
	$(LIB_NFCTAG_CXXFLAGS)				\
        -I${srcdir}/..                                  \
        -I${srcdir}/.                                   \
        -Wno-deprecated-declarations                    \
        -Wno-unused-parameter                           \
        -fPIC

libnfctag_la_SOURCES =					\
	nfctag/SmeNfc.cpp				\
	nfctag/NT3H1101.cpp				\
	nfctag/ndef/ndef.cpp				\
	nfctag/ndef/rtd/nfcForum.cpp			\
	nfctag/ndef/rtd/rtdText.cpp			\
	nfctag/ndef/rtd/rtdUri.cpp			\
	nfctag/ndef/ndef.h				\
	nfctag/ndef/rtd/nfcForum.h			\
	nfctag/ndef/rtd/rtdTypes.h			\
	nfctag/ndef/rtd/rtdText.h			\
	nfctag/ndef/rtd/rtdUri.h

pkgconfigdir = $(libdir)/pkgconfig

pkgconfig_DATA = libnfctag.pc

nobase_include_HEADERS =				\
	SmeNfc.h					\
	SmeNfcConfig.h					\
	nfctag/NT3H1101.h				\
	nfctag/NT3H1101_model.h
