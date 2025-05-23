include(CreateCPackCommon)

list(APPEND CPACK_GENERATOR "RPM")
set(CPACK_BINARY_RPM ON)

set(QGC_INSTALLER_SOURCE "${CMAKE_SOURCE_DIR}/deploy/linux")

set(CPACK_RPM_COMPONENT_INSTALL ON)
# CPACK_RPM_PACKAGE_SUMMARY
# CPACK_RPM_PACKAGE_NAME
# set(CPACK_RPM_FILE_NAME RPM-DEFAULT)
# CPACK_RPM_MAIN_COMPONENT
# CPACK_RPM_PACKAGE_EPOCH
# CPACK_RPM_PACKAGE_VERSION
set(CPACK_RPM_PACKAGE_ARCHITECTURE "amd64")
# CPACK_RPM_PACKAGE_RELEASE
# CPACK_RPM_PACKAGE_RELEASE_DIST
# CPACK_RPM_PACKAGE_LICENSE
# CPACK_RPM_PACKAGE_GROUP
# CPACK_RPM_PACKAGE_VENDOR
# CPACK_RPM_PACKAGE_URL
set(CPACK_RPM_PACKAGE_DESCRIPTION ${CPACK_PACKAGE_DESCRIPTION})
set(CPACK_RPM_COMPRESSION_TYPE xz)
# CPACK_RPM_PACKAGE_AUTOREQ
# CPACK_RPM_PACKAGE_AUTOPROV
# CPACK_RPM_PACKAGE_AUTOREQPROV
# CPACK_RPM_PACKAGE_REQUIRES
# CPACK_RPM_PACKAGE_CONFLICTS
# CPACK_RPM_PACKAGE_REQUIRES_PRE
# CPACK_RPM_PACKAGE_REQUIRES_POST
# CPACK_RPM_PACKAGE_REQUIRES_POSTUN
# CPACK_RPM_PACKAGE_REQUIRES_PREUN
# CPACK_RPM_PACKAGE_SUGGESTS
# CPACK_RPM_PACKAGE_PROVIDES
# CPACK_RPM_PACKAGE_OBSOLETES
# CPACK_RPM_PACKAGE_RELOCATABLE
# CPACK_RPM_SPEC_INSTALL_POST
# CPACK_RPM_SPEC_MORE_DEFINE
# CPACK_RPM_PACKAGE_DEBUG
# CPACK_RPM_USER_BINARY_SPECFILE
# CPACK_RPM_GENERATE_USER_BINARY_SPECFILE_TEMPLATE
# CPACK_RPM_PRE_INSTALL_SCRIPT_FILE
# CPACK_RPM_PRE_UNINSTALL_SCRIPT_FILE
# CPACK_RPM_PRE_TRANS_SCRIPT_FILE
# CPACK_RPM_POST_INSTALL_SCRIPT_FILE
# CPACK_RPM_POST_UNINSTALL_SCRIPT_FILE
# CPACK_RPM_POST_TRANS_SCRIPT_FILE
# CPACK_RPM_USER_FILELIST
# CPACK_RPM_CHANGELOG_FILE
# CPACK_RPM_EXCLUDE_FROM_AUTO_FILELIST
# CPACK_RPM_EXCLUDE_FROM_AUTO_FILELIST_ADDITION
# CPACK_RPM_RELOCATION_PATHS
# CPACK_RPM_NO_INSTALL_PREFIX_RELOCATION
# CPACK_RPM_ADDITIONAL_MAN_DIRS
# CPACK_RPM_DEFAULT_USER
# CPACK_RPM_DEFAULT_GROUP
# CPACK_RPM_DEFAULT_FILE_PERMISSIONS
# CPACK_RPM_DEFAULT_DIR_PERMISSIONS
# CPACK_RPM_INSTALL_WITH_EXEC
# CPACK_RPM_DEBUGINFO_PACKAGE
# CPACK_BUILD_SOURCE_DIRS
# CPACK_RPM_BUILD_SOURCE_DIRS_PREFIX
# CPACK_RPM_DEBUGINFO_EXCLUDE_DIRS
# CPACK_RPM_DEBUGINFO_EXCLUDE_DIRS_ADDITION
# CPACK_RPM_DEBUGINFO_SINGLE_PACKAGE
# CPACK_RPM_DEBUGINFO_FILE_NAME
# CPACK_RPM_PACKAGE_SOURCES
# CPACK_RPM_SOURCE_PKG_BUILD_PARAMS
# CPACK_RPM_SOURCE_PKG_PACKAGING_INSTALL_PREFIX
# CPACK_RPM_BUILDREQUIRES
# CPACK_RPM_REQUIRES_EXCLUDE_FROM

include(CPack)
