# SPDX-License-Identifier: Apache-2.0

if(CONFIG_WIREGUARD)

zephyr_interface_library_named(wireguard)

zephyr_library()
zephyr_library_include_directories(${ZEPHYR_BASE}/subsys/net/ip)
zephyr_library_include_directories(../../../../include)

zephyr_library_sources(wg.c)

zephyr_library_link_libraries(wireguard)
target_link_libraries(wireguard INTERFACE zephyr_interface)

endif()
