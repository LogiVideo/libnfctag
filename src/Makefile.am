
VPATH=$(srcdir) $(builddir)

lib_LTLIBRARIES = libnfctag.la

libnfctag_la_CXXFLAGS = 				\
        $(CE_COMMON_CXXFLAGS)                           \
        $(CE_MODULE_CXXFLAGS)                           \
        -I${srcdir}/..                                  \
        -I${srcdir}/.                                   \
        -Wno-deprecated-declarations                    \
        -Wno-unused-parameter                           \
        -fPIC

libnfctag_la_SOURCES =					\
	nfc/SmeNfc.cpp					\
	nfc/NT3H1101.cpp				\
	nfc/ndef/ndef.cpp				\
	nfc/ndef/rtd/nfcForum.cpp			\
	nfc/ndef/rtd/rtdText.cpp			\
	nfc/ndef/rtd/rtdUri.cpp				\
	SmeNfc.h


nobase_include_HEADERS =				\
	nfc/NT3H1101.h					\
	nfc/ndef/ndef.h					\
	nfc/ndef/rtd/nfcForum.h				\
	nfc/ndef/rtd/rtdText.h				\
	nfc/ndef/rtd/rtdTypes.h				\
	nfc/ndef/rtd/rtdUri.h
