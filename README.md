## Building and Running

Building the zephyr-wireguard requires a proper Zephyr development environment. Follow the
official [Zephyr Getting Started
Guide](https://docs.zephyrproject.org/latest/getting_started/index.html) to establish one.
You need Zephyr version (4.1.99+), specifically from commit
8e908176c773980a61a44f861941228dc91c3329 ("net: shell: iface: Print VPN public key")
or later.

Note that zephyr-wireguard is a library so normally you would want to use it in your own
application. The zephyr-wireguard repository is a [Zephyr
module](https://docs.zephyrproject.org/latest/develop/modules.html) which allows for reuse of its
components outside of the zephyr-wireguard demo application.

To pull in zephyr-wireguard as a Zephyr module, either add it as a West project in the `west.yaml` file
or pull it in by adding a submanifest (e.g. `zephyr/submanifests/zephyr-wireguard.yaml`) file with the
following content and run `west update wireguard`:

```yaml
manifest:
  projects:
    - name: wireguard
      url: https://github.com/jukkar/zephyr-wireguard.git
      revision: main
      path: modules/lib/zephyr-wireguard # adjust the path as needed
```

You can also copy the file from this directory:

```shell
cp zephyr-wireguard.yaml $ZEPHYR_BASE/submanifests/
```

The zephyr-wireguard demo application can be used to show Wireguard functionality and how to
setup the connection. The demo uses native_sim board, you can use the net-tools project, which
is part of Zephyr development environment, to setup the host side:

```shell
cd $ZEPHYR_BASE/../tools/net-tools
./net-setup.sh -c wireguard-vpn.conf
```

The Zephyr Wireguard demo application can be built and run like this:

```shell
cd $ZEPHYR_BASE/../modules/lib/zephyr-wireguard
west build -p -b native_sim -d ../build samples/net/wireguard/ -- -DCONFIG_NATIVE_UART_AUTOATTACH_DEFAULT_CMD="\"gnome-terminal -- screen %s\""
../build/zephyr/zephyr.exe -attach_uart
```
