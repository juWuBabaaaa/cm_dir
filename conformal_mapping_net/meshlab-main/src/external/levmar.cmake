# Copyright 2019, 2020, Collabora, Ltd.
# Copyright 2019, 2020, Visual Computing Lab, ISTI - Italian National Research Council
# SPDX-License-Identifier: BSL-1.0

option(MESHLAB_ALLOW_DOWNLOAD_SOURCE_LEVMAR "Allow download and use of levmar source" ON)

if(MESHLAB_ALLOW_DOWNLOAD_SOURCE_LEVMAR)
	set(LEVMAR_DIR "${MESHLAB_EXTERNAL_DOWNLOAD_DIR}/levmar-2.6")
	set(LEVMAR_CHECK "${LEVMAR_DIR}/lm.h")

	if (NOT EXISTS ${LEVMAR_CHECK})
		set(LEVMAR_LINK
			http://users.ics.forth.gr/~lourakis/levmar/levmar-2.6.tgz
			https://www.meshlab.net/data/libs/levmar-2.6.tgz)
		set(LEVMAR_MD5 16bc34efa1617219f241eef06427f13f)
		download_and_unzip(
			NAME "Levmar"
			LINK ${LEVMAR_LINK}
			MD5 ${LEVMAR_MD5}
			DIR ${MESHLAB_EXTERNAL_DOWNLOAD_DIR})
		if (NOT download_and_unzip_SUCCESS)
			message(STATUS "- Levmar - download failed.")
		endif()
	endif()

	if (EXISTS ${LEVMAR_CHECK})
		message(STATUS "- levmar - using downloaded source")

		set(HAVE_LAPACK 0 CACHE BOOL "Do we have LAPACK/BLAS?")
		set(BUILD_DEMO OFF)
		set(MESSAGE_QUIET ON)
		add_subdirectory(${LEVMAR_DIR})
		unset(MESSAGE_QUIET)
		unset(HAVE_LAPACK)
		unset(BUILD_DEMO)

		add_library(external-levmar INTERFACE)
		target_link_libraries(external-levmar INTERFACE levmar)
		target_include_directories(external-levmar INTERFACE ${LEVMAR_DIR})
	endif()
endif()
