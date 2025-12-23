# SPDX-License-Identifier: Apache-2.0

if(CONFIG_WIREGUARD)

zephyr_interface_library_named(wireguard)

zephyr_library()
zephyr_library_include_directories(${ZEPHYR_BASE}/subsys/net/ip)
zephyr_library_include_directories(${ZEPHYR_BASE}/subsys/net/lib/shell)
zephyr_library_include_directories(../../../../include)

zephyr_library_sources(wg.c)
zephyr_library_sources_ifdef(CONFIG_NET_SHELL wg_shell.c)

zephyr_library_sources_ifdef(CONFIG_WIREGUARD_USE_PSA wg_psa.c)

zephyr_library_sources(
  crypto/crypto.c
)

# Reference implementations needed when not using PSA or for algorithms
# not available in PSA (Blake and XChaCha20-Poly1305)
zephyr_library_sources(
  crypto/refc/chacha20.c
  crypto/refc/poly1305-donna.c
  crypto/refc/blake2s.c
  crypto/refc/chacha20poly1305.c
)

zephyr_library_sources_ifndef(CONFIG_WIREGUARD_USE_PSA
  crypto/refc/x25519.c
)

zephyr_library_sources_ifdef(CONFIG_BOARD_NATIVE_SIM ns_rtc.c)

zephyr_library_link_libraries(wireguard)
target_link_libraries(wireguard INTERFACE zephyr_interface)

endif()
