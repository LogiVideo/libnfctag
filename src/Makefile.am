
VPATH=$(srcdir) $(builddir)

lib_LTLIBRARIES = libnfctag.la

libnfctag_la_CXXFLAGS = 				\
        $(CE_COMMON_CXXFLAGS)                           \
        $(CE_MODULE_CXXFLAGS)                           \
        -I${srcdir}/..                                  \
        -I${abs_srcdir}/.                                   \
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
	nfctag/ndef/rtd/rtdUri.h			\
	SmeNfc.h


nobase_include_HEADERS =				\
	nfctag/NT3H1101.h				\
	nfctag/NT3H1101_model.h
