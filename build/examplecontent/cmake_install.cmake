# Install script for directory: /storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent/examplecontent

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libExampleContent.so.03.00.03"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libExampleContent.so.03.00"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "/storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent/lib:/storage/epp2/phupqr/Pandora.repos/Workshop/PandoraSDK/lib:/storage/epp2/phupqr/Pandora.repos/Workshop/PandoraMonitoring/lib")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent/build/examplecontent/lib/libExampleContent.so.03.00.03"
    "/storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent/build/examplecontent/lib/libExampleContent.so.03.00"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libExampleContent.so.03.00.03"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libExampleContent.so.03.00"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/storage/epp2/phupqr/Pandora.repos/Workshop/PandoraSDK/lib:/storage/epp2/phupqr/Pandora.repos/Workshop/PandoraMonitoring/lib::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"
           NEW_RPATH "/storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent/lib:/storage/epp2/phupqr/Pandora.repos/Workshop/PandoraSDK/lib:/storage/epp2/phupqr/Pandora.repos/Workshop/PandoraMonitoring/lib")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libExampleContent.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libExampleContent.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libExampleContent.so"
         RPATH "/storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent/lib:/storage/epp2/phupqr/Pandora.repos/Workshop/PandoraSDK/lib:/storage/epp2/phupqr/Pandora.repos/Workshop/PandoraMonitoring/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent/build/examplecontent/lib/libExampleContent.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libExampleContent.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libExampleContent.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libExampleContent.so"
         OLD_RPATH "/storage/epp2/phupqr/Pandora.repos/Workshop/PandoraSDK/lib:/storage/epp2/phupqr/Pandora.repos/Workshop/PandoraMonitoring/lib::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"
         NEW_RPATH "/storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent/lib:/storage/epp2/phupqr/Pandora.repos/Workshop/PandoraSDK/lib:/storage/epp2/phupqr/Pandora.repos/Workshop/PandoraMonitoring/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libExampleContent.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PandoraExample" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PandoraExample")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PandoraExample"
         RPATH "/storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent/lib:/storage/epp2/phupqr/Pandora.repos/Workshop/PandoraSDK/lib:/storage/epp2/phupqr/Pandora.repos/Workshop/PandoraMonitoring/lib:/cvmfs/larsoft.opensciencegrid.org/products/root/v6_18_04d/Linux64bit+3.10-2.17-e19-prof/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES "/storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent/build/examplecontent/bin/PandoraExample")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PandoraExample" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PandoraExample")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PandoraExample"
         OLD_RPATH "/storage/epp2/phupqr/Pandora.repos/Workshop/PandoraSDK/lib:/storage/epp2/phupqr/Pandora.repos/Workshop/PandoraMonitoring/lib:/cvmfs/larsoft.opensciencegrid.org/products/root/v6_18_04d/Linux64bit+3.10-2.17-e19-prof/lib:/storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent/build/examplecontent/lib:"
         NEW_RPATH "/storage/epp2/phupqr/Pandora.repos/Workshop/WorkshopContent/lib:/storage/epp2/phupqr/Pandora.repos/Workshop/PandoraSDK/lib:/storage/epp2/phupqr/Pandora.repos/Workshop/PandoraMonitoring/lib:/cvmfs/larsoft.opensciencegrid.org/products/root/v6_18_04d/Linux64bit+3.10-2.17-e19-prof/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PandoraExample")
    endif()
  endif()
endif()

