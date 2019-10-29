################################################################################
# Created on 2017-04-17 by Nick Stoughton <nstoughton@logitech.com>
#
# Copyright (c) 2017 Logitech, Inc.  All Rights Reserved
# This program is a trade secret of LOGITECH, and it is not to be reproduced,
# published, disclosed to others, copied, adapted, distributed or displayed
# without the prior authorization of LOGITECH.
#
# Licensee agrees to attach or embed this notice on all copies of the program,
# including partial copies or modified versions thereof.
################################################################################

nfc_tool=nfc-tool

bin_PROGRAMS =					\
		    $(nfc_tool)

nfc_tool_CXXFLAGS = ${LIB_NFCTAG_CXXFLAGS}

nfc_tool_LDADD = ${LIB_NFCTAG_LIBS}

nfc_tool_SOURCES = nfc-tool.cpp
